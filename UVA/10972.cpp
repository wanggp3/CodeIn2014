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
const int N=2005;
using namespace std;
typedef pair<int,int>PII;
int n,m;
vector<int>G[N];
int  pre[N],low[N],d[N],dfs_clock,b_cnt;
void init(){
    rep(i,n+1)G[i].clear();
    memset(pre,0,sizeof pre);
    memset(low,0,sizeof low);
    memset(d,0,sizeof d);
    dfs_clock=b_cnt=0;
}
void dfs(int u,int fa){
    pre[u]=low[u]=++dfs_clock;
    rep(i,G[u].size()){
        int v=G[u][i];
        if(v==fa)continue;
        if(!pre[v]){
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>pre[u])b_cnt++;
        }else low[u]=min(low[u],pre[v]);
    }
}
void solve(){
    int u,v;
    rep(i,m){
        sf("%d%d",&u,&v);
        G[u].PB(v);
        G[v].PB(u);
    }
    fab(i,1,n){
        if(!pre[i]){
            b_cnt++;
            dfs(i,-1);
        }
    }
    if(b_cnt==1){
        puts("0");
        return;
    }
    int ans=0;
    bool used[N];
    memset(used,0,sizeof used);
    memset(d,0,sizeof d);
    fab(i,1,n){
        used[low[i]]=1;
        rep(j,G[i].size()){
            int u=i;
            int v=G[i][j];
            used[low[u]]=used[low[v]]=1;
            if(low[u]!=low[v])d[low[u]]++;
        }
    }
    fab(i,1,n){
        if(used[i]&&d[i]==0)ans+=2;
        else if(d[i]==1)ans++;
    }
    pf("%d\n",(ans+1)/2);
}
int main(){
    while(~sf("%d%d",&n,&m)){
        init();
        solve();
    }
    return 0;
}


