#include<cstring>
#include<stdlib.h>
#include<stdio.h>

#define rep(i,n) for(int i=0;i<n;++i)
#define fab(i,a,b) for(int i=a;i<=b;++i)
#define fba(i,b,a) for(int i=b;i>=a;--i)
#define sf scanf
#define pf printf
#define LL long long
const int N=20010;
using namespace std;
struct Node{
    int r,v,s;//r priority; v value; s size of subtree
    Node* ch[2];// left&right subtree
    Node(int v):v(v){
        ch[0]=ch[1]=NULL;
        r=rand();
        s=1;
    }
    bool operator<(const Node& rhs)const{
        return r< rhs.r;
    }
    int cmp(int x)const{
        if(x==v)return -1;
        else return x<v?0:1;
    }
    void maintain(){
        s=1;
        if(ch[0]!=NULL)s+=ch[0]->s;
        if(ch[1]!=NULL)s+=ch[1]->s;
    }
};
//调用的时候 Node * root=NULL;
/*bool find(Node* o,int x){
    while(o!=NULL){
       int d=o->cmp(x); 
       if(d==-1)return true;
       o=o->ch[d];
    }
    return false;
}*/
void rotate(Node* &o, int d){
    Node* k = o->ch[d^1];
    o->ch[d^1] = k->ch[d];
    k->ch[d] = o;
    o->maintain();
    k->maintain();
    o = k;
}
//若不予许出现相同节点，那么调用前先调用find，判断是否存在相同节点，remove类似
void insert(Node* &o,int x){
    if(o==NULL)o=new Node(x);
    else{
        int d=( x < o->v ? 0 : 1 );// 这里相同节点的处理是放在右边
        insert(o->ch[d],x);
        if(o->ch[d] > o)rotate(o,d^1);
    }
    o->maintain();
}
void remove(Node* &o,int x){
    int d=o->cmp(x);
    if(d==-1){
       Node* u=o;
       if(o->ch[0]!=NULL && o->ch[1]!=NULL){
          int d2=(o->ch[0] > o->ch[1] ? 1:0 );
          rotate(o,d2);
          remove(o->ch[d2],x);
       }else{
           if(o->ch[0]==NULL)o=o->ch[1];
           else o=o->ch[0];
           delete u;
       }
    }else{
        remove(o->ch[d],x);
    }
    if(o!=NULL)o->maintain();
}
/*void print(Node* o){
    if(o==NULL)return;
    else{
        print(o->ch[0]);
        pf("%d ",o->v);
        print(o->ch[1]);
    }
}*/
const int M=60010;
const int maxc=500010;
struct Cmd{
    char type;
    int x,p;
    Cmd(){};
    Cmd(char type,int x,int p):type(type),x(x),p(p){}
}cmd[maxc];
int n,m;
int W[N],U[M],V[M];
bool removed[M];
LL sum=0;
int cnt=0;
int c;
int fa[N];
Node* root[N];
int cas=1;
int findfa(int x){
    if(x!=fa[x])return fa[x]=findfa(fa[x]);
    return fa[x];
}

void init(){
    fab(i,1,n)sf("%d",&W[i]);
    fab(i,1,m)sf("%d%d",&U[i],&V[i]);
    memset(removed,0,sizeof removed);
    c=0;
    while(true){
        char type[2];
        int x,p=0,v=0;
        sf("%s",type);
        if(type[0]=='E')break;
        sf("%d",&x);
        if(type[0]=='D')removed[x]=true;
        if(type[0]=='Q')sf("%d",&p);
        if(type[0]=='C'){
            sf("%d",&v);
            p=W[x];
            W[x]=v;
        }
        cmd[c++]=Cmd(type[0],x,p);
    }
}

void removetree(Node* &o){
   // rep(i,2)if(o->ch[i]!=NULL)removetree(o->ch[i]);
    if(o->ch[0]!=NULL)removetree(o->ch[0]);
    if(o->ch[1]!=NULL)removetree(o->ch[1]);
    delete o;
    o=NULL;
}
void mergetree(Node* &st,Node* &ed){
    //rep(i,2)if(st->ch[i]!=NULL)mergetree(st->ch[i],ed);
    if(st->ch[0]!=NULL)mergetree(st->ch[0],ed);
    if(st->ch[1]!=NULL)mergetree(st->ch[1],ed);
    insert(ed,st->v);
    delete st;
    st=NULL;
}
void add_edge(int x){
    int u=findfa(U[x]),v=findfa(V[x]);
    if(u!=v){
        if(root[u]->s <= root[u]->s ){
            fa[u]=v;
            mergetree(root[u],root[v]);
        }
        else {
            fa[v]=u;
            mergetree(root[v],root[u]);
        }
    }
}
void change_weight(int x,int v){
    int u=findfa(x);
    remove(root[u],W[x]);
    insert(root[u],v);
    W[x]=v;
}
int Kth(Node* o,int k){
    if(o==NULL||k<=0||k>o->s)return 0;
    int s=(o->ch[1]==NULL ? 0:o->ch[1]->s);
    if(k==s+1)return o->v;
    else if(k<=s)return Kth(o->ch[1],k);
    else return Kth(o->ch[0],k-s-1);
}
void qurry(int x,int k){
    cnt++;
    sum+=Kth(root[findfa(x)],k);
}
void solve(){
    fab(i,1,n){ 
       fa[i]=i;
       if(root[i]!=NULL)removetree(root[i]);
       root[i]=new Node(W[i]);
    }
    fab(i,1,m)if(!removed[i])add_edge(i);
    cnt=0;
    sum=0;
    for(int i=c-1;i>=0;i--){
        if(cmd[i].type=='D')add_edge(cmd[i].x);
        if(cmd[i].type=='Q')qurry(cmd[i].x,cmd[i].p);
        if(cmd[i].type=='C')change_weight(cmd[i].x,cmd[i].p);
    }
    //if(cnt==0)cnt=1;
    pf("Case %d: %.6lf\n",cas++,sum/(double)cnt);
}
int main(){
    while(sf("%d%d",&n,&m)&&(n||m)){
        init();
        solve();
    }
    return 0;
}


