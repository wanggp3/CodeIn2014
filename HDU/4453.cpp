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
const int N=101015;
using namespace std;
typedef pair<int,int>PII;
struct Node{
    Node* ch[2];
    int s,v,flip;
    int add;
    Node(){
        ch[0]=ch[1]=NULL;
        v=flip=add=0;
        s=1;
    }
    Node(int v){
        this->v=v;
        s=1;
        flip=add=0;
        ch[0]=ch[1]=NULL;
    }
    void maintain(){
        s=1;
        rep(i,2)if(ch[i]!=NULL)s+=ch[i]->s;
    }
    int cmp(int k){
        int d=(ch[0]==NULL?0:ch[0]->s);
        if(d+1==k)return -1;
        else return k<=d?0:1;
    }
    void pushdown(){
        if(flip){
            flip=0;
            swap(ch[0],ch[1]);
            rep(i,2)if(ch[i]!=NULL)ch[i]->flip^=1;
        }
        if(add){
            rep(i,2)if(ch[i]!=NULL)ch[i]->add+=add;
            v+=add;
            add=0;
        }
    }
};
void rotate(Node* &o,int d){
    Node* k=o->ch[d^1]; o->ch[d^1]=k->ch[d]; k->ch[d]=0;
    o->maintain();k->maintain();o=k;
}
void splay(Node* &o,int k){
    o->pushdown();
    int d=o->cmp(k);
    int l=(o->ch[0]==NULL?0:o->ch[0]->s);
    if(d!=-1){
        if(d==0)splay(o->ch[0],k);
        else splay(o->ch[1],k-l-1);
        rotate(o,d^1);
    }
}
int a[N];
Node* build(int l,int r){
    if(l==r)return new Node(a[l]);
    else{
        int m=(l+r)>>1;
        Node* t=new Node(a[m]);
        if(l<m)t->ch[0]=build(l,m-1);
        t->ch[1]=build(m+1,r);
        t->maintain();
        return t;
    }
}
void removetree(Node* &o){
    rep(i,2)if(o->ch[i]!=NULL)removetree(o->ch[i]);
    delete o;
}
Node* merge(Node* left,Node* right){
    if(left==NULL)return right;
    else if(right==NULL)return left;
    splay(left,left->s);
    left->ch[1]=right;
    left->maintain();
    return left;
}
void split(Node* o,int k,Node* &left,Node* &right){
    if(k==0){
        left=NULL;
        right=o;
        return;
    }
    splay(o,k);
    left=o;
    right=o->ch[1];
    o->ch[1]=NULL;
    left->maintain();
}
Node *root;
int n,M,k1,k2;
void init(){
    if(root!=NULL){
        removetree(root);
    }
    fab(i,1,n){
        sf("%d",&a[i]);
    }
    root=build(1,n);
}
void print(Node *o){
    if(o->ch[0]!=NULL)print(o->ch[0]);
    pf("%d ",o->v);
    if(o->ch[1]!=NULL)print(o->ch[1]);
}
void bug(){
    puts("print tree");
    if(root!=NULL)print(root);
}
void ADD(int x){
   if(root->s <= k2){
        root->add+=x;
   }else{
        splay(root,k2+1);
        root->ch[0]->add+=x;
        splay(root,1);
   }
}
void REVERSE(){
   if(root->s <= k1){
       root->flip^=1;
   }else{
       splay(root,k1+1);
       root->pushdown();
       root->ch[0]->flip^=1;
       splay(root,1);
   }
}
void INSERT(int x){
    if(root->s==1){
        root->pushdown();
        root->ch[1]=new Node(x);
        root->maintain();
    }else{
        splay(root,1);
        splay(root->ch[1],1);
        root->ch[1]->pushdown();
        root->ch[1]->ch[0]=new Node(x);
        root->ch[1]->maintain();
        root->maintain();
    }
}
void DELETE(){
    splay(root,2);
    root->ch[0]=NULL;
    root->maintain();
}
void MOVE(int x){
    if(x==1){
        int sz=root->s;
        splay(root,sz-1);
        root->pushdown();
        Node *tmp=root->ch[1];
        root->ch[1]=NULL;
        root->maintain();
        splay(root,1);
        root->pushdown();
        root->ch[0]=tmp;
        root->maintain();
    }else if(x==2){
        //pf(" root->ch[0/1]->s = %d  %d\n",root->ch[0]->s,root->ch[1]->s);
        int sz=root->s;
        root->pushdown();
        splay(root,2);
        bug();
        //pf("after splay 2 root->ch[0/1]->s = %d  %d\n",root->ch[0]->s,root->ch[1]->s);
        Node* tmp=root->ch[0];
        pf(" ok 3\n");
        root->ch[0]=NULL;
        root->maintain();
        pf("root size = %d  sz = %d\n",root->s,sz);
        splay(root,sz-1);
        puts("ok4");
        root->pushdown();
        puts("ok5");
        root->ch[1]=tmp;
        root->maintain();
    }
}
void QUERY(){
    splay(root,1);
    root->pushdown();
    pf("%d\n",root->v);
}
void solve(){
    bug();
    char s[100];
    rep(cmd,M){
        sf("%s",s);
        if(!strcmp(s,"add")){
            int x;
            sf("%d",&x);
            ADD(x);
        }else if(!strcmp(s,"reverse")){
            REVERSE();
        }else if(!strcmp(s,"insert")){
            int x;sf("%d",&x);
            INSERT(x);
        }else if(!strcmp(s,"delete")){
            DELETE();
        }else if(!strcmp(s,"move")){
            int x;sf("%d",&x);
            MOVE(x);
        }else if(!strcmp(s,"query")){
            QUERY();
        }
    }
}
int main(){
    int cas=1;
    while(~sf("%d%d%d%d",&n,&M,&k1,&k2)&&(n+M+k1+k2)){
        pf("Case #%d:\n",cas++);
        init();
        solve();
    }
    return 0;
}


