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
const int N=1005;
using namespace std;
int n,m,s,t,k;
struct Edge{
    int u,v,c,f;
    Edge(int u=0,int v=0,int cap=0,int f=0)
        :u(u),v(v),c(c),f(f){  }
};
int sum;
int row[N],col[N];
vector<Edge>edges;
vector<int>G[N];
bool vis[N];
int cur[N],d[N];
void addEdge(int u,int v,int c){
    edges.PB(Edge(u,v,c,0));
    edges.PB(Edge(v,u,0,0));
    int sz=edges.size();
    G[u].PB(sz-2);
    G[v].PB(sz-1);
}
bool BFS(){
    memset(vis,0,sizeof vis);
    queue<int>Q;
    Q.push(s);
    d[s]=0;
    vis[s]=1;
    while(!Q.empty()){
        int x=Q.front();Q.pop();
        rep(i,G[x].size()){
            Edge& e=edges[G[x][i]];
            if(!vis[e.v]&&e.c>e.f){
                vis[e.v]=1;
                d[e.v]=d[e.u]+1;
                Q.push(e.v);
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
        if(d[x]+1==d[e.v]&&(f=DFS(e.v,min(a,e.c-e.f)))>0){
            e.f+=f;
            edges[G[x][i]^1].f-=f;
            flow+=f;
            a-=f;
            if(a==0)break;
        }
    }
    return flow;
}
int Dinic(){
    int f=0;
    while(BFS()){
        cout<<"bfsok "<< ' ';
        memset(cur,0,sizeof cur);
        f+=DFS(s,INF);
        cout<<f<<endl;
    }
    return f;
}
void init(){
    edges.clear();
    rep(i,N)G[i].clear();
    sum=0;
}
void print(){

}
bool dfs(int u,int fa){
    rep(i,G[u].size()){
        if(i==(fa^1))continue;
        Edge& e=edges[G[u][i]];
        if(e.f){
            if(vis[e.v])return true;
            vis[e.v]=1;
            if(dfs(e.v,G[u][i]))return true;
            vis[e.v]=0;
        }
    }
    return false;
}
int main(){
    while(~sf("%d%d%d",&n,&m,&k)){
        init();
        s=0,t=n+m+1;
        fab(i,1,n){
            sf("%d",&row[i]);
            addEdge(s,i,row[i]);
            sum+=row[i];
            fab(j,1,m)addEdge(i,j+n,k);
        }
        int tmp=0;
        fab(i,1,m){
            sf("%d",&col[i]);
            addEdge(i+n,t,col[i]);
            tmp+=col[i];
        }
        if(tmp!=sum){
            puts("Impossible");
            //cout<<"fucm"<<tmp<<' '<<sum<<endl;
        }else {
            int maxflow=Dinic();
            if(maxflow!=sum){
                cout<<"fuc "<<maxflow<<' '<<sum<<endl;
                puts("Impossible");
            }else{
                bool flag=0;
                memset(vis,0,sizeof vis);
                fab(i,1,n){
                    if(dfs(i,-1)){
                        flag=1;
                        break;
                    }
                }
                if(flag)puts("Not Unique");
                else print();
            }
        }
    }
    return 0;
}

