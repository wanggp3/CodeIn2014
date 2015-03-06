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
const int N=100005;
using namespace std;
int father[N],dep[N],f[N];
bool used[N],vis[N];
int n,m;
vector<int>G[N];
typedef pair<int,int>PII;
vector<PII>Q[N];
struct Node{
    int d,u,v,id;
    int lca;
    bool operator<(const Node& rhs)const{
        return d>rhs.d;
    }
}qurry[N];
void init(){
    rep(i,N){
        Q[i].clear();
        G[i].clear();
        father[i]=-1;
        f[i]=-1;
        used[i]=vis[i]=0;
        dep[i]=0;
    }
}
void input(){
    int u,v;
    rep(i,n-1){
        sf("%d%d",&u,&v);
        G[u].PB(v);
        G[v].PB(u);
    }
    rep(i,m){
        sf("%d%d",&u,&v);
        Q[u].PB(MP(v,i));
        Q[v].PB(MP(u,i));
        qurry[i].u=u,qurry[i].v=v,qurry[i].id=i,qurry[i].d=0;
    }
}
void dfs1(int u,int fa,int d){
    father[u]=fa;
    dep[u]=d;
    rep(i,G[u].size()){
        int v=G[u][i];
        if(v==fa)continue;
        dfs1(v,u,d+1);
    }
}
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void dfs2(int x){
    f[x]=x;
    int y;
    rep(i,G[x].size()){
        y=G[x][i];
        if(f[y]!=-1)continue;
        dfs2(y);
        f[y]=x;
    }
    vis[x]=1;
    int id;
    rep(i,Q[x].size()){
        y=Q[x][i].first,id=Q[x][i].second;
        if(vis[y])qurry[id].lca=find(y),qurry[id].d=dep[qurry[id].lca];
    }
}
void dfs3(int x){
    used[x]=1;
    rep(i,G[x].size()){
        int v=G[x][i];
        if(v==father[x]||used[v])continue;
        dfs3(v);
    }
}
void solve(){
   dfs1(1,-1,0);
   dfs2(1);
   sort(qurry,qurry+m);
   int ans=0;
   rep(i,m){
     int Lca=qurry[i].lca;
     int u=qurry[i].u,v=qurry[i].v;
     if(!used[Lca]&&!used[u]&&!used[v]){
         dfs3(Lca);
         ans++;
     }
   }
   pf("%d\n",ans);
}
int main(){
    while(~sf("%d%d",&n,&m)) {
        init();
        input();
        solve();
    }
    return 0;
}

