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
const int N=17;
using namespace std;
int n;
int g[N][N],sum[N][N];
int dp[N][N][N][N][N];
int getsum(int x1,int yy1,int x2,int yy2){
    int tmp= sum[x2][yy2]-sum[x1-1][yy2]-sum[x2][yy1-1]+sum[x1-1][yy1-1];
    return tmp*tmp;
}
int dfs(int x1,int yy1,int x2,int yy2,int k){
    if(dp[x1][yy1][x2][yy2][k]!=-1)return dp[x1][yy1][x2][yy2][k];
    if(k==0){
        return dp[x1][yy1][x2][yy2][k]=getsum(x1,yy1,x2,yy2);
    }
    int ret=INF;
    for(int x=x1;x<x2;x++){
        int tmp=min(dfs(x1,yy1,x,yy2,k-1)+getsum(x+1,yy1,x2,yy2),
                    dfs(x+1,yy1,x2,yy2,k-1)+getsum(x1,yy1,x,yy2));
        ret=min(tmp,ret);
    }
    for(int y=yy1;y<yy2;y++){
        int tmp=min(dfs(x1,yy1,x2,y,k-1)+getsum(x1,y+1,x2,yy2),
                    dfs(x1,y+1,x2,yy2,k-1)+getsum(x1,yy1,x2,y));
        ret=min(ret,tmp);
    }
    return dp[x1][yy1][x2][yy2][k]=ret;
}
void init(){
    memset(g,0,sizeof(g));
    memset(sum,0,sizeof(sum));
    memset(dp,-1,sizeof(dp));
    double avg=0;
    fab(i,1,8)fab(j,1,8)sf("%d",&g[i][j]),avg+=g[i][j];
    avg=avg*1.0/n;
    fab(i,1,8){
        fab(j,1,8){
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+g[i][j];
        }
    }
    int xx=dfs(1,1,8,8,n-1);
    pf("%d\n",xx);
    double ans=(double)xx*1.0/n-avg*avg;
    pf("%.3lf\n",sqrt(ans));
}
int main(){
    while(~sf("%d",&n)){
        init();
    }
    return 0;
}

