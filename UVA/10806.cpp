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
const int N=205;
using namespace std;
typedef pair<int,int>PII;
struct Edge{
    int u,v,c,f,w;
    Edge(int u=0,int v=0,int c=0,int f=0,int w=0):u(u),v(v),c(c),f(f),w(w){}
};
struct MCMF{
    int n,m,s,t;
    vector<Edge>edges;
    vector<int>G[N];
    int inq[N],d[N],p[N],a[N];
    queue<int>Q;
    void init(int n){
        this->n=n;
        rep(i,n)G[i].clear();
        edges.clear();
    }
    void addedge(int u,int v,int c,int w){
        edges.PB(Edge(u,v,c,0,w));
        edges.PB(Edge(v,u,0,0,-w));
        m=edges.size();
        G[u].PB(m-2);
        G[v].PB(m-1);
    }
    bool bellman(int s,int t,int &flow,int &cost){
        rep(i,n)d[i]=INF,inq[i]=0;
        d[s]=0; inq[s]=1; p[s]=0; a[s]=INF;
        Q.push(s);
        while(!Q.empty()){
            int u=Q.front();Q.pop();
            inq[u]=0;
            rep(i,G[u].size()){
                Edge& e=edges[G[u][i]];
                if(e.c>e.f && d[e.v]>d[u]+e.w){
                    d[e.v]=d[u]+e.w;
                    p[e.v]=G[u][i];
                    a[e.v]=min(a[u],e.c-e.f);
                    if(!inq[e.v]){
                        Q.push(e.v);
                        inq[e.v]=1;
                    }
                }
            }
        }
        if(d[t]==INF)return false;// s -t not connected
        flow+=a[t];
        cost+=d[t]*a[t];
        int u=t;
        while(u!=s){
            edges[p[u]].f+=a[t];
            edges[p[u]^1].f-=a[t];
            u=edges[p[u]].u;
        }
        return true;
    }
    PII mincost(int s,int t){
        int flow=0,cost=0;
        while(bellman(s,t,flow,cost));
        return MP(flow,cost);
    }
}g;
int n,m;
void solve(){
    int s=0,t=n+1;
    g.init(t+1);
    sf("%d",&m);
    rep(i,m){
        int u,v,w;
        sf("%d%d%d",&u,&v,&w);
        g.addedge(u,v,1,w);
        g.addedge(v,u,1,w);
    }
    g.addedge(s,1,2,0);
    g.addedge(n,t,2,0);
    PII ans=g.mincost(s,t);
    if(ans.first!=2)puts("Back to jail");
    else pf("%d\n",ans.second);
}
int main(){
    while(~sf("%d",&n)&&n){
        solve();
    }
    return 0;
}


