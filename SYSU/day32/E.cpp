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
#define INF 0x3f3f3f3f
const int N=1005;
int n,m,s,t;
vector<int>V[N];
struct Edge{
    int from,to,cap,flow;
    Edge(int from=0,int to=0,int cap=0,int flow=0):from(from),to(to),cap(cap),flow(flow){}
};
vector<Edge>edges;
vector<int>G[N];
bool vis[N];
int d[N];
int cur[N];
int R[N],C[N];
void addEdge(int u,int v,int cap){
    edges.PB(Edge(u,v,cap,0));
    edges.PB(Edge(v,u,0,0));
    int sz=edges.size();
    G[u].PB(sz-2);
    G[v].PB(sz-1);
}
bool bfs(){
    memset(vis,0,sizeof vis);
    queue<int>Q;
    Q.push(s);
    d[s]=0;
    vis[s]=1;
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        rep(i,G[u].size()){
            Edge& e=edges[G[u][i]];
            if(!vis[e.to]&&e.cap>e.flow){
                vis[e.to]=1;
                d[e.to]=d[e.from]+1;
                Q.push(e.to);
            }
        }
    }
    return vis[t];
}
int dfs(int x,int a){
    if(x==t||a==0)return a;
    int flow=0,f=0;
    for(int &i=cur[x];i<G[x].size();i++){
        Edge& e=edges[G[x][i]];
        if(d[x]+1==d[e.to]&&(f=dfs(e.to,min(a,e.cap-e.flow)))>0){
            e.flow+=f;
            edges[G[x][i]^1].flow-=f;
            flow+=f;
            a-=f;
            if(a==0)break;
        }
    }
    return flow;
}
int dinic(){
    int flow=0;
    while(bfs()){
      memset(cur,0,sizeof cur);
      flow+=dfs(s,INF);
    }
    return flow;
}
int rows=0,cols=0;
void init(){
    rows=cols=0;
    rep(i,N){
        G[i].clear();
    }
    edges.clear();
    sf("%d%d",&n,&m);
    fab(i,1,n){
        sf("%d",&R[i]);
        rows+=R[i];
    }
    fab(i,1,m){
        sf("%d",&C[i]);
        cols+=C[i];
    }
}
/*queue<int>Q;
bool ok(int u){
   while(!Q.empty())Q.pop();
   memset(d,-1,sizeof d);
   d[u]=0;
   Q.push(u);
   while(!Q.empty()){
       int x=Q.front();Q.pop();
       rep(i,G[x].size()){
           Edge& e=edges[G[x][i]];
           if(e.cap>e.flow){
               if(d[e.to]==-1){
                   d[e.to]=d[x]+1;
                   Q.push(e.to);
               }else if(e.to==u){
                   if(d[x]>1)return true;
               }
           }
       }
   }
   return false;
}*/
stack<int>sta;
int dfs_clock=1,scc_cnt=1;
int dfn[N],low[N],scc_no[N];
bool flag=0;
void tarjan(int u){
    sta.push(u);
    dfn[u]=low[u]=++dfs_clock;
    rep(i,G[u].size()){
        Edge &e=edges[G[u][i]];
        int v=e.to;
        if(e.cap>e.flow){
            if(!dfn[v]){
                tarjan(v);
                low[u]=min(low[u],low[v]);
            }else if(!scc_no[v]){
                low[u]=min(low[u],dfn[v]);
            }
        }
    }
    if(low[u]==dfn[u]){
        int v;
        scc_cnt++;
        int cnt=0;
        do{
           v=sta.top();sta.pop();
           scc_no[v]=scc_cnt;
           cnt++;
        }while(v!=u);
        if(cnt>=3)flag=1;
    }
}
bool only(){
    memset(dfn,0,sizeof dfn);
    memset(low,0,sizeof low);
    memset(scc_no,0,sizeof scc_no);
    while(!sta.empty())sta.pop();
    flag=0;
    dfs_clock=scc_cnt=0;
    fab(i,0,t){
      if(!flag&&!dfn[i])tarjan(i);
    }
    return !flag;
}
void print(){
    puts("print");
    fab(i,0,t){
       // pf("%d :%d\n",i,scc_no[i]);
       pf("%d: ",i);
       rep(j,G[i].size()){
           Edge &e=edges[G[i][j]];
           if(e.cap>e.flow)pf("%d ",e.to);
       }
       pf("\n");
    }
}
void solve(){
    if(rows!=cols){
        puts("So native!");
    }else{
        s=0,t=n+m+1;
        fab(i,1,n){
            addEdge(s,i,R[i]);
            fab(j,1,m)addEdge(i,n+j,9);
        }
        fab(i,1,m){
            addEdge(n+i,t,C[i]);
        }
        int flow=dinic();
        if(flow!=rows)puts("So native!");
        else if(only())puts("So simple!");
        else puts("So young!");
    }
}
int main() {
    int T;sf("%d",&T);
    rep(cas,T){
        init();
        pf("Case #%d: ",cas+1);
        solve();
    }
    return 0;
}
