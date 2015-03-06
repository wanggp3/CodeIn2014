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
struct rec{
    int x[2];
    int y[2];
    int c;
}a[N];
int ind[N];
int ans;
vector<int>G[N];
bool vis[N];
void init(){
    memset(vis,0,sizeof vis);
    memset(ind,0,sizeof ind);
    rep(i,N)G[i].clear();
    ans=INF;
    sf("%d",&n);
    rep(i,n){
        sf("%d%d%d%d%d",&a[i].y[0],&a[i].x[0],&a[i].y[1],&a[i].x[1],&a[i].c);
    }
}
bool ok(int i,int j){
    if(a[i].y[1]!=a[j].y[0])return 0;
    if(a[i].x[1]<=a[j].x[0])return 0;
    if(a[i].x[0]>=a[j].x[1])return 0;
    return 1;
}
void dfs(int cur,int col,int cnt){
    if(cnt>=ans)return;
    if(cur>=n){
        ans=min(ans,cnt);
        return;
    }
    rep(i,n){
        if(vis[i])continue;
       bool flag=1;
       rep(j,G[i].size()){
           if(!vis[G[i][j]]){
               flag=0;
               break;
           }
       }
       if(flag){
           vis[i]=1;
           if(a[i].c==col)dfs(cur+1,col,cnt);
           else dfs(cur+1,a[i].c,cnt+1);
           vis[i]=0;
       }
    }
}
void solve(){
    rep(i,n){
        rep(j,n){
            if(i==j)continue;
            if(ok(i,j))G[j].PB(i);
        }
    }
    dfs(0,0,0);
    pf("%d\n",ans);
}
int main(){
    int T;sf("%d",&T);
    while(T--){
        init();
        solve();
    }
    return 0;
}

