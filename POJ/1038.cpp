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
const int N=60005;
using namespace std;
int n,m,k;
bool g[220][17];
int fact[17];
int dp[2][N];
int last[16],now[16];
int getD(int* f){
    int ret=0;
    fab(i,1,m)ret+=f[i]*fact[i];
    return ret;
}
void getT(int x,int* f){
    fab(i,1,m){
        f[i]=x%3;
        x/=3;
    }
}
void init(){
    memset(g,0,sizeof g);
    memset(last,0,sizeof last);
    memset(now,0,sizeof now);
    fact[0]=0;
    fact[1]=1;
    fab(i,2,15)fact[i]=3*fact[i-1];
}
void input(){
    sf("%d%d%d",&n,&m,&k);
    rep(i,k){
        int x,y;
        sf("%d%d",&x,&y);
        g[x][y]=1;
    }
    fab(i,1,m)last[i]=g[1][i]+1;
    memset(dp[1],-1,sizeof dp[1]);
}
void dfs(int i,int j,int v,int sta){
    dp[i&1][sta]=max(dp[i&1][sta],v);
    if(j>=m)return;
    if(j+1<=m&&!last[j]&&!last[j+1]&&!now[j]&&!now[j+1]){
        now[j]=now[j+1]=2;
        int tmp=getD(now);
        dfs(i,j+2,v+1,tmp);
        now[j]=now[j+1]=0;
    }
    if(j<m-1&&!now[j]&&!now[j+1]&&!now[j+2]){
        now[j]=now[j+1]=now[j+2]=2;
        int tmp=getD(now);
        dfs(i,j+3,v+1,tmp);
        now[j]=now[j+1]=now[j+2]=0;
    }
    dfs(i,j+1,v,sta);
}
void solve(){
   int sta=getD(last);
   dp[1][sta]=0;
   fab(i,2,n){
       memset(dp[i&1],-1,sizeof dp[i&1]);
       rep(j,fact[m+1]){
           if(dp[(i+1)&1][j]==-1)continue;
           getT(j,last);
           fab(t,1,m){
               if(g[i][t])now[t]=2;
               else now[t]=max(0,last[t]-1);
           }
           int sta=getD(now);
           dfs(i,1,dp[(i+1)&1][j],sta);
       }
   }
   int ans=0;
   rep(j,fact[m+1])ans=max(ans,dp[n&1][j]);
   pf("%d\n",ans);
}
int main(){
    int T;
    sf("%d",&T);
    while(T--){
        init();
        input();
        solve();
    }
    return 0;
}

