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
const int N=1005;
using namespace std;
int low[N],pre[N],bccno[N],col[N],iscut[N];
bool iscur[N],A[N][N],odd[N];
vector<int>G[N],bcc[N];
int n,m,bcc_cnt,dfs_clock;
struct Edge{
    int u,v;
    Edge(int u=0,int v=0):u(u),v(v){}
};
stack<Edge>S;
void init(){
   memset(A,0,sizeof A);
   int u,v;
   rep(i,m){
       sf("%d%d",&u,&v);
       A[u][v]=A[v][u]=1;
   }
   rep(i,N){
       G[i].clear();
       bcc[i].clear();
       low[i]=pre[i]=iscut[i]=col[i]=bccno[i]=0;
   }
   fab(i,1,n){
       fab(j,1,n)pf("%d ",A[i][j]);
       pf("\n");
   }
   fab(i,1,n)
       fab(j,i+1,n){
           if(!A[i][j]){
               G[i].PB(j);
               G[j].PB(i);
           }
       }
   while(!S.empty())S.pop();
}
void buggrap(){
    pf("buggrap\n");
    fab(i,1,n){
      pf("%d :",i);
      rep(j,G[i].size())pf("%d ",G[i][j]);
      pf("\n");
    }
}
int dfs(int u,int fa){
    int lowu;
    lowu=pre[u]=++dfs_clock;
    int child=0;
    rep(i,G[u].size()){
        int v=G[u][i];
        Edge e=Edge(u,v);
        if(!pre[v]){
            S.push(e);
            child++;
            int lowv= dfs(v,u);
            lowu=min(lowu,lowv);
            if(lowv>=pre[u]){
                iscut[u]=1;
                bcc_cnt++;
                bcc[bcc_cnt].clear();
                for(;;){
                    
                    Edge x=S.top();S.pop();
                    pf("bcccc %d: %d %d\n",bcc_cnt,x.u,x.v);
                    if(bccno[x.u]!=bcc_cnt){
                        bcc[bcc_cnt].PB(x.u);
                        bccno[x.u]=bcc_cnt;
                    }
                    if(bccno[x.v]!=bcc_cnt){
                        bcc[bcc_cnt].PB(x.v);
                        bccno[x.v]=bcc_cnt;
                    }
                    if(x.u==u&&x.v==v)break;
                }
            }else if(v!=fa&&pre[v]<pre[u]){
                S.push(e);
                lowu=min(lowu,pre[v]);
            }
        }
    }
    if(child==1&&fa<0)iscut[u]=0;
    return lowu;
}
void find_bcc(){
    bcc_cnt=0;
    dfs_clock=0;
    fab(i,1,n){
        if(!pre[i])dfs(i,-1);
    }
}
bool bip(int u,int id){
    rep(i,G[u].size()){
       int v=G[u][i];
       if(bccno[v]!=id)continue;
       if(col[v]==col[u])return false;
       if(!col[v]){
           col[v]=3-col[u];
           if(!bip(v,id))return false;
       }
    }
    return true;
}
void bugbcc(){
    puts("bugbcc");
    fab(i,1,bcc_cnt){
        pf("%d :",i);
        rep(j,bcc[i].size()){
            pf("%d ",bcc[i][j]);
        }
        pf("\n");
    }
}
void bugiscut(){
    puts("is cut");
    fab(i,1,n)pf("%d ",iscut[i]);
    puts("");
}
void solve(){
    find_bcc();
    memset(odd,0,sizeof odd);
    fab(i,1,bcc_cnt){
        memset(col,0,sizeof col);
        rep(j,bcc[i].size())bccno[bcc[i][j]]=i;
        int u=bcc[i][0];
        col[u]=1;
        if(!bip(u,i)){
            rep(j,bcc[i].size())odd[bcc[i][j]]=1;
        }
    }
    int ans=n;
    fab(i,1,n){
        if(odd[i])ans--;
    }
    pf("%d\n",ans);
    bugbcc();
    buggrap();
    bugiscut();
}
int main(){
    while(~sf("%d%d",&n,&m)&&(m+n)){
        init();
        solve();
    }
    return 0;
}
