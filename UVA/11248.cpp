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
const int N=105;
using namespace std;
typedef pair<int,int>PII;
struct Edge{
    int u,v,c,f;
    Edge(int u=0,int v=0,int c=0,int f=0):u(u),v(v),c(c),f(f){}
    bool operator<(const Edge& rhs)const{
        return u<rhs.u || (u==rhs.u&&v<rhs.v);
    }
};
struct Dinic{
    int n,m,s,t;
    vector<Edge>E;
    vector<int>G[N];
    bool vis[N];
    int d[N],cur[N];
    void clearall(int x){
        rep(i,x)G[i].clear();
        E.clear();
    }
    void clearflow(){
        rep(i,m)E[i].f=0;
    }
    void addedge(int u,int v,int c){
        E.PB(Edge(u,v,c,0));
        E.PB(Edge(v,u,0,0));
        m=E.size();
        G[u].PB(m-2);
        G[v].PB(m-1);
    }
    queue<int>Q;
    bool bfs(){
        memset(vis,0,sizeof vis);
        while(!Q.empty())Q.pop();
        Q.push(s); d[s]=0; vis[s]=1;
        while(!Q.empty()){
            int x=Q.front();Q.pop();
            rep(i,G[x].size()){
                Edge& e=E[G[x][i]];
                if(!vis[e.v] && e.c > e.f ){
                    vis[e.v] =1;
                    d[e.v]=d[x]+1;
                    Q.push(e.v);
                }
            }
        }
        return vis[t];
    }
    int dfs(int x,int a){
        if(x==t||a==0)return a;
        int flow=0,f;
        for(int &i=cur[x];i<G[x].size();i++){
            Edge& e=E[G[x][i]];
            if(d[e.v]==d[x]+1 && (f=dfs(e.v,min(a,e.c - e.f)))>0){
                flow+=f;
                e.f+=f;
                E[G[x][i]^1].f-=f;
                a-=f;
                if(a==0)return flow;
            }
        }
        return flow;
    }
    int maxflow(int s,int t){
        this->s=s;this->t=t;
        int flow=0;
        while(bfs()){
            memset(cur,0,sizeof cur);
            flow+=dfs(s,INF);
        }
        return flow;
    }
    vector<int> mincut(){
        vector<int>ret;
        rep(i,E.size()){
            Edge& e=E[i];
            if(e.c>0 && vis[e.u]&&!vis[e.v])ret.PB(i);
        }
        return ret;
    }
    void reduce(){
        rep(i,E.size())E[i].c-=E[i].f;
    }
}solver;
int n,m,cas,c;
void init(){
    solver.clearall(n);
}
void solve(){
    rep(i,m){
        int u,v,w;
        sf("%d%d%d",&u,&v,&w);
        solver.addedge(u-1,v-1,w);
    }
    int flow=solver.maxflow(0,n-1);
    pf("Case %d: ",cas++);
    if(flow>=c)puts("possible");
    else{
        vector<int>cut = solver.mincut();
        solver.reduce();
        vector<Edge>ans;
        rep(i,cut.size()){
            Edge& e=solver.E[cut[i]];
            e.c=c;
            solver.clearflow();
            if(flow+solver.maxflow(0,n-1)>=c)ans.PB(e);
            e.c=0;
        }
        if(ans.empty())puts("not possible");
        else{
            sort(ans.begin(),ans.end());
            pf("possible option:(%d,%d)",ans[0].u+1,ans[0].v+1);
            for(int i=1;i<ans.size();i++)pf(",(%d,%d)",ans[i].u+1,ans[i].v+1);
            pf("\n");
        }
    }
}
int main(){
    cas=1;
    while(~sf("%d%d%d",&n,&m,&c)&&n){
        init();
        solve();
    }
    return 0;
}


