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
const int N=505;
using namespace std;
typedef pair<int,int>PII;
struct Edge{
    int u,v,c,f,w;
    Edge(int u=0,int v=0,int c=0,int f=0,int w=0):u(u),v(v),c(c),f(f),w(w){
    }
};
struct MCMF{
    int n,m,s,t;
    vector<Edge>edges;
    vector<int>G[N];
    int inq[N],d[N],p[N],a[N];
    queue<int>Q;
    void init(int n){
        this->n = n;
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
    bool spfa(int s,int t,int &flow,int &cost){
        rep(i,n)d[i]=INF;
        memset(inq,0,sizeof inq);
        d[s]=0; inq[s]=1; p[s]=0; a[s]=INF;
        while(!Q.empty())Q.pop();
        Q.push(s);
        while(!Q.empty()){
           int u=Q.front();Q.pop();
           inq[u]=0;
           rep(i,G[u].size()){
               Edge& e = edges[G[u][i]];
               if(e.c>e.f&&d[e.v]>d[u]+e.w){
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
        if(d[t]==INF||a[t]==0)return false;
        flow+=a[t];
        cost+=d[t]*a[t];
        int u=t;
        cout<<a[t];
        while(u!=s){
            edges[p[u]].f+=a[t];
            edges[p[u]^1].f-=a[t];
            u=edges[p[u]].u;
        }
        return true;
    }
    PII mincost(int s,int t){
        int f=0,w=0;
        while(spfa(s,t,f,w))puts("H");
        return MP(f,w);
    }
}Fuck;
int n,m,k,S,T;
int st[N],ed[N],C[N][N],D[N][N],E[N][N],F[N][N];
void init(){
    rep(i,n)sf("%d%d",&st[i],&ed[i]);puts("fuck");
    rep(i,n)rep(j,m)sf("%d",&C[i][j]);puts("fuck");
    rep(i,n)rep(j,m)sf("%d",&D[i][j]);puts("fuck");
    rep(i,n)rep(j,n)sf("%d",&E[i][j]);puts("guck");
    rep(i,n)rep(j,n)sf("%d",&F[i][j]);puts("fuck");
}
void bug(){
    puts("bug");
}
void solve(){
    bug();
    S=3*n+m;T=S+1;
    Fuck.init(T);
    rep(i,n)Fuck.addedge(S,i,1,0);
    rep(i,m)Fuck.addedge(S,3*n+i,1,0);
    rep(i,n)Fuck.addedge(2*n+i,T,1,0);
    rep(i,n)Fuck.addedge(n+i,2*n+i,1,0);
    rep(i,n){
        rep(j,m){
            if(C[i][j]>=ed[i])continue;
            int w=D[i][j]+max(0,C[i][j]-st[i])*k;
            Fuck.addedge(3*n+j,n+i,1,w);
        }
    }
    rep(i,n){
        rep(j,n){
            if(i==j)continue;
            if(ed[i]+E[i][j]<ed[j]){
                int w=F[i][j]+max(0,ed[i]+E[i][j]-st[j])*k;
                Fuck.addedge(i,2*n+j,1,w);
            }
        }
    }
    PII ret=Fuck.mincost(S,T);
    bug();
    if(ret.first!=n)puts("-1");
    else pf("%d\n",ret.second);
}
int main(){
    while(~sf("%d%d%d",&n,&m,&k)&&(n+m+k)){
        init();
        solve();
    }
    return 0;
}


