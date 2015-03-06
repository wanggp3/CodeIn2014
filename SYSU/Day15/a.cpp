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
const int N=105;
using namespace std;
int a[N],g[N][N],dp[N][N],ans;
int n;
void init(){
    ans=0;
    rep(i,N){
        rep(j,N){
            g[i][j]=dp[i][j]=0;
        }
        a[i]=0;
    }
}
void input(){
    sf("%d",&n);
    fab(i,1,n)sf("%d",&a[i]);
    fab(i,1,n)fab(j,1,n)sf("%d",&g[i][j]);
    rep(i,n+1){
        g[i][0]=g[i][n+1]=1;
        g[0][i]=g[n+1][i]=0;
    }
}
void solve(){
   rep(i,n+1){
       dp[i][i+1]=dp[i+1][i]=dp[i][i]=1;
   }
   dp[n+1][n+1]=1;
   for(int d=2;d<=n;d++){
       for(int i=0;i+d<=n+1;i++){
           int j=i+d;
           for(int k=i+1;k<j;k++){
               if(dp[i][k]&&dp[k][j]){
                   if(g[i][k]||g[j][k])dp[i][j]=1;
               }
           }
       }
   }
   ans=-1;
   fab(i,1,n){
       if(dp[0][i]&&dp[i][n+1])ans=max(ans,a[i]);
   }
}
int main(){
    int T;
    sf("%d",&T);
    rep(cas,T){
        init();
        input();
        solve();
        pf("Case %d: %d\n",cas+1,ans);
    }
    return 0;
}

