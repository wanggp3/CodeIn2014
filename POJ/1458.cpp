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
const int N=1005;
using namespace std;
int dp[N][N];
char a[N],b[N];
void solve(){
    memset(dp,0,sizeof dp);
    int len_a=strlen(a+1),len_b=strlen(b+1);
    fab(i,1,len_a){
        fab(j,1,len_b){
            if(a[i]==b[j])dp[i][j]=dp[(i-1)][j-1]+1;
            else dp[i][j]=max(dp[(i-1)][j],dp[i][j-1]);
        }
    }
    pf("%d\n",dp[len_a][len_b]);
}
int main(){
    while(sf("%s %s",a+1,b+1)==2){
        solve();
    }
    return 0;
}

