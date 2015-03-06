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
const int N=1505;
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
    queue<int>Q;
    void init(int n){
        this->n=n;
        rep(i,n)G[i].clear();
        E.clear();
    }
    void addedge(int u,int v,int c){
        E.PB(Edge(u,v,c,0));
        E.PB(Edge(v,u,0,0));
        m=E.size();
        G[u].PB(m-2);
        G[v].PB(m-1);
    }
    bool bfs(){
        memset(vis,0,sizeof vis);
        while(!Q.empty())Q.pop();
        d[s]=0; vis[s]=1; Q.push(s);
        while(!Q.empty()){
            int x=Q.front();Q.pop();
            rep(i,G[x].size()){
                Edge& e=E[G[x][i]];
                if( !vis[e.v]&& e.c>e.f){
                    vis[e.v]=1;
                    d[e.v]=d[x]+1;
                    Q.push(e.v);
                }
            }
        }
        return  vis[t];
    }
    int dfs(int x,int a){
        if(x==t||a==0)return a;
        int flow=0,f;
        for(int &i=cur[x];i<G[x].size();i++){
            Edge& e=E[G[x][i]];
            if(d[x]+1==d[e.v]&&(f=dfs(e.v,min(a,e.c-e.f)))>0){
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
        this->s=s; this->t=t;
        int flow=0;
        while(bfs()){
            memset(cur,0,sizeof cur);
            flow+=dfs(s,INF);
        }
        return flow;
    }
    void clearflow(){
        rep(i,E.size())E[i].f=0;
    }
}g;
#include<sstream>
int n,m,s,t;
vector<int> G[1005];
char name[15005];
char tmp[100];
void init(){
    s=0,t=n+m+1;
    g.init(t+1);
    rep(i,1005)G[i].clear();
}
int trans(char* s){
    int len=strlen(s);
    int ret=0;
    rep(i,len)ret=ret*10+(s[i]-'0');
    return ret;
}
bool ok(int x){
    g.init(t+1);
    fab(i,1,n){
        g.addedge(s,i,1);
        rep(j,G[i].size()){
            g.addedge(i,n+1+G[i][j],1);
        }
    }
    fab(i,1,m)g.addedge(n+i,t,x);
    return g.maxflow(s,t)==n;
}
void solve(){
    char ch;
    ch=getchar();
    fab(i,1,n){
        cin.getline(name,15005);
        istringstream in(name);
        while(in>>tmp){
            if(isdigit(tmp[0]))G[i].PB(trans(tmp));
        }
    }/*
    fab(i,1,n){
        rep(j,G[i].size())pf("%d ",G[i][j]);pf("\n");
    }*/
    int L=-1,R=n;
    while(L+1<R){
        int M=L+(R-L)/2;
        if(ok(M))R=M;
        else L=M;
    }
    pf("%d\n",R);
}
int main(){
    while(~sf("%d%d*c",&n,&m)&&(n+m)){
        init();
        solve();
    }
    return 0;
}


