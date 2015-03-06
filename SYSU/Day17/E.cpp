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
const int N=1026;
using namespace std;
int a[N],n;
LL dp1[N][N],dp2[N][N],dp3[N][N];
const LL MOD=1e9+7;
void init(){
    rep(i,N)rep(j,N)
        dp1[i][j]=dp2[i][j]=dp3[i][j]=0;
}
void input(){
    sf("%d",&n);
    rep(i,n)sf("%d",&a[i+1]);
}
void solve(){
    for(int i=1;i<n;i++){
        dp1[i][a[i]]++;
        rep(j,N){
            dp1[i+1][j]=(dp1[i][j^a[i+1]]+dp2[i][j^a[i+1]])%MOD;
            dp2[i+1][j]=(dp1[i][j]+dp2[i][j])%MOD;
        }
    }
    /*for(int i=n;i>0;i--){
        dp3[i][a[i]]++;
        rep(j,N){
            dp3[i-1][j]=(dp3[i-1][j]+dp3[i][j])%MOD;
            dp3[i-1][j&a[i-1]]=(dp3[i-1][j&a[i-1]]+dp3[i][j])%MOD;
        }
    }*/
    LL ans=0;
    for(int i=1;i<n;i++){
        rep(j,N){
            ans=(ans+dp1[i][j]*dp3[i+1][j]%MOD)%MOD;
        }
    }
    pf("%lld\n",ans);
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

