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
const int N=160;
using namespace std;
typedef pair<int,int>PII;
char g[N][N];
struct Node{
    int v,l,r,col;
    Node(int v=0,int l=0,int r=0,int col=0):v(v),l(l),r(r),col(col){}
}BST[N];
int n,sz,col,maxdep;
void insert(int x){
    int root=0;
    while(1){
       if(x<BST[root].v){
           if(~BST[root].l)root=BST[root].l;
           else{
               BST[root].l=++sz;
               BST[sz].v=x;
               return;
           }
       }else if(x>BST[root].v){
           if(~BST[root].r)root=BST[root].r;
           else{
               BST[root].r=++sz;
               BST[sz].v=x;
               return;
           }
       }else return ;
    }
}
void build(int root,int dep){
    maxdep=max(maxdep,dep);
    if(~BST[root].l)build(BST[root].l,dep+2);
    BST[root].col=col++;
    if(~BST[root].r)build(BST[root].r,dep+2);
    if(~BST[root].l){
        g[dep][BST[BST[root].l].col]='+';
        g[dep+1][BST[BST[root].l].col]='|';
        fab(i,BST[BST[root].l].col+1,BST[root].col-1)g[dep][i]='-';
    }
    g[dep][BST[root].col]='o';
    if(~BST[root].r){
        g[dep][BST[BST[root].r].col]='+';
        g[dep+1][BST[BST[root].r].col]='|';
        fab(i,BST[root].col+1,BST[BST[root].r].col-1)g[dep][i]='-';
    }
}
void solve(){
   memset(g,' ',sizeof g);
   build(0,0);
   rep(i,maxdep+1){
       for(int j=N-1;g[i][j]==' ';j--)g[i][j]='\0';
       pf("%s\n",g[i]);
   }
}
void init(){
    sf("%d",&n);
    col=maxdep=sz=0;
    memset(BST,-1,sizeof BST);
    sf("%d",&BST[0].v);
    int x;
    fab(i,1,n-1){
        sf("%d",&x);
        insert(x);
    }
}
int main(){
    int T;sf("%d",&T);
    rep(cas,T){
        init();
        pf("Case #%d:\n",cas+1);
        solve();
    }
    return 0;
}


