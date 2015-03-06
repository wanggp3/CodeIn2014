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
const int N=55005;
using namespace std;
struct Edge{
    int u,v,w;
    Edge(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
}edges[N];
typedef pair<int,int>PII;
vector<PII>E[N];
int degree[N],flag[N];
int n,m,q,limit;
vector<int>BIG;
LL sum[N][2];
void init(){
  rep(i,N){
      flag[i]=1;
      degree[i]=0;
      E[i].clear();
      sum[i][0]=sum[i][1]=0;  
    }
  BIG.clear();
}
void change(int u){
  rep(i,E[u].size()){
    int v=E[u][i].first,w=E[u][i].second;
    w*=flag[u]*flag[v];
    if(degree[v]<=limit)v=0;
    sum[v][0]-=w;
    sum[v][1]-=w;
  }
  if(degree[u]>limit){
    LL tmp=sum[u][1];
    sum[u][1]=-sum[u][0];
    sum[u][0]=-tmp;
  }
  flag[u]=-flag[u];
}
LL getsum(int x){
   LL ret=sum[0][x];
   rep(i,BIG.size()){
       ret+=sum[BIG[i]][x];
   }
   return ret;
}
int main(){
    int cas=0;
    while(~sf("%d %d %d",&n,&m,&q)){
        init();
        rep(i,m){
            sf("%d %d %d",&edges[i].u,&edges[i].v,&edges[i].w);
            degree[edges[i].u]++;
            degree[edges[i].v]++;
        }
        limit=sqrt(2*m+0.5);
        rep(i,n+1){
            if(degree[i]>limit)BIG.PB(i);
        }
        rep(i,m){
            int v=edges[i].v,u=edges[i].u,w=edges[i].w;
            if(degree[u]>limit){
                E[v].PB(MP(u,w));
                sum[v][w>0]+=w;
            }else if(degree[v]>limit){
                E[u].PB(MP(v,w));
                sum[u][w>0]+=w;
            }else {
                E[v].PB(MP(u,w));
                E[u].PB(MP(v,w));
                sum[0][w>0]+=w;
            }
        }
        if(cas++)puts("");
        while(q--){
            char op[10];
            sf("%s",op);
            if(op[0]=='Q'){
                LL ans=0;
                sf("%s",op);
                if(op[0]=='A')ans=getsum(0)+getsum(1);
                else if(op[0]=='-')ans=getsum(0);
                else if(op[0]=='+')ans=getsum(1);
pf("%lld\n",ans);
            }else{
                int x;
                sf("%d",&x);
                change(x);
            }
        }
    }
    return 0;
}

