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
const int N=155;
using namespace std;
int n,p;
int dp[N][N];
int num[N];
int ans;
vector<int>G[N];
void init(){
    rep(i,N)G[i].clear();
    memset(dp,INF,sizeof dp);
    int u,v;
    rep(i,n-1){
        sf("%d%d",&u,&v);
        G[u].PB(v);
        G[v].PB(u);
    }
}
int dfs(int u,int fa){
    num[u]=1;
    rep(i,G[u].size()){
        int v=G[u][i];
        if(v==fa)continue;
        num[u]+=dfs(v,u);
    }
    dp[u][1]=G[u].size()-(u!=1);
    rep(i,G[u].size()){
        int v=G[u][i];
        if(v==fa)continue;
        for(int s=num[u];s>=1;s--){
            for(int j=1;j<s&&j<=num[v];j++){
                dp[u][s]=min(dp[u][s],dp[u][s-j]+dp[v][j]-1);
            }
        }
    }
    //if(num[u]>=p)ans=min(ans,dp[u][p]+(u!=1));
    return num[u];
}
void solve(){
   ans=INF;
   dfs(1,-1);
   fab(i,1,n)ans=min(ans,dp[i][p]+(i!=1));
   pf("%d\n",ans);
}
int main(){
    while(~sf("%d%d",&n,&p)){
        init();
        solve();
    }
    return 0;
}

