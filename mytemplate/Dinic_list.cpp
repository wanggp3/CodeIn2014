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
const int N=555;
const int M=N*N;
using namespace std;
typedef pair<int,int>PII;
struct Edge{
    int v,c,f,next;
}E[M];
struct Dinic{
    int n,m,s,t,ecnt;
    int head[N],d[N];
    bool vis[N];
    queue<int>Q;
    void init(){
        ecnt=0;
        memset(head,-1,sizeof head);
    }
    void addedge(int u,int v,int c){
        E[ecnt].v=v; E[ecnt].c=c; E[ecnt].f=0; E[ecnt].next=head[u]; head[u]=ecnt++;
        E[ecnt].v=u; E[ecnt].c=0; E[ecnt].f=0; E[ecnt].next=head[v]; head[v]=ecnt++;
    }
    bool bfs(){
        memset(vis,0,sizeof vis);
        while(!Q.empty())Q.pop();
        Q.push(s);d[s]=0;vis[s]=1;
        while(!Q.empty()){
            int x=Q.front();Q.pop();
            for(int p=head[x];~p;p=E[p].next){
               Edge &e=E[p];
               if(!vis[e.v] && e.c > e.f) {
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
        for(int p=head[x];~p;p=E[p].next){
            Edge& e=E[p];
            if(d[x]+1==d[e.v] && (f=dfs(e.v,min(a,e.c-e.f)))>0){
                e.f+=f;
                E[p^1].f-=f;
                flow+=f;
                a-=f;
                if(a==0)break;
            }
        }
        return flow;
    }
    int maxflow(int s,int t){
        this->s=s;this->t=t;
        int flow=0;
        while(bfs())flow+=dfs(s,INF);
        return flow;
    }
}solver;
int main(){
    
    return 0;
}


