#include<iostream>
#include<cstring>
#include<stdio.h>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<iomanip>
#include<cmath>
#include<list>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)
#define fab(i,a,b) for(int i=(a);i<=(b);i++)
#define fba(i,b,a) for(int i=(b);i>=(a);i--)
#define cls(x) memset(x,0,sizeof(x))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define LL long long 
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define sf scanf
#define pf printf 
const int N=2005;
using namespace std;
int n,tot;
int x[N],y[N],head[N];
struct Node{
    int x,y,id;
    Node(int x=0,int y=0,int id=0):x(x),y(y),id(id){
    }
}node[N];
struct Edge{
    int v,next,id;
    Edge(int v=0,int next=0,int id=0):v(v),next(next),id(id){}
}E[N*4];
bool vis[N];
void init(){
    tot=0;
    memset(vis,0,sizeof vis);
    memset(head,-1,sizeof head);
    rep(i,n){
     sf("%d%d",&x[i],&y[i]);
     node[i].x=x[i];
     node[i].y=y[i];
     node[i].id=i;
    }
}
bool cmp1(Node x,Node y){
    return x.x<y.x || x.x==y.x&&x.y<y.y;
}
bool cmp2(Node x,Node y){
    return x.y<y.y || x.y==y.y&&x.x<y.x;
}
void addedge(int u,int v){
   E[tot].v=v;
   E[tot].next=head[u];
   head[u]=tot++;

   E[tot].v=u;
   E[tot].next=head[v];
   head[v]=tot++;
}
void dfs1(int u){
    vis[u]=1;
    for(int p=head[u];~p;p=E[p].next){
        if(!vis[E[p].v])dfs1(E[p].v);
    }
}
void dfs2(int fa,int u){
   vis[u]=1;
   for(int p=head[u];~p;p=E[p].next){
       if(!vis[E[p].v])dfs2(u,E[p].v);
   }
   if(fa!=-1){
       pf("(%d, %d) ",x[u],y[u]);
       if(x[fa]<x[u])puts("LEFT");
       if(x[fa]>x[u])puts("RIGHT");
       if(y[fa]<y[u])puts("DOWN");
       if(y[fa]>y[u])puts("UP");
   }
}
void solve(){
   sort(node,node+n,cmp1);
   rep(i,n-1){
       if(node[i].x==node[i+1].x)addedge(node[i].id,node[i+1].id);
   }
   sort(node,node+n,cmp2);
   rep(i,n-1){
       if(node[i].y==node[i+1].y)addedge(node[i].id,node[i+1].id);
   }
   int num=0;
   rep(i,n)if(!vis[i])num++,dfs1(i);
   pf("%d\n",num);
   memset(vis,0,sizeof vis);
   rep(i,n){
     if(!vis[i])dfs2(-1,i);
   }
}
int main(){
    while(~sf("%d",&n)){
        init();
        solve();
    }
    return 0;
}

