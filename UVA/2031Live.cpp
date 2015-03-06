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
const int N=10005;
using namespace std;
int a[N];
int dp[N][5][5];
int n;
int getv(int x,int y){
    if(x==y)return 1;
    else if(x==0||y==0)return 2;
    else if(abs(x-y)==2)return 4;
    else return 3;

}
int dfs(int k,int x,int y){
    if(k==n){
        return dp[k][x][y]=0;
    }
    if(dp[k][x][y]!=-1)return dp[k][x][y];
    //if(x==y&&x!=0)return INF;
    int ret=min(dfs(k+1,a[k],y)+getv(x,a[k]),dfs(k+1,x,a[k])+getv(y,a[k]));
    return dp[k][x][y]=ret;
}
int main(){
    int x;
    while(~sf("%d",&x)){
        if(!x)break;
        int cnt=0;
        a[cnt++]=x;
        while(sf("%d",&x)&&x)a[cnt++]=x;
        n=cnt;
        memset(dp,-1,sizeof dp);
        int ans=dfs(0,0,0);
        pf("%d\n",ans);
    }
    return 0;
}
