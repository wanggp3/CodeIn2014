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
const int N=315;
using namespace std;
int S,T,n,m;
int type[N],R[N],tb[N],tp[N];
int d[N],p[N];
bool inq[N];
struct Edge{
    int v,w;
    Edge(int v=0,int w=0):v(v),w(w){}
};
vector<Edge>G[N];
void init(){
    rep(i,N){
        G[i].clear();
        type[i]=R[i]=tb[i]=tp[i]=p[i]=0;
        d[i]=INF;
        inq[i]=0;
    }
}
void input(){
    sf("%d%d",&n,&m);
    char tmp[2];
    fab(i,1,n){
        sf("%s %d %d %d",tmp,&R[i],&tb[i],&tp[i]);
        if(tmp[0]=='B')type[i]=1;
        else type[i]=2;
    }
    int u,v,w;
    rep(i,m){
        sf("%d%d%d",&u,&v,&w);
        G[u].PB(Edge(v,w));
        G[v].PB(Edge(u,w));
    }
}
void getcol(int u,int now,int& c,int& nxt){
    if(now<R[u]){
        c=type[u];
        nxt=R[u];
        return;
    }else{
        int tmp=(now-R[u])%(tb[u]+tp[u]);
        if(type[u]==1){
            if(tmp<tp[u]){
                c=2;
                nxt=now+tp[u]-tmp;
            }else {
                c=1;
                nxt=now+tb[u]-(tmp-tp[u]);
            }
        }else if(type[u]==2){
            if(tmp<tb[u]){
                c=1;
                nxt=now+tb[u]-tmp;
            }else{
                c=2;
                nxt=now+tp[u]-(tmp-tb[u]);
            }
        }
    }
}
int getwait(int u,int v,int now,int cnt){
   int ca,cb,nxta,nxtb;
   getcol(u,now,ca,nxta);
   getcol(v,now,cb,nxtb);
   if(ca==cb)return now;
   if(nxta==nxtb){
      if(cnt==0)return getwait(u,v,nxta,cnt+1);
      else if(now<=R[u]||now<=R[v])return getwait(u,v,nxta,cnt+1);
      else return INF;

   }else return min(nxta,nxtb);
}
void solve(){
   queue<int>Q;
   Q.push(S);
   d[S]=0;
   inq[S]=1;
   while(!Q.empty()){
       int u=Q.front();Q.pop();
       inq[u]=0;
       rep(i,G[u].size()){
           int v=G[u][i].v;
           int w=G[u][i].w;
           int wt=getwait(u,v,d[u],0);
           if(wt+w<d[v]){
               p[v]=u;
               d[v]=w+wt;
               if(!inq[v]){
                   Q.push(v);
                   inq[v]=1;
               }
           }
       }
   }

   if(d[T]==INF){
       puts("0");
   }else{
       printf("%d\n",d[T]);
       vector<int>ans;
       while(T!=S){
         ans.PB(T);
         T=p[T];
       }
       ans.PB(S);
       //pf("size %d\n",int(ans.size()));
       for(int i=ans.size()-1;i>=0;i--){
           if(i==0)pf("%d\n",ans[i]);
           else pf("%d ",ans[i]);
       }
   }
}
int main(){
    while(~sf("%d%d",&S,&T)){
        init();
        input();
        solve();
    }
    return 0;
}

