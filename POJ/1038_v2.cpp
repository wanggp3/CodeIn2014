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
int dp[2][N],last[20],now[20],fact[20];
bool g[155][20];
int n,m,k;
void init(){
    memset(g,0,sizeof g);
    memset(last,0,sizeof last);
    memset(now,0,sizeof now);
    fact[0]=1;
    fab(i,1,18)fact[i]=fact[i-1]*3;
}
int getdec(int *f){
    int ret=0;
    fab(i,1,m)ret+=fact[i-1]*f[i];
    return ret;
}
void getback(int v,int *f){
    fab(i,1,m){
        f[i]=v%3;
        v/=3;
    }
}
void input(){
    sf("%d%d%d",&n,&m,&k);
    int x,y;
    rep(i,k){
        sf("%d%d",&x,&y);
        g[x][y]=1;
    }
    fab(i,1,m)last[i]=g[1][i]+1;
    memset(dp[1],-1,sizeof dp[1]);
    int sta=getdec(last);
    dp[1][sta]=0;
}
void dfs(int x,int j,int v,int sta){
    dp[x&1][sta]=max(dp[x&1][sta],v);
    if(j>m)return;
    if(j+1<=m&&!last[j]&&!last[j+1]&&!now[j]&&!now[j+1]){
        now[j]=now[j+1]=2;
        int tmp=getdec(now);
        dfs(x,j+2,v+1,tmp);
        now[j]=now[j+1]=0;
    }
    if(j+2<=m&&!now[j]&&!now[j+1]&&!now[j+2]){
        now[j]=now[j+1]=now[j+2]=2;
        int tmp=getdec(now);
        dfs(x,j+3,v+1,tmp);
        now[j]=now[j+1]=now[j+2]=0;
    }
    dfs(x,j+1,v,sta);
}
void solve(){
    fab(i,2,n){
        memset(dp[i&1],-1,sizeof dp[i&1]);
        rep(j,fact[m]+1){
            if(dp[(i+1)&1][j]==-1)continue;
            getback(j,last);
            fab(t,1,m){
                if(g[i][t])now[t]=2;
                else now[t]=max(0,last[t]-1);
            }
            int sta=getdec(now);
            dfs(i,1,dp[(i+1)&1][j],sta);
        }
    }
    int ans=0;
    rep(i,fact[m]+1)ans=max(ans,dp[n&1][i]);
    pf("%d\n",ans);
}
int main(){
    int T;sf("%d",&T);
    while(T--){
        init();
        input();
        solve();
    }
    return 0;
}

