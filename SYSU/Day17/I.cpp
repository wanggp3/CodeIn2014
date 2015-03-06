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
const int MOD=1e9+7;
int dp[1<<21];
int n,k,l;
int main(){
    int T;
    sf("%d",&T);
    rep(cas,T){
        sf("%d%d%d",&n,&k,&l);
        cls0(dp);
        dp[0]=1;
        int left=0;
        if(l>k)left=l-k,l=k;
        int all=(1<<k)-1;
        rep(i,n){
          for(int mask=all;mask>=0;mask--){
              if(!dp[mask])continue;
              LL tmp=(LL)left*dp[mask]%MOD;
              int now=dp[mask];
              rep(j,l){
                 int nxt=(mask|(1<<j)|(all&(mask<<(j+1))));
                 dp[nxt]+=now;
                 if(dp[nxt]>MOD)dp[nxt]-=MOD;
              }
              dp[mask]+=tmp;
              if(dp[mask]>MOD)dp[mask]-=MOD;
          }
        }
        LL ans=0;
        rep(mask,all+1){
            if((mask>>(k-1))&1)ans=(ans+dp[mask])%MOD;
        }
        pf("%lld\n",ans);
    }
    return 0;
}

