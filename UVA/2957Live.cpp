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
const int N=5000;
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
    bool vis[N];
    int d[N],cur[N];
    void clearall(int x){
        rep(i,x)G[i].clear();
        E.clear();
    }
    void clearflow(){
        rep(i,E.size())E[i].f=0;
    }
    void init(){E.clear();}
    void clearnode(int a,int b){
        fab(i,a,b)G[i].clear();
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
        d[s]=0; vis[s]=1; Q.push(s);
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
            if(d[x]+1==d[e.v] && (f=dfs(e.v,min(a,e.c-e.f)))>0){
                flow+=f;
                e.f+=f;
                E[G[x][i]^1].f-=f;
                a-=f;
                if(a==0)break;
            }
        }
        return flow;
    }
    int maxflow(int s,int ,int limit){
        this->s=s;this->t=t;
        int flow=0;
        while(bfs()){
            memset(cur,0,sizeof cur);
            flow+=dfs(s,limit-flow);
            if(flow>=limit)break;
        }
        return flow;
    }

}solver;
int U[N],V[N];
int n,m,s,t,k;
void init(){
    rep(i,m)sf("%d%d",&U[i],&V[i]);
    solver.init();
}
void solve(){
    int day=1;
    solver.clearnode(0,n-1);
    int flow=0;
    for(;;){
        solver.clearnode(day*n,day*n+n-1);
        rep(i,n)solver.addedge((day-1)*n+i,day*n+i,INF);
        rep(i,m){
            solver.addedge((day-1)*n+U[i]-1,day*n+V[i]-1,1);
            solver.addedge((day-1)*n+V[i]-1,day*n+U[i]-1,1);
        }
        flow+=solver.maxflow(s-1,day*n+t-1,k-flow);
        if(flow>=k)break;
        day++;
    }
    pf("%d\n",day);
    int idx=0;
    vector<int>location(k,s);
    fab(d,1,day){
        idx+=2*n;
        vector<int>moved(k,0);
        vector<int>a,b;
        rep(i,m){
            int f1=solver.E[idx].f;idx+=2;
            int f2=solver.E[idx].f;idx+=2;
            if(f1==1&&f2==0){
                a.PB(U[i]);b.PB(V[i]);
            }
            if(f1==0&&f2==1){
                a.PB(V[i]);b.PB(U[i]);
            }
        }
        pf("%d",int(a.size()));
        rep(i,a.size()){
            rep(j,k){
                if(!moved[j] && location[j]==a[i]){
                    pf(" %d %d",j+1,b[i]);
                    moved[j]=1;
                    location[j]=b[i];
                    break;
                }
            }
        }
        pf("\n");
    }
}
int main(){
    while(~sf("%d%d%d%d%d",&n,&m,&k,&s,&t)){
        init();
        solve();
    }
    return 0;
}


