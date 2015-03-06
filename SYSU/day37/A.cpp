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
const int N=55005;
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
        memset(d,-1,sizeof d);
        while(!Q.empty())Q.pop();
        Q.push(s); d[s]=0; 
        while(!Q.empty()){
            int x=Q.front();Q.pop();
            rep(i,G[x].size()){
                Edge& e=E[G[x][i]];
                if(d[e.v]==-1 && e.c>e.f){
                    d[e.v]=d[x]+1;
                    Q.push(e.v);
                }
            }
        }
        return d[t]!=-1;
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
int n,m,ans;
int s,t;
void input(){
    s=0,t=n+m+1;
    solver.init();
    int x;
    fab(i,1,n){
        sf("%d",&x);
        solver.addedge(m+i,t,x);
    }
    int u,v,w;
    ans=0;
    fab(i,1,m){
        sf("%d%d%d",&u,&v,&w);
        ans+=w;
        solver.addedge(s,i,w);
        solver.addedge(i,m+u,INF);
        solver.addedge(i,m+v,INF);
    }
}
void solve(){
    pf("%d\n",ans-solver.maxflow(s,t));
}
int main(){
    while(~sf("%d%d",&n,&m)){
        input();
        solve();
    }
    return 0;
}


