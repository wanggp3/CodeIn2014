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
const int N=555;
using namespace std;
struct Edge{
    int u,v,cap,flow;
    Edge(int u=0,int v=0,int cap=0,int flow=0)
        :u(u),v(v),cap(cap),flow(flow){}
};
int n,p;
int x[N],y[N];
struct Dinic{
    int n,m,s,t;
    vector<Edge>edges;
    vector<int>G[N];
    int d[N],cur[N];
    bool vis[N];
    void addedge(int u,int v,int cap){
        edges.PB(Edge(u,v,cap,0));
        edges.PB(Edge(v,u,0,0));
        m=edges.size();
        G[u].PB(m-2);
        G[v].PB(m-1);
    }
    void init(){
        rep(i,N){
            G[i].clear();
        }
        edges.clear();
    }
    bool bfs(){
        memset(vis,0,sizeof vis );
        queue<int>Q;
        Q.push(s);
        d[s]=0;
        vis[s]=1;
        while(!Q.empty()){
            int x=Q.front();Q.pop();
            rep(i,G[x].size()){
                Edge& e=edges[G[x][i]];
                if(!vis[e.v]&&e.cap>e.flow){
                    vis[e.v]=1;
                    d[e.v]=d[x]+1;
                    Q.push(e.v);
                }
            }
        }
        return vis[t];
    }
    LL dfs(int x,int a){
        if(x==t||a==0)return a;
        LL flow=0,f=0;
        for(int& i=cur[x];i<G[x].size();i++){
            Edge& e=edges[G[x][i]];
            if(d[x]+1==d[e.v]&&(f=dfs(e.v,min(a,e.cap-e.flow)))>0){
                e.flow+=f;
                edges[G[x][i]^1].flow-=f;
                flow+=f;
                a-=f;
                if(a==0)break;
            }
        }
        return flow;
    }
    LL maxflow(int s,int t){
        this->s=s;
        this->t=t;
        LL flow=0;
        while(bfs()){
            memset(cur,0,sizeof cur);
            flow+=dfs(s,INF);
        }
        return flow;
    }
}F;
void solve(){
    F.init();
   LL tot=0;
   rep(i,n){
       sf("%d%d",&x[i],&y[i]);
       tot+=1LL*(x[i]&y[i]);
       if((x[i]^y[i])&1){
            F.addedge(0,i+1,x[i]&y[i]);
       }else{
            F.addedge(i+1,n+1,x[i]&y[i]);
       }
   }
   rep(i,n){
       rep(j,n){
           if(i==j)continue;
           if(__gcd(p,x[i]^x[j]^y[i]^y[j])<=1){
               if((x[i]^y[i])&1)F.addedge(i+1,j+1,INF);
               else F.addedge(j+1,i+1,INF);
           }
       }
   }
   tot-=F.maxflow(0,n+1);
   //pf("%d\n",tot);
   cout<<tot<<endl;
}
int main(){
    while(~sf("%d%d",&n,&p)){
        solve();
    }
    return 0;
}

