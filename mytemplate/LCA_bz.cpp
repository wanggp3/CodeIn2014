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
const int N=100010;
const int maxn=N;
const int logmaxn=20;
using namespace std;
typedef pair<int,int>PII;
/*
struct LCA {
  int n;
  int fa[maxn];   // 父亲数组
  int cost[maxn]; // 和父亲的费用
  int L[maxn];    // 层次（根节点层次为0）
  int anc[maxn][logmaxn];     // anc[p][i]是结点p的第2^i级父亲。anc[i][0] = fa[i]
  int maxcost[maxn][logmaxn]; // maxcost[p][i]是i和anc[p][i]的路径上的最大费用

  // 预处理，根据fa和cost数组求出anc和maxcost数组
  void preprocess() {
    for(int i = 0; i < n; i++) {
      anc[i][0] = fa[i]; maxcost[i][0] = cost[i];
      for(int j = 1; (1 << j) < n; j++) anc[i][j] = -1;
    }   
    for(int j = 1; (1 << j) < n; j++)
      for(int i = 0; i < n; i++)
        if(anc[i][j-1] != -1) {
          int a = anc[i][j-1];
          anc[i][j] = anc[a][j-1];
          maxcost[i][j] = max(maxcost[i][j-1], maxcost[a][j-1]);
        }
  }

  // 求p到q的路径上的最大权
  int query(int p, int q) {
    int tmp, log, i;
    if(L[p] < L[q]) swap(p, q);
    for(log = 1; (1 << log) <= L[p]; log++); log--;

    int ans = -INF;
    for(int i = log; i >= 0; i--)
      if (L[p] - (1 << i) >= L[q]) { ans = max(ans, maxcost[p][i]); p = anc[p][i];}
   
    if (p == q) return ans; // LCA为p
   
    for(int i = log; i >= 0; i--)
      if(anc[p][i] != -1 && anc[p][i] != anc[q][i]) {
        ans = max(ans, maxcost[p][i]); p = anc[p][i];
        ans = max(ans, maxcost[q][i]); q = anc[q][i];
      }

    ans = max(ans, cost[p]);
    ans = max(ans, cost[q]);
    return ans; // LCA为fa[p]（它也等于fa[q]）
  }  
};
*/
struct LCA{
   int n,fa[N],cost[N],L[N],anc[N][20],maxcost[N][20];
   void preprocess(){
       rep(i,n){
           anc[i][0]=fa[i];maxcost[i][0]=cost[i];
           for(int j=1;(1<<j)<n;j++){
               anc[i][j]=-1;
           }
       }
       for(int j=1;(1<<j)<n;j++){
           rep(i,n){
               if(anc[i][j-1]!=-1){
                   int p=anc[i][j-1];
                   anc[i][j]=anc[p][j-1];
                   maxcost[i][j]=max(maxcost[i][j-1],maxcost[p][j-1]);
               }
           }
       }
   }
   int query(int p,int q){
        int k=0;
        if(L[p]<L[q])swap(p,q);
        while((1<<(k+1))<=L[p])k++;
   //     for(k=1;(1<<k)<=L[p];k++);k--;
        int ans=-INF;
        fba(i,k,0)if(L[p]-(1<<i)>=L[q]){
            ans=max(ans,maxcost[p][i]);
            p=anc[p][i];
        }
        if(p==q)return ans;/// lca = p 
        fba(i,k,0)if(anc[p][i]!=-1&&anc[p][i]!=anc[q][i]){
            ans=max(ans,maxcost[p][i]);p=anc[p][i];
            ans=max(ans,maxcost[q][i]);q=anc[q][i];
        }
        ans=max(ans,cost[p]);
        ans=max(ans,cost[q]);
        return ans;// lca = fa[p] = fa[q];
   }
};
LCA solver;

int pa[N];
int find(int x){
    return x==pa[x]?x:pa[x]=find(pa[x]);
}
vector<PII>G[N];
void dfs(int u,int fa,int lev){
    solver.L[u]=lev;
    rep(i,G[u].size()){
        int v=G[u][i].first;
        if(v!=fa){
            solver.fa[v]=u;
            solver.cost[v]=G[u][i].second;
            dfs(v,u,lev+1);
        }
    }
}
struct Edge{
    int u,v,d;
    bool operator< (const Edge& rhs)const{
        return d < rhs.d;
    }
}E[N];
int main(){
    int cas=0,n,m,Q;
    while(~sf("%d%d",&n,&m)&&n){
        rep(i,m){
            sf("%d%d%d",&E[i].u,&E[i].v,&E[i].d);
            E[i].u--;E[i].v--;
        }
        sort(E,E+m);
        rep(i,n){pa[i]=i;G[i].clear();}
        rep(i,m){
            int x=E[i].u,y=E[i].v,u=find(x),v=find(y);
            if(u!=v){
                pa[u]=v;
                G[x].PB(MP(y,E[i].d));
                G[y].PB(MP(x,E[i].d));
            }
        }
        solver.n=n;
        dfs(0,-1,0);
        solver.preprocess();
        if(++cas!=1)pf("\n");
        sf("%d",&Q);
        while(Q--){
            int a,b;sf("%d%d",&a,&b);
            pf("%d\n",solver.query(a-1,b-1));
        }
    }
    return 0;
}


