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
    vector<Edge>E;
    vector<int>G[N];
    bool inq[N];
    int d[N],a[N],p[N];
    queue<int>Q;
    void init(int n){
        this->n=n;
        rep(i,n)G[i].clear();
        E.clear();
    }
    void addedge(int u,int v,int c,int w){
        E.PB(Edge(u,v,c,0,w));
        E.PB(Edge(v,u,0,0,-w));
        m=E.size();
        G[u].PB(m-2);
        G[v].PB(m-1);
    }
    bool spfa(int s,int t,LL &cost){
        rep(i,n)d[i]=INF;
        memset(inq,0,sizeof inq);
        while(!Q.empty())Q.pop();
        d[s]=0; inq[s]=1; a[s]=INF; p[s]=0; Q.push(s);
        while(!Q.empty()){
            int u=Q.front();Q.pop();
            inq[u]=0;
            rep(i,G[u].size()){
                Edge& e=E[G[u][i]];
                if(e.c>e.f && d[e.v]>d[u]+e.w){
                    d[e.v]=d[u]+e.w;
                    p[e.v]=G[u][i];
                    a[e.v]=min(a[u],e.c-e.f);
                    if(!inq[e.v]){
                        inq[e.v]=1;
                        Q.push(e.v);
                    }
                }
            }
        }
        if(d[t]>0)return false;
        cost+=1LL*d[t]*a[t];
        int u=t;
        while(u!=s){
            E[p[u]].f+=a[t];
            E[p[u]^1].f-=a[t];
            u=E[p[u]].u;
        }
        return true;
    }
    LL mincost(int s,int t){
        this->s=s; this->t=t;
        LL cost=0;
        while(spfa(s,t,cost));
        return cost;
    }
}g;
void solve(int cas){
    int month,store_cost;
    sf("%d%d",&month,&store_cost);
    int s=0,t=month*2+1;
    g.init(t+1);
    fab(i,1,month){
        int makecost,makelimit,price,maxsell,maxstore;
        sf("%d%d%d%d%d",&makecost,&makelimit,&price,&maxsell,&maxstore);
        g.addedge(s,i,makelimit,makecost);
        g.addedge(i+month,t,maxsell,-price);
        rep(j,maxstore+1)if(i+j<=month)g.addedge(i,month+i+j,INF,store_cost*j);
    }
    pf("Case %d: %lld\n",cas,-g.mincost(s,t));
}
int main(){
    int T;sf("%d",&T);
    rep(cas,T){
        solve(cas+1);
    }
    return 0;
}


