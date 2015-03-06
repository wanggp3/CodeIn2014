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
const int N=205;
using namespace std;
int val[N],col[N],len[N],dp[N][N][N];
int cnt,n;
void init(){
    sf("%d",&n);
    rep(i,n)sf("%d",&val[i]);
    memset(col,0,sizeof col);
    memset(len,0,sizeof len);
    cnt=0;
    col[0]=val[0];
    rep(i,n){
        if(val[i]==col[cnt]){
            len[cnt]++;
        }else{
            ++cnt;
            len[cnt]=1;
            col[cnt]=val[i];
        }
    }
}
int sqr(int x){return x*x;}
int dfs(int L,int R,int k){
  if(dp[L][R][k]!=-1)return dp[L][R][k];
  if(L>R)return 0;
  if(L==R)return dp[L][R][k]=sqr(len[L]+k);
  dp[L][R][k]=dfs(L,R-1,0)+sqr(k+len[R]);
  for(int i=R-1;i>=L;i--){
      if(col[i]==col[R])dp[L][R][k]=max(dp[L][R][k],dfs(i+1,R-1,0)+dfs(L,i,k+len[R]));
  }
  return dp[L][R][k];
}
void solve(){
    memset(dp,-1,sizeof(dp));
    int ans=dfs(0,cnt,0);
    pf("%d\n",ans);
}
int main(){
    int T;
    sf("%d",&T);
    int cas=0;
    while(T--){
      init();
      pf("Case %d: ",++cas);
      solve();
    }
    return 0;
}

