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
const int N=500005;
using namespace std;
typedef pair<int,int>PII;
struct Node{
    Node* ch[2];
    int flip,v,s,add;
    Node(){
        flip=v=s=add=0;
    }
    int cmp(int k)const{
        int d=k-ch[0]->s;
        if(d==1)return -1;
        return d<0?0:1;
    }
    void maintain(){
        s=ch[0]->s+ch[1]->s+1;
    }
    void pushdown(){
        if(flip){
            flip=0;
            swap(ch[0],ch[1]);
            ch[0]->flip^=1;
            ch[1]->flip^=1;
        }
        if(add){
            ch[0]->add+=add;
            ch[1]->add+=add;
            add=0;
        }
    }
};
Node *null = new Node();
void rotate(Node* &o,int d){
    Node* k=o->ch[d^1];
    o->ch[d^1]=k->ch[d];
    k->ch[d]=o;
    o->maintain();k->maintain();o=k;
}
void splay(Node* &o,int k){
    o->pushdown();
    int d=o->cmp(k);
    if(d==1)k-=o->ch[0]->s+1;
    if(d!=-1){
        Node* p = o->ch[d];
        p->pushdown();
        int d2=p->cmp(k);
        int k2=(d2==0?k:k-p->ch[0]->s-1);
        if(d2!=-1){
            splay(p->ch[d2],k2);
            if(d==d2)rotate(o,d^1);
            else rotate(o->ch[d],d);
        }
        rotate(o,d^1);
    }
}
Node* merge(Node* left,Node* right){
    splay(left,left->s);
    left->ch[1]=right;
    left->maintain();
    return left;
}
void split(Node* o,int k,Node* &left,Node* &right){
    splay(o,k);
    left=o;
    right=o->ch[1];
    o->ch[1]=null;
    left->maintain();
}
int a[N];
struct Splay{
    int n;
    Node seq[N];
    Node *root;
    Node* build(int sz){
        if(!sz)return null;
        Node* L=build(sz/2);
        Node* o=&seq[++n];
        o->v=a[n];
        o->ch[0]=L;
        o->ch[1]=build(sz-sz/2-1);
        o->flip=o->s=o->add=0;
        o->maintain();
        return o;
    }
    void init(int sz){
        n=0;
        null->s=0;
        root=build(sz);
    }
}T;
vector<int>ans;
void print(Node* root){
    if(root!=null){
       root->pushdown();
       print(root->ch[0]);
      // pf("%d ",root->v);
       ans.PB(root->v);
       print(root->ch[1]);
    }
}
void bug(){
    ans.clear();
    print(T.root);
   // pf(" T size = %d\n",T.root->s);
    //rep(i,ans.size())pf("%d ",ans[i]);puts("");
}
int n,M,k2,k1;
void init(){
    memset(a,0,sizeof a);
    fab(i,1,n)sf("%d",&a[i]);
    T.init(n);
}
void Add(int x){
    if(k2==T.root->s){
        T.root->add+=x;
    }else{
        
    }
}
void Query(){
    //puts("B");
    bug();
    splay(T.root,4);
    T.root->pushdown();
    bug();
}
void solve(){
    //bug();
    char op[100];
    rep(cmd,M){
        sf("%s",op);
        if(!strcmp(op,"add")){
            int x;sf("%d",&x);
            Add(x);
        }else if(!strcmp(op,"query")){
            Query();
        }
    }
}
void work(){
    sf("%d%d",&n,&M);
    T.init(n+1);
    while(M--){
        int a,b;
        sf("%d%d",&a,&b);
        Node* left,* mid,* right,* o;
        split(T.root,a,left,o);
        split(o,b-a+1,mid,right);
        mid->flip^=1;
        T.root=merge(merge(left,right),mid);
    }
    bug();
    for(int i=1;i<ans.size();i++)pf("%d\n",ans[i]-1);
}
int main(){
    /*int cas=1;
    while(~sf("%d%d%d%d",&n,&M,&k1,&k2)&&(n+M+k2+k1)){
        pf("Case #%d:\n",cas++);
        init();
        solve();
    }*/
    work();
    return 0;
}


