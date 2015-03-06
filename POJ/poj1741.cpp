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
#define cls0(x) memset(x,0,sizeof(x))
#define cls1(x) memset(x,-1,sizeof(x))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1
#define LL long long
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define sf scanf
#define pf printf
#define left le_
#define right ri_
const int N=10005;
using namespace std;
struct Edge{
    int v,w;
    Edge(int v=0,int w=0):v(v),w(w){

    }
};
vector<Edge>G[N];
bool vis[N];
int size[N],dep[N];
int left,right,minx,k;
int n,u,v,w;
void init(){
    rep(i,N)G[i].clear();
    cls0(vis);
    cls0(dep);
    cls0(size);
}
void input(){
    rep(i,n-1){
        sf("%d %d %d",&u,&v,&w);
        G[u].PB(Edge(v,w));
        G[v].PB(Edge(u,w));
    }
}
int getsize(int u,int fa){
    size[u]=1;
    rep(i,G[u].size()){
        int v=G[u][i].v;
        if(v==fa||vis[v])continue;
        size[u]+=getsize(v,u);
    }
    return size[u];
}
void getroot(int u,int fa,int nodesize,int& root){
   int maxx=nodesize-size[u];
   rep(i,G[u].size()){
       int v=G[u][i].v;
       if(v==fa||vis[v])continue;
       getroot(v,u,nodesize,root);
       maxx=max(maxx,size[v]);
   }
   if(maxx<minx){
       minx=maxx;
       root=u;
   }
}
void getdep(int u,int fa,int w){
    dep[right++]=w;
    rep(i,G[u].size()){
        int v=G[u][i].v;
        if(v==fa||vis[v])continue;
        getdep(v,u,w+G[u][i].w);
    }
}
int getans(int l,int r){
    sort(dep+l,dep+r);
    int ans=0;
    int a=l-1;
    for(int i=r-1;i>=l;i--){
        while(a+1<i&&dep[a+1]+dep[i]<=k)a++;
        if(a>=i)ans+=(i-l);
        else ans+=(a-l+1);
    }
    return ans;
    // 
    int ret=0;
    int e=r-1;
    for(int i=l;i<r;i++){
        if(dep[i]>k)break;
        while(e>=l&&dep[e]+dep[i]>k)e--;
        ret+=(e-l+1);
        if(e>i)ret--;
    }
    return ret>>1;
}
int solve(int u){
    int nodesize=getsize(u,-1);
    int ret=0;
    minx=INF;
    int root;
    getroot(u,-1,nodesize,root);
    vis[root]=1;
    rep(i,G[root].size()){
        int v=G[root][i].v;
        if(vis[v])continue;
        ret+=solve(v);
    }
    left=right=0;
    rep(i,G[root].size()){
        int v=G[root][i].v;
        if(vis[v])continue;
        getdep(v,root,G[root][i].w);
        ret-=getans(left,right);
        left=right;
    }
    ret+=getans(0,right);
    rep(i,right){
        if(dep[i]<=k)ret++;
        else break;
    }
    vis[root]=false;
    return ret;
}
int main(){
    while(~sf("%d %d",&n,&k)){
        if(n==0&&k==0)break;
        init();
        input();
        pf("%d\n",solve(1));
    }
    return 0;
}
