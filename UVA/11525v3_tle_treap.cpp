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
const int N=50015;
using namespace std;
typedef pair<int,int>PII;
int K;
vector<int>ans;
struct Node{
    Node* ch[2];
    int r,v,s;
    Node(int v):v(v){
        ch[0]=ch[1]=NULL;
        r=rand();
        s=1;
    }
    bool operator<(const Node& rhs)const{
        return r<rhs.r;
    }
    int cmp(int x)const{
        if(x==v)return -1;
        return x<v?0:1;
    }
    void maintain(){
        s=1;
        if(ch[0]!=NULL)s+=ch[0]->s;
        if(ch[1]!=NULL)s+=ch[1]->s;
    }
};
void rotate(Node* &o,int d){
    Node* k=o->ch[d^1];o->ch[d^1]=k->ch[d];k->ch[d]=o;
    o->maintain();k->maintain();o=k;
}
void insert(Node* &o,int x){
    if(o==NULL)o=new Node(x);
    else{
        int d=(x<o->v?0:1);
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
    }else remove(o->ch[d],x);
    if(o!=NULL)o->maintain();
}
int Kth(Node* o,int k){
    if(o==NULL||k<=0||k>o->s)return 0;
    int s=(o->ch[0]==NULL?0:o->ch[0]->s);
    if(k==s+1)return o->v;
    else if(k<=s)return Kth(o->ch[0],k);
    else return Kth(o->ch[1],k-s-1);
}
void removetree(Node* &o){
    if(o==NULL)return;
    if(o->ch[0]!=NULL)removetree(o->ch[0]);
    if(o->ch[1]!=NULL)removetree(o->ch[1]);
    delete o;
    o=NULL;
}
Node* root=NULL;
void print(Node* o){
    if(o==NULL)return;
    print(o->ch[0]);
    pf("%d ",o->v);
    print(o->ch[1]);
}
void init(){
//    removetree(root);
    root=NULL;
    ans.clear();
    sf("%d",&K);
    fab(i,1,K)insert(root,i);
   // puts("print");print(root);
}
void solve(){
    int x;
    rep(i,K){
        sf("%d",&x);
        int id=Kth(root,x+1);
       // pf("idid %d\n",id);
        ans.PB(id);
        remove(root,id);
    }
    rep(i,ans.size()){
        if(i==ans.size()-1)pf("%d\n",ans[i]);
        else pf("%d ",ans[i]);
    }
}
int main(){
    int T;sf("%d",&T);
    while(T--){
        init();
        solve();
    }
    return 0;
}


