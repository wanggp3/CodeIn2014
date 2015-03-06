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
#define INF (LL)1e18+1
#define MP make_pair
#define PB push_back
#define sf scanf
#define pf printf 
const int N=1005;
using namespace std;
int vis[11];
struct Edge{
    int u,v;
    LL c;
    Edge(int u=0,int v=0,LL c=0):u(u),v(v),c(v){}
    bool operator<(const Edge& rhs)const{
        return c>rhs.c;
    }
}E[N];
int n,m,k;
LL get(int S,int k){
  memset(vis,0,sizeof vis);
  rep(i,n){
      if((S>>i)&1)vis[i]=1;
      else vis[i]=0;
  }
  rep(i,n)pf("%d",vis[i]);pf("\n");
  if(vis[0]==vis[n-1])return INF;
  LL ret=0;
  rep(i,m){
      int u=E[i].u,v=E[i].v;
      if(vis[u]!=vis[v]){
          if(--k<0)ret+=E[i].c;
      }
  }
  return ret;
}
void solve(){
    rep(i,m){
        sf("%d%d%lld",&E[i].u,&E[i].v,&E[i].c);
        E[i].u--;
        E[i].v--;
    }
    sort(E,E+m);
    LL ans=INF;
    rep(i,(1<<n)){
        //pf("ss %lld\n",get(i,k));
        ans=min(ans,get(i,k));
    }
    pf("%lld\n",ans);
}
int main(){
    while(~sf("%d%d%d",&n,&m,&k)){
        solve();
    }
    return 0;
}

