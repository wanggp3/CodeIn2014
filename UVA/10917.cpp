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
const int N=10005;
using namespace std;
int n,m;
int d[N],dp[N];
int head[N];
struct Edge{
    int v,w,next;
    Edge(int v=0,int w=0,int next=0):v(v),w(w),next(next){}
}E[N*10];
int e=0;
void add(int u,int v,int w){
    E[e].v=v;
    E[e].w=w;
    E[e].next=head[u];
    head[u]=e++;
}
void init(){
    memset(head,-1,sizeof head);
    e=0;
    int u,v,w;
    rep(i,m){
        sf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
}
typedef pair<int,int>PII;
bool inq[N];
void dijkstra(int s){
    fill(d,d+N,INF);
    memset(inq,0,sizeof inq);
    d[s]=0;
    deque<int>Q;
    Q.push_back(s);
    inq[s]=1;
    while(!Q.empty()){
        int u=Q.front();Q.pop_front();
        inq[u]=0;
        for(int p=head[u];~p;p=E[p].next){
            int v=E[p].v;
            int w=E[p].w;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                //if(!inq[v])inq[v]=1, Q.push(v);
                if(!inq[v]){
                    if(d[v]>d[Q.front()])Q.push_back(v);
                    else Q.push_front(v);
                    inq[v]=1;
                }
            }
        }
    }
}
int dfs(int u,int fa){
   if(dp[u]!=-1)return dp[u];
   if(u==2)return 1;
   dp[u]=0;
   for(int p=head[u];~p;p=E[p].next){
       int v=E[p].v;
       if(v==fa)continue;
       if(d[v]<d[u])dp[u]+=dfs(v,u);
   }
   return  dp[u];
}
void solve(){
    dijkstra(2);
    //fab(i,1,n)pf("%d ",d[i]);pf("\n");
    memset(dp,-1,sizeof dp);
    int ans=dfs(1,-1);
    pf("%d\n",ans);
}
int main(){
    while(~sf("%d%d",&n,&m)&&n){
        init();
        solve();
    }
    return 0;
}

