//By team8
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <complex>
#include <cmath>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <vector>
#define rep(i, n) for(int i=0; i<n; i++)
#define sf scanf
#define pf printf
#define fab(i, a, b) for(int i=(a); i<=(b); i++)
#define LL long long
#define PB push_back
#define MP make_pair
using namespace std;
const int N=1005;
int n,m,L;
int a[N];
int dp[N][N];
int sum[N];
int maxv[N];
int get(int x,int y){
    if(y-x+1<L)return 0;
    else return sum[y]-sum[x-1];
}
void init(){
    memset(dp,0,sizeof dp);
    memset(a,0,sizeof a);
    memset(sum,0,sizeof sum);
    memset(maxv,0,sizeof maxv);
    fab(i,1,n) sf("%d",&a[i]);
    fab(i,1,n)sum[i]=sum[i-1]+a[i];
    //fab(i,1,n)pf("%d ",sum[i]);puts("");
}
int cal(int x,int y,int s){
    /*if(x==2&&s==10){
        pf("ss %d %d %d\n",maxv[y],sum[s],maxv[y]+sum[s]);
    }*/
    if(y>=x){
       return maxv[y-1]+sum[s];
    }else return 0;
}
void solve(){

    for(int j=1;j<=n;j++){
        dp[1][j]=get(1,j-1);
        for(int k=1;k<=j-L;k++){
           dp[1][j]=max(dp[1][j],get(1,k-1)+get(k+1,j));
        }
        if(j==1)maxv[1]=dp[1][1]-sum[1+1];
        else maxv[j]=max(maxv[j-1],dp[1][j]-sum[j+1]);
    }
    for(int i=2;i<=m;i++){
       // puts("maxv");for(int j=1;j<=n;j++)pf("%d ",maxv[j]);puts("");
        for(int j=n;j>=i;j--){
            dp[i][j]=max(dp[i-1][j-1],cal(i,j-L,j));
        }
        //for(int j=0;j<=i;j++)maxv[j]=0;
        for(int j=i;j<=n;j++){
            if(j==i)maxv[j]=dp[i][j]-sum[j+1];
            else maxv[j]=max(maxv[j-1],dp[i][j]-sum[j+1]);
        }
    }
    /*for(int i=1;i<=m;i++){
      for(int j=1;j<=n;j++)pf("%d ",dp[i][j]);pf("\n");
    }*/
    pf("%d\n",dp[m][n]);
}
int main() {
    while(~sf("%d%d%d",&n,&m,&L)){
        init();
        solve();
    }
    return 0;
}
