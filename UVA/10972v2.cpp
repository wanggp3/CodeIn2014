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
const int N=2105;
using namespace std;
typedef pair<int,int>PII;
int n,m;
struct Edge{
    int v,flag;
    Edge(int v=0,int flag=0):v(v),flag(flag){}
};
vector<int>G[N];
vector<Edge>E;
int pre[N],low[N],dfs_clock,b_cnt,bccno[N],d[N];
void init(){
    rep(i,N)G[i].clear();
    E.clear();
    memset(pre,0,sizeof pre);
    memset(low,0,sizeof low);
    memset(bccno,0,sizeof bccno);
    memset(d,0,sizeof d);
    dfs_clock=b_cnt=0;
}
inline void addedge(int u,int v){
    E.PB(Edge(v,0));
    E.PB(Edge(u,0));
    int sz=E.size();
    G[u].PB(sz-2);
    G[v].PB(sz-1);
}
void dfs(int u,int fa){
    low[u]=pre[u]=++dfs_clock;
    rep(i,G[u].size()){
        Edge& e=E[G[u][i]];
        if(!pre[e.v]){
            dfs(e.v,u);
            low[u]=min(low[u],low[e.v]);
            if(low[e.v]>pre[u]){
                e.flag=1;
                E[G[u][i]^1].flag=1;
            }
        }else if(pre[e.v]<pre[u]&&e.v!=fa)low[u]=min(low[u],pre[e.v]);
    }
}
void dfs1(int u){
    bccno[u]=b_cnt;
    rep(i,G[u].size()){
        Edge& e=E[G[u][i]];
        if(!bccno[e.v]&&e.flag!=1)dfs1(e.v);
    }
}
void find_bcc(){
    fab(i,1,n){
        if(!pre[i])dfs(i,-1);
    }
    fab(i,1,n)if(!bccno[i])b_cnt++,dfs1(i);
}
void solve(){
    int u,v;
    rep(i,m){
        sf("%d%d",&u,&v);
        addedge(u,v);
    }
    find_bcc();
    if(b_cnt==1){
        puts("0");
        return;
    }
    fab(u,1,n){
        rep(i,G[u].size()){
            int v=E[G[u][i]].v;
            if(bccno[v]!=bccno[u])d[bccno[u]]++;
        }
    }
    int ans=0;
    fab(i,1,b_cnt){
        if(d[i]==0)ans+=2;
        else if(d[i]==1)ans++;
    }
    pf("%d\n",(ans+1)/2);
}
int main(){
    while(~sf("%d%d",&n,&m)){
        init();
        solve();
    }
    return 0;
}


