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
const int N=215;
using namespace std;
typedef pair<int,int>PII;
struct Edge{
    int u,v,c,f;
    Edge(int u=0,int v=0,int c=0,int f=0):u(u),v(v),c(c),f(f){}
};
struct Dinic{
    int n,m,s,t;
    vector<Edge>E;
    vector<int>G[N];
    queue<int>Q;
    bool vis[N];
    int d[N],cur[N];
    void init(int x){
        E.clear();
        rep(i,x)G[i].clear();
    }
    void addedge(int u,int v,int c){
        E.PB(Edge(u,v,c,0));
        E.PB(Edge(v,u,0,0));
        m=E.size();
        G[u].PB(m-2);G[v].PB(m-1);
    }
    bool bfs(){
        memset(vis,0,sizeof vis);
        while(!Q.empty())Q.pop();
        Q.push(s); d[s]=0; vis[s]=1;
        while(!Q.empty()){
            int x=Q.front();Q.pop();
            rep(i,G[x].size()){
                Edge& e=E[G[x][i]];
                if(!vis[e.v] && e.c>e.f){
                    vis[e.v]=1;
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
            if(d[x]+1==d[e.v]&&(f=dfs(e.v,min(a,e.c-e.f)))>0){
                e.f+=f;
                E[G[x][i]^1].f-=f;
                flow+=f;
                a-=f;
                if(a==0)break;
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
}solver;
int n,m,L[N*N],R[N*N];
int in[N],out[N];
int s,t;
int sum=0;
void init(){
    s=0,t=n+1;
    sum=0;
    memset(in,0,sizeof in);
    memset(out,0,sizeof out);
    solver.init(t+1);
}
void input(){
    int u,v;
    rep(i,m){
      sf("%d%d%d%d",&u,&v,&L[i],&R[i]);
      solver.addedge(u,v,R[i]-L[i]);
      //in[v]+=L[i];
      //out[u]+=L[i];
      solver.addedge(s,v,L[i]);
      solver.addedge(u,t,L[i]);
      sum+=L[i];
    }
    /*
    fab(i,1,n){
        int w=in[i]-out[i];
        if(w>0)solver.addedge(s,i,w),sum+=w;
        if(w<0)solver.addedge(i,t,-w);
    }*/
}
void solve(){
    int flow=solver.maxflow(s,t);
    /*bool flag=1;
    rep(i,solver.G[s].size()){
        if(solver.E[solver.G[s][i]].c!=solver.E[solver.G[s][i]].f){
            flag=0;
            break;
        }
    }*/
    if(sum!=flow)puts("NO");
    else{
        puts("YES");
        rep(i,m)pf("%d\n",solver.E[6*i].f+L[i]);
    }
}
int main(){
    while(~sf("%d%d",&n,&m)){
        init();
        input();
        solve();
    }
    return 0;
}


