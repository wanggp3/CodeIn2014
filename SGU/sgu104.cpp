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
const int N=105;
using namespace std;
int F,V;
int dp[N][N],p[N][N],w[N][N];
void init(){
    rep(i,N)rep(j,N)dp[i][j]=-INF;
    rep(i,N)dp[0][i]=0;
    memset(p,0,sizeof p);
    fab(i,1,F){
        fab(j,1,V){
            sf("%d",&w[i][j]);
        }
        p[i][i]=1;
        dp[i][i]=dp[i-1][i-1]+w[i][i];
    }
}
void solve(){
    fab(i,1,F){
        fab(j,i+1,V){
           dp[i][j]=dp[i][j-1];
           if(dp[i-1][j-1]+w[i][j]>dp[i][j]){
               dp[i][j]=dp[i-1][j-1]+w[i][j];
               p[i][j]=1;
           }
        }
    }
    pf("%d\n",dp[F][V]);
    int j=V;
    vector<int>ans;
    for(int i=F;i>=1;i--){
       while(!p[i][j])j--;
       ans.PB(j--);
    }
    for(int i=ans.size()-1;i>=0;i--)
        if(i==0)pf("%d\n",ans[i]);
        else pf("%d ",ans[i]);
    /*pf("ssss\n");
    fab(i,1,F){
        fab(j,1,V){
            pf("%d ",dp[i][j]);
        }
        pf("\n");
    }
    pf("ss\n");
    fab(i,1,F){
        fab(j,1,V){
            pf("%d ",p[i][j]);
        }
        pf("\n");
    }*/
}
int main(){
    while(~sf("%d%d",&F,&V)){
        init();
        solve();
    }
    return 0;
}

