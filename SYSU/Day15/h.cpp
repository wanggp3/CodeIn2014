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
const int N=1005;
using namespace std;
int dfn[N],low[N],scc[N],res[N],ind[N],you[N];
int n,m,u,v,scc_cnt,clock_cnt;
vector<int>G[N],g[N];
bool vis[N],insta[N];
stack<int>sta;
void bug(){
   // puts("bug");
}
void init(){
    rep(i,N){
        G[i].clear();
        g[i].clear();
        dfn[i]=low[i]=scc[i]=res[i]=insta[i]=ind[i]=you[i]=0;
    }
    scc_cnt=0;
    clock_cnt=1;
    while(!sta.empty())sta.pop();
}
void input(){
    sf("%d%d",&n,&m);
    rep(i,m){
        sf("%d%d",&u,&v);
        G[u].PB(v);
        g[v].PB(u);
    }
}
void dfs(int u){
    dfn[u]=low[u]=clock_cnt++;
    sta.push(u);
    insta[u]=1;
    rep(i,G[u].size()){
        v=G[u][i];
        if(!dfn[v]){
            dfs(v);
            low[u]=min(low[u],low[v]);
        }else if(insta[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u]){
        ++scc_cnt;
        you[scc_cnt]=sta.top();
        int t;
        do{
            t=sta.top();sta.pop();
            insta[t]=0;
            scc[t]=scc_cnt;
        }while(t!=u);
    }
}
int go(int u){
    int ret=0;
    cls0(vis);
    queue<int>Q;
    vis[u]=1;
    Q.push(u);
    while(!Q.empty()){
        int t=Q.front();Q.pop();
       // ret++;
        rep(i,g[t].size()){
            v=g[t][i];
            if(vis[v])continue;
            vis[v]=1;
            Q.push(v);
        }
    }
    rep(i,n)if(vis[i])ret++;
    return ret-1;
}
void solve(){
    rep(i,n){
        if(!dfn[i]){
            dfs(i);
        }
    }
    bug();
    int ans=0;
    rep(i,n){
        rep(j,g[i].size()){
            u=scc[i];
            v=scc[g[i][j]];
            if(u!=v){
                ++ind[v];
            }
        }
    }
    bug();
    for(int i=1;i<=scc_cnt;i++){
        if(ind[i]==0){
            res[i]=go(you[i]);
            ans=max(ans,res[i]);
        }
    }
    pf("%d\n",ans);
    bool flag=1;
    rep(i,n){
        if(res[scc[i]]==ans){
            
            if(flag)pf("%d",i);
            else pf(" %d",i);
            flag=0;
        }
    }
    pf("\n");
}
int main(){
    int T;
    sf("%d",&T);
    rep(cas,T){
        init();
        input();
        pf("Case %d: ",cas+1);
        solve();
    }
    return 0;
}

