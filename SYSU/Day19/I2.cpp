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
#define cls0(x) memset(x,0,sizeof(x))
#define cls1(x) memset(x,-1,sizeof(x))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1
#define LL long long 
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define sf scanf
#define pf printf 
const int N=1025;
using namespace std;
int n,m,s,t;
struct Edge{
    int from,to,cap,flow;
    Edge(int from=0,int to=0,int cap=0,int flow=0)
        :from(from),to(to),cap(cap),flow(flow){
        }
};
vector<Edge>edges;
vector<int>G[N];
int d[N],cur[N];
bool vis[N];
void addEdge(int from,int to,int cap){
    edges.PB(Edge(from,to,cap,0));
    edges.PB(Edge(to,from,0,0));
    int size_=edges.size();
    G[from].PB(size_-2);
    G[to].PB(size_-1);
}
bool BFS(){
    cls0(vis);
    queue<int>Q;
    Q.push(s);
    d[s]=0;
    vis[s]=1;
    while(!Q.empty()){
        int x=Q.front();Q.pop();
        rep(i,G[x].size()){
            Edge& e=edges[G[x][i]];
            if(!vis[e.to]&&e.cap>e.flow){
                vis[e.to]=1;
                d[e.to]=d[e.from]+1;
                Q.push(e.to);
            }
        }
    }
    return vis[t];
}
int DFS(int x,int a){
    if(x==t||a==0)return a;
    int flow=0,f=0;
    for(int &i=cur[x];i<G[x].size();i++){
        Edge& e=edges[G[x][i]];
        if(d[x]+1==d[e.to]&&(f=DFS(e.to,min(a,e.cap-e.flow)))>0){
            e.flow+=f;
            edges[G[x][i]^1].flow-=f;
            flow+=f;
            a-=f;
            if(a==0)break;
        }
    }
    return flow;
}
int Dinic(){
    int flow=0;
    while(BFS()){
        cls0(cur);
        flow+=DFS(s,INF);
    }
    return flow;
}
void init(){
    edges.clear();
    rep(i,N){
        G[i].clear();
    }
}
int main(){
    int T;
    sf("%d",&T);
    rep(cas,T){
      init();
      int nn,mm,a,b,c;
      sf("%d%d",&nn,&mm);
      int ex=0;
      s=0,t=500+nn+1;
      for(int i=1;i<=500;i++){
          addEdge(s,i,mm);
      }
      rep(i,nn){
          sf("%d%d%d",&a,&b,&c);
          for(int j=b;j<=c;j++){
              addEdge(j,501+i,1);
          }
          addEdge(501+i,t,a);
          ex+=a;
      }
      int now=Dinic();
      //pf("%d\n",now);
      if(ex>=now)printf("Case %d: Yes\n",cas+1);
      else printf("Case %d: No\n",cas+1);
    }
    return 0;
}


