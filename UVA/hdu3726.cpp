#include<iostream>
#include<cstring>
#include<set>
#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<algorithm>
#include<stdio.h>
#include<iomanip>

#define rep(i,n) for(int i=0;i<n;++i)
#define fab(i,a,b) for(int i=a;i<=b;++i)
#define fba(i,b,a) for(int i=b;i>=a;--i)
#define PB push_back
#define INF 0x3f3f3f3f
#define MP make_pair
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define sf scanf
#define pf printf
#define LL long long
const int N=1005;
using namespace std;
typedef pair<int,int>PII;
struct Node{
    Node* ch[2];//left&right subtree
    int r,v,s;//r priority; v value; s size of the subtree
    Node(int v):v(v){ch[0]=ch[1]=NULL;r=rand();s=1;}
    bool operator<(const Node& rhs)const{
        return r<rhs.r;
    }
    int cmp(int x)const{
       if(x==v)return -1;
       return x<v?0:1;
    }
    void maintain(){
        s=1;
        if(ch[0]!=NULL)s+= ch[0]->s;
        if(ch[1]!=NULL)s+= ch[1]->s;
    }
};
bool find(Node* o,int x){
    while(o!=NULL){
        int d=o->cmp(x);
        if(d==-1)return true;
        o=o->ch[d];
    }
    return false;
}
void rotate(Node* &o,int d){
    Node* k=o->ch[d^1];o->ch[d^1]=k->ch[d];k->ch[d]=o;
    o->maintain();k->maintain();o=k;
}
//箬不允许出现相同节点，那么调用之前先调用find判断是否可插入，remove类似
void insert(Node* &o,int x){
    if(o==NULL)o=new Node(x);
    else{
        int d= (x<o->v?0:1);//这里相同节点是放到右仔树,也因此不能用cmp
        insert(o->ch[d],x);
        if(o->ch[d]>o)rotate(o,d^1);
    }
    o->maintain();
}
void remove(Node* &o,int x){
    int d=o->cmp(x);
    if(d==-1){
       Node* u=o;
       if(o->ch[0]!=NULL && o->ch[1]!=NULL){
           int d2= o->ch[0] > o->ch[1] ? 1 : 0;
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
const int maxn=20010;
const int maxc = 500010;
int n,m,w[maxn],from[maxn*3],to[maxn*3],removed[maxn*3];
int f[maxn];
Node* root[maxn];
struct Command{
    char type;
    int x,p;
    Command(){}
    Command(char type,int x,int p):type(type),x(x),p(p){}
}commands[maxc];
int find(int x){
    if(x!=f[x])return f[x]=find(f[x]);
    return f[x];
}
int Kth(Node* o,int k){
    if(o==NULL||k<=0||k>o->s)return 0;//不存在第k大
    int s=(o->ch[1]==NULL?0:o->ch[1]->s);
    if(k==s+1)return o->v;
    else if(k<=s)return Kth(o->ch[1],k);
    else return Kth(o->ch[0],k-s-1);
}
void mergeto(Node* &src,Node* &dest){//启发式合合并两颗子树，把小的合到大的里面，复杂度n(logn)^2
    if(src->ch[0]!=NULL)mergeto(src->ch[0],dest);
    if(src->ch[1]!=NULL)mergeto(src->ch[1],dest);
    insert(dest,src->v);
    delete src;
    src=NULL;
}
void add_edge(int x){
    int u=find(from[x]),v=find(to[x]);
    if(u!=v){
        if(root[u]->s > root[v]->s ){
           f[v]=u;
           mergeto(root[v],root[u]);
        }else{
            f[u]=v;
            mergeto(root[u],root[v]);
        }
    }
}
void removetree(Node* &x){//删除整颗树，释放空间
    if(x->ch[0]!=NULL)removetree(x->ch[0]);
    if(x->ch[1]!=NULL)removetree(x->ch[1]);
    delete x;
    x=NULL;
}
int qurry_cnt;
LL qurry_tol;
void qurry(int x,int k){
   qurry_cnt++;
   qurry_tol+=Kth(root[find(x)],k);
}
void change_weight(int x,int v){
    int u=find(x);
    remove(root[u],w[x]);
    insert(root[u],v);
    w[x]=v;
}
int main(){
    int cas=0;
    while(sf("%d %d",&n,&m)&&(n||m)){
        fab(i,1,n)sf("%d",&w[i]);
        fab(i,1,m)sf("%d%d",&from[i],&to[i]);
        memset(removed,0,sizeof removed);
        int c=0;
        while(1){
            char type[2];
            int x,p=0,v=0;
            sf("%s",type);
            if(type[0]=='E')break;
            sf("%d",&x);
            if(type[0]=='D')removed[x]=1;
            if(type[0]=='Q')sf("%d",&p);
            if(type[0]=='C'){
                sf("%d",&v);
                p=w[x];
                w[x]=v;
            }
            commands[c++]=Command(type[0],x,p);
        }
        fab(i,1,n){
            f[i]=i;
            if(root[i]!=NULL)removetree(root[i]);
            root[i]=new Node(w[i]);
        }
        fab(i,1,m){
            if(!removed[i])add_edge(i);
        }
        qurry_cnt=qurry_tol=0;
        fba(i,c-1,0){
           if(commands[i].type=='D')add_edge(commands[i].x);
           if(commands[i].type=='Q')qurry(commands[i].x,commands[i].p);
           if(commands[i].type=='C')change_weight(commands[i].x,commands[i].p);
        }
        pf("Case %d: %.6lf\n",++cas,qurry_tol/(double)qurry_cnt);
    }
    return 0;
}
