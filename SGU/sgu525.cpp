//By team8__
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <complex>
#include <cstring>
#include <iomanip>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define fab(i, a, b) for(int i=(a); i<=(b); i++)
#define PB push_back
#define MP make_pair
#define LL long long
#define sf scanf
#define pf printf
const int N = 1005;
vector<int>G[N];
bool g[N][N],go[N][N],from[N][N];
int n,m,dfs_clock,scc_cnt;
int dfn[N],low[N];
int scc_no[N],cnt[N];

struct Edge{
    int u,v;
    Edge(int u=0,int v=0):u(u),v(v){}
}E[N*20];
stack<int>sta;
void init(){
     rep(i,N)G[i].clear();
}
void input(){
    int u,v;
    rep(i,m){
        sf("%d%d",&u,&v);
        E[i].u=u;E[i].v=v;
        G[u].PB(v);
    }
}
void dfs(int u){
    low[u]=dfn[u]=++dfs_clock;
    sta.push(u);
    rep(i,G[u].size()){
        int v=G[u][i];
        if(!dfn[v]){
            dfs(v);
            low[u]=min(low[u],low[v]);
        }else if(!scc_no[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u]){
        int w;
        ++scc_cnt;
        do{
            w=sta.top();sta.pop();
            scc_no[w]=scc_cnt;
            cnt[scc_cnt]++;
        }while(w!=u);
    }
}
void Tarjan(){
   memset(cnt,0,sizeof cnt);
   memset(low,0,sizeof low);
   memset(dfn,0,sizeof dfn);
   memset(scc_no,0,sizeof scc_no);
   while(!sta.empty())sta.pop();
   dfs_clock=scc_cnt=0;
   fab(i,1,n){
       if(!dfn[i]){
           dfs(i);
       }
   }
}
void find(int u,int id){
    go[id][u]=1;
    fab(v,1,scc_cnt){
        if(g[u][v]&&!go[id][v]){
            find(v,id);
        }
    }
}
void find1(int v,int id){
    from[id][v]=1;
    fab(u,1,scc_cnt){
        if(g[u][v]&&!from[id][u]){
            find1(u,id);
        }
    }
}
void reg(){
    memset(from,0,sizeof from);
    memset(g,0,sizeof g);
    memset(go,0,sizeof go);
    rep(i,m){
        int u=scc_no[E[i].u];
        int v=scc_no[E[i].v];
        g[u][v]=1;
    }
    fab(i,1,scc_cnt){
        find(i,i);
    }
    fab(i,1,scc_cnt){
        find1(i,i);
    }
}
int work(int u,int v){
    int ret=0;
    fab(i,1,scc_cnt){
        if(go[u][i]&&from[v][i])ret+=cnt[i];
    }
    return ret;
}
void bug(){
    puts("bug");
    fab(i,1,n){
        pf("i = %d scc_cnt = %d\n",i,scc_no[i]);
    }
    puts("go");
    fab(i,1,scc_cnt){
        fab(j,1,scc_cnt)pf("%d ",go[i][j]);puts("");
    }
    puts("from");
    fab(i,1,scc_cnt){
        fab(j,1,scc_cnt)pf("%d ",from[i][j]);puts("");
    }
    puts("cnt");
    fab(i,1,scc_cnt)pf("%d ",cnt[i]);puts("");
}
vector<int>e;
void solve(){
    int ans=1;
    Tarjan();
    fab(i,1,scc_cnt)ans=max(ans,cnt[i]);
    reg();
    e.clear();
    rep(i,m){
       int u=E[i].u,v=E[i].v;
       if(scc_no[u]==scc_no[v])continue;
       u=scc_no[u],v=scc_no[v];
       int tmp=work(u,v);
       if(tmp>ans){
           ans=tmp;
           e.clear();
           e.PB(i+1);
       }else if(tmp==ans){
           e.PB(i+1);
       }
    }
    pf("%d\n",ans);
    if(e.size()>0){
        pf("%d\n",int(e.size()));
        rep(i,e.size()){
            if(i==e.size()-1)pf("%d\n",e[i]);
            else pf("%d ",e[i]);
        }
    }else{
        pf("%d\n",m);
        rep(i,m){
            if(i==m-1)pf("%d\n",i+1);
            else pf("%d ",i+1);
        }
    }
}
int main() {
    while(~sf("%d%d",&n,&m)){
        init();
        input();
        solve();
    }
    return 0;
}

