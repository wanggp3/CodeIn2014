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
const int N=2005;
const double eps =1e-9;
using namespace std;
typedef pair<int,int>PII;

struct Edge{
    int u,v;
    double c,f;
    Edge(int u=0,int v=0,double c=0,double f=0):u(u),v(v),c(c),f(f){}
};/*
struct Dinic{
    int n,m,s,t;
    vector<Edge>E;
    vector<int>G[N];
    bool vis[N];
    int d[N],cur[N];
    queue<int>Q;
    void init(int x){
        rep(i,x)G[i].clear();
        E.clear();
    }
    void addedge(int u,int v,double c){
        E.PB(Edge(u,v,c,0));
        E.PB(Edge(v,u,0,0));
        m=E.size();
        G[u].PB(m-2);
        G[v].PB(m-1);
    }
    bool bfs(){
        memset(vis,0,sizeof vis);
        while(!Q.empty())Q.pop();
        Q.push(s); d[s]=0; vis[s]=1;
        while(!Q.empty()){
            int x=Q.front();Q.pop();
            rep(i,G[x].size()){
                Edge& e=E[G[x][i]];
                if(!vis[e.v]&&e.c>e.f){
                    vis[e.v]=1;
                    Q.push(e.v);
                    d[e.v]=d[x]+1;
                }
            }
        }
        return vis[t];
    }
    double dfs(int x,double a){
        if(x==t||a==0)return a;
        double flow=0,f;
        for(int& i=cur[x];i<G[x].size();i++){
            Edge& e=E[G[x][i]];
            if(d[e.v]==d[x]+1 && (f=dfs(e.v,min(a,e.c-e.f)))>0){
                flow+=f;
                e.f+=f;
                E[G[x][i]^1].f-=f;
                a-=f;
                if(a<=eps)break;
            }
        }
        return flow;
    }
    double maxflow(int s,int t){
        this->s=s; this->t=t;
        double flow=0;
        while(bfs()){
            memset(cur,0,sizeof cur);
            flow+=dfs(s,INF);
        }
        return flow;
    }
}g;*/
/*struct Edge{
    int u,v,c,f;
    Edge(int u=0,int v=0,int c=0,int f=0):u(u),v(v),c(c),f(f){}
};*/
struct ISAP{
    int n,m,s,t;
    vector<Edge>E;
    vector<int>G[N];
    bool vis[N];
    int d[N],cur[N],p[N],num[N];
    queue<int>Q;
    void addedge(int u,int v,double c){
        E.PB(Edge(u,v,c,0));
        E.PB(Edge(v,u,0,0));
        m=E.size();
        G[u].PB(m-2);
        G[v].PB(m-1);
    }
    bool bfs(){
        memset(vis,0,sizeof vis);
        while(!Q.empty())Q.pop();
        Q.push(t);
        d[t]=0; vis[t]=1;
        while(!Q.empty()){
            int x=Q.front();Q.pop();
            rep(i,G[x].size()){
                Edge& e=E[G[x][i]^1];
                if(!vis[e.u] && e.c>e.f){
                    vis[e.u]=1;
                    d[e.v]=d[x]+1;
                    Q.push(e.u);
                }
            }
        }
        return vis[s];
    }
    void init(int x){
        this->n=n;
        rep(i,n)G[i].clear();
        E.clear();
    }
    void clearflow(){
        rep(i,E.size())E[i].f=0;
    }
    double augment(){
        int x=t;
        double a=INF;
        while(x!=s){
            Edge& e=E[p[x]];
            a=min(a,e.c-e.f);
            x=E[p[x]].u;
        }
        x=t;
        while(x!=s){
            E[p[x]].f+=a;
            E[p[x]^1].f-=a;
            x=E[p[x]].u;
        }
        return a;
    }
    double maxflow(int s,int t){
        this->s=s;
        this->t=t;
        double flow=0;
        bfs();
        memset(num,0,sizeof num);
        rep(i,n)num[d[i]]++;
        int x=s;
        memset(cur,0,sizeof cur);
        while(d[s]<n){
            if(x==t){
                flow+=augment();
                x=s;
            }
            int ok=0;
            for(int i=cur[x];i<G[x].size();i++){
                Edge& e=E[G[x][i]];
                if(e.c>e.f && d[x]==d[e.v]+1){
                    ok=1;
                    p[e.v]=G[x][i];
                    cur[x]=i;
                    x=e.v;
                    break;
                }
            }
            if(!ok){
                int m=n-1;
                rep(i,G[x].size()){
                    Edge& e=E[G[x][i]];
                    if(e.c>e.f)m=min(m,d[e.v]);
                }
                if(--num[d[x]]==0)break;
                num[d[x]=m+1]++;
                cur[x]=0;
                if(x!=s)x=E[p[x]].u;
            }
        }
        return flow;
    }
    vector<int> mincut(){
        bfs();
        vector<int>ans;
        rep(i,E.size()){
            Edge& e=E[i];
            if(!vis[e.u] && vis[e.v] && e.c>0)ans.PB(i);
        }
        return ans;
    }
    void dfs(){
        memset(vis,0,sizeof vis);
        while(!Q.empty())Q.pop();
        Q.push(s);  vis[s]=1;
        while(!Q.empty()){
            int x=Q.front();Q.pop();
            rep(i,G[x].size()){
                Edge& e=E[G[x][i]];
                if(!vis[e.v] &&e.c>e.f){
                    vis[e.v]=1;
                    Q.push(e.v);
                }
            }
        }
    }
}g;
vector<int>ans;
int u[N],v[N];
int n,m,s,t;
void init(){
    s=0,t=n+m+1;
    fab(i,1,m)sf("%d%d",&u[i],&v[i]);
    ans.clear();
}
bool ok(double mid){
    g.init(t+1);
    fab(i,1,n)g.addedge(i,t,mid);
    fab(i,1,m){
        g.addedge(s,n+i,1);
        g.addedge(n+i,u[i],INF);
        g.addedge(n+i,v[i],INF);
    }
    double flow=g.maxflow(s,t);
    return double(m)-flow>eps;
}
void solve(){
    if(m==0){
        pf("1\n1\n");
        return ;
    }
    double L=0,R=m;
    while(R-L>=eps){
        double mid=(L+R)/2;
        if(ok(mid))L=mid;
        else R=mid;
    }
    ok(R);
    memset(g.vis,0,sizeof g.vis);
    g.dfs();
    fab(i,1,n)if(g.vis[i])ans.PB(i);
    pf("%d\n",int(ans.size()));
    rep(i,ans.size())pf("%d\n",ans[i]);
}
int main(){
    while(~sf("%d%d",&n,&m)){
        init();
        solve();
    }
    return 0;
}


