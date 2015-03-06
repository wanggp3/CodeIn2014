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
const int N=305;
using namespace std;
typedef pair<int,int>PII;
int n;
char g[N][N];
int v[N];
bool vis[N];
int ans;
void init(){
    rep(i,n)sf("%d",&v[i+1]);
    rep(i,n)sf("%s",g[i+1]+1);
}
void dfs(int id,int j){
    vis[j]=1;
    if(j>=id)ans=min(ans,v[j]);
    for(int i=1;i<=n;i++){
        if(g[j][i]=='1'&&!vis[i])dfs(id,i);
    }
}
void solve(){
    for(int i=1;i<=n;i++){
        ans=v[i];
        memset(vis,0,sizeof vis);
        for(int j=1;j<=n;j++){
            if(g[i][j]=='1'&&!vis[j])dfs(i,j);
        }
        for(int j=i+1;j<=n;j++){
            if(v[j]==ans){
                swap(v[j],v[i]);
                break;
            }
        }
        v[i]=ans;
    }
    rep(i,n)if(i==n-1)pf("%d\n",v[i+1]);
    else pf("%d ",v[i+1]);
}
int main(){
    while(~sf("%d",&n)){
        init();
        solve();
    }
    return 0;
}


