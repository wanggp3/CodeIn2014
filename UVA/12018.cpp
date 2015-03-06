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
#define X first
#define Y second
const int N=2005;
using namespace std;
typedef pair<int,int>PII;
PII P[N];
int dp[N];
int n;
void init(){
    sf("%d",&n);
    fab(i,1,n)sf("%d%d",&P[i].X,&P[i].Y);
}
void solve(){
    sort(P+1,P+n+1);
    dp[0]=0;
    int j,cnt;
    int ans=0;
    fab(i,1,n){
       cnt=0;
       dp[i]=dp[i-1];
       fba(j,i,1){
           if(P[j].Y>=P[i].X)cnt++;
           if(j==1||P[j].X!=P[j-1].X)dp[i]=max(dp[i],dp[j-1]+(cnt-3>=0?cnt:0));
       }
       ans=max(ans,dp[i]);
    }
    pf("%d\n",ans);
}
int main(){
    int T;sf("%d",&T);
    rep(cas,T){
        init();
        pf("Case #%d: ",cas+1);
        solve();
    }
    return 0;
}


