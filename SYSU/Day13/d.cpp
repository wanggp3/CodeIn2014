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
const int N=1005;
using namespace std;
int n,m,l,r;
int dp[N];
struct Edge{
  int v,w;
  Edge(int v=0,int w=0):v(v),w(w){

  }
};
vector<Edge>G[N];
void init(){
    rep(i,N)G[i].clear(),dp[i]=-1;
    l=INF;
    r=-INF;
}
int dfs(int u,int fa,int mid){
    //if(dp[u]!=-1)return dp[u];
    bool flag=1;
    dp[u]=INF;
    rep(i,G[u].size()){
        int v=G[u][i].v,w=G[u][i].w;
        if(v==fa)continue;
        if(flag){
            flag=0;
            dp[u]=0;
        }
        dfs(v,u,mid);
        if(w<=mid)dp[u]+=min(dp[v],w);
        else dp[u]+=dp[v];
        dp[u]=min(INF,dp[u]);
    }
    return dp[u];
}
void solve(){
    int ans=-1;
    //pf("bug11\n");
    while(l<=r){
        int mid=(l+r)>>1;
       // pf("%d %d %d\n",l,r,mid);
        if(dfs(1,-1,mid)<=m){
           // pf("ok %d\n",mid);
            ans=mid;
            r=mid-1;
        }else l=mid+1;
       // pf("bug\n");
    }
    pf("%d\n",ans);
}
int main(){
    while(sf("%d %d",&n,&m)!=EOF){
        if(n==0&&m==0)break;
        init();
        int u,v,w;
        rep(i,n-1){
         sf("%d %d %d",&u,&v,&w);
         G[u].PB(Edge(v,w));
         G[v].PB(Edge(u,w));
         l=min(l,w);
         r=max(r,w);
        }
        solve();
    }
    return 0;
}


