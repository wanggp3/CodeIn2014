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
const int N=3005;
using namespace std;
int sum[N],dp[N][2],a[N],n;
int ok(int x){
    if(x>=1&&x<=n)return 1;
    else return 0;
}
void init(){
    cls0(sum);
    cls0(dp);
    cls0(a);
    fab(i,1,n){
        sf("%d",&a[i]);
        sum[i]=sum[i-1]+ok(a[i]);
    }
}
void solve(){
    int ret=sum[n];
    for(int c=-2*n;c<=2*n;c++){
        int tmp=0;
        for(int i=n;i>=1;i--){
            tmp+=ok(a[i]+c);
            dp[i][0]=max(dp[i][0],tmp);
            ret=max(ret,dp[i][0]+sum[i-1]);
        }
    }
    for(int c=-2*n;c<=2*n;c++){
        int tmp1=ok(c+a[n]);
        int tmp2=dp[n][0]-tmp1;
        for(int i=n-1;i>=1;i--){
            tmp1+=ok(c+a[i]);
            ret=max(ret,sum[i-1]+tmp1+tmp2);
            tmp2=max(tmp2,dp[i][0]-tmp1);
        }
    }
    pf("%d\n",ret);
}
int main(){
    while(~sf("%d",&n)){
        init();
        solve();
    }
    return 0;
}

