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
const int N=5005;
using namespace std;
short int dp[N][N];
char str[N];
int n;
int dfs(int L,int R){
    if(L>R)return 0;
    if(L==R)return dp[L][L]=0;
    if(dp[L][R]!=-1)return dp[L][R];
    short int &ret=dp[L][R];
    if(str[L]==str[R])ret=dfs(L+1,R-1);
    else {
        ret=min(dfs(L,R-1)+1,dfs(L+1,R)+1);
    }
    return ret;
}
void solve(){
    sf("%s",str);
    memset(dp,-1,sizeof dp);
    dfs(0,n-1);
    pf("%d\n",dp[0][n-1]);
}
int main(){
    while(~sf("%d",&n)){
        solve();
    }
    return 0;
}

