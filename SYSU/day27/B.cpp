#include<iostream>
#include<cstring>
#include<stdio.h>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<iomanip>
#include<cmath>
#include<list>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)
#define fab(i,a,b) for(int i=(a);i<=(b);i++)
#define fba(i,b,a) for(int i=(b);i>=(a);i--)
#define cls(x) memset(x,0,sizeof(x))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define LL long long 
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define sf scanf
#define pf printf 
const int N=205;
using namespace std;
struct Edge{
    int from,to,cap,flow,cost;
    Edge(int from=0,int to=0,int cap=0,int flow=0,int cost=0)
        :from(from),to(to),cap(cap),flow(flow),cost(cost){

        }
};
struct MCMF{
    int n,m,s,t;
    vector<Edge>es;
    vector<int>G[N];
    int inq[N],d[N],p[N],a[N];
    void init(int n){
        this->n=n;
        rep(i,n)G[i].clear();
        es.clear();
    }
    void addEdge(int from,int to,int cap,int cost){
        es.PB(Edge(from,to,cap,0,cost));
        es.PB(Edge(to,from,0,0,-cost));
        m=es.size();
        G[from].PB(m-2);
        G[to].PB(m-1);
    }
    bool bfs(int s,int t,int &flow,int& cost){
        rep(i,n)d[i]=INF;
        memset(inq,0,sizeof inq);
        d[s]=0;
        inq[s]=1;
        p[s]=0;
        a[s]=INF;
        queue<int>Q;
        Q.push(s);
        while(!Q.empty()){
            int u=Q.front();Q.pop();
            inq[u]=0;
            rep(i,G[u].size()){
                Edge& e=es[G[u][i]];
                if(e.cap>e.flow&&d[e.to]>d[u]+e.cost){
                    d[e.to]=d[u]+e.cost;
                    p[e.to]=G[u][i];
                    a[e.to]=min(a[u],e.cap-e.flow);
                    if(!inq[e.to]){
                        Q.push(e.to);
                        inq[e.to]=1;
                    }
                }
            }
        }
        if(d[t]==INF)return 0;
        flow+=a[t];
        cost+=d[t]*a[t];
        int u=t;
        while(u!=s){
            es[p[u]].flow+=a[t];
            es[p[u]^1].flow-=a[t];
            u=es[p[u]].from;
        }
        return 1;
    }
    pair<int,int> minCost(int s,int t){
        int flow=0,cost=0;
        while(bfs(s,t,flow,cost));
        return MP(flow,cost);
    }
}X;
int n,m,k;
char s[N][N];
void init(){
    sf("%d%d%d",&n,&m,&k);  
    rep(i,n){
        sf("%s",s[i]);
    }

}
int main(){
    int T;sf("%d",&T);
    rep(cas,T){
        init();
        pf("Case %d : ",cas+1);
        solve();
    }
    return 0;
}

