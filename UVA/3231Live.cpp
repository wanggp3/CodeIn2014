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
const int N=11005;
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
    void init(){
        E.clear();
        rep(i,N)G[i].clear();
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
    void setflow(int x,int sz){
        rep(i,sz){
            E[2*i].c=x;
        }
        rep(i,m)E[i].f=0;
    }
}solver;
int n,m,k;
int s,t;
void init(){
    sf("%d%d",&n,&m);
    s=0,t=n+m+1;
    solver.init();
    fab(i,1,n)solver.addedge(m+i,t,1);
    fab(i,1,m)solver.addedge(s,i,1);
    int a,b;
    rep(i,m){
        sf("%d%d",&a,&b);
        solver.addedge(i+1,m+a,1);
        solver.addedge(i+1,m+b,1);
    }
}
bool ok(int x){
    solver.setflow(x,n);
    int flow=solver.maxflow(s,t);
    if(flow==m)return true;
    else return false;
}
void solve(){
  int L=0,R=m;
  while(L+1<R){
      int M=(L+R)>>1;
      if(ok(M))R=M;
      else L=M;
  }
  pf("%d\n",R);
}
int main(){
    int T;sf("%d",&T);
    while(T--){
        init();
        solve();
    }
    return 0;
}


