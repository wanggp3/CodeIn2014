//By team8__
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <complex>
#include <cstring>
#include <iomanip>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define fab(i, a, b) for(int i=(a); i<=(b); i++)
#define PB push_back
#define INF 0x3f3f3f3f
#define MP make_pair
#define LL long long
#define sf scanf
#define pf printf
const int N = 51;

int dp[1<<8][1<<8][N];
int ok[1<<8][1<<8][N];
int d[N][N];
int P[N],T[N],FT[N],ni[N];
int canplay[N];
int ticket[10][N];
int n,m,K;
typedef pair<int,int> PII;
vector<PII>G[N];
queue<int>Q;
void init(){
    memset(canplay,-1,sizeof canplay);
    rep(i,N)G[i].clear();
    memset(ticket,0,sizeof ticket);
   rep(i,1<<8){
       rep(j,1<<8){
           rep(k,N)dp[i][j][k]=INF;
       }
   }
   memset(ok,0,sizeof ok);
}
void input(){
    sf("%d%d%d",&n,&m,&K);
    rep(i,m){
        int a,b,d;
        sf("%d%d%d",&a,&b,&d);
        a--;b--;
        G[a].PB(MP(b,d));
        G[b].PB(MP(a,d));
    }
    rep(i,K){
        sf("%d%d%d%d",&P[i],&T[i],&FT[i],&ni[i]);
        P[i]--;
        canplay[P[i]]=i;
        rep(j,ni[i]){
            int x;sf("%d",&x);x--;
            ticket[i][x]=1;
        }
    }
}
bool inq[N];
void spfa(int s){
   while(!Q.empty())Q.pop();
   memset(inq,0,sizeof inq);
   rep(i,n)d[s][i]=INF;
   Q.push(s);
   d[s][s]=0;
   inq[s]=1;
   while(!Q.empty()){
       int u=Q.front();Q.pop();
       inq[u]=0;
       rep(i,G[u].size()){
           int v=G[u][i].first,w=G[u][i].second;
           if(d[s][v]>d[s][u]+w){
               d[s][v]=d[s][u]+w;
               if(!inq[v]){
                   inq[v]=1;
                   Q.push(v);
               }
           }
       }
   }
}
void bug(){
    puts("bug");
    rep(i,n){
        rep(j,n)pf("%d ",d[i][j]);puts("");
    }
}
void pre(){
    rep(i,n){
        spfa(i);
    }
}
bool Ticket(int i,int j,int v){
    rep(k,K){
        if(!((i>>k)&1)&&!((j>>k)&1)&&ticket[k][v])return true;
    }
    return false;
}
void solve(){
    //cout<<int(~(1<<1))<<endl;
    int ans =INF;
    dp[0][0][0]=0;
    rep(i,1<<K){
        rep(j,1<<K){
            rep(u,n){
                if(dp[i][j][u]==INF)continue;
                //pf("%d %d %d %d\n",i,j,u,dp[i][j][u]);
                if(i==((1<<K)-1))ans=min(ans,dp[i][j][u]+d[u][0]);
                rep(v,n){
                    int id=canplay[v];
                    //if(id==-1&&!Ticket(i,j,v))continue;
                    if(id==-1){
                        rep(k,K){
                            if(!((i>>k)&1)&&!((j>>k)&1)&&ticket[k][v]){
        
                                dp[i][j|(1<<k)][v]=min(dp[i][j|(1<<k)][v],dp[i][j][u]+d[u][v]);
                                //pf("to i,j,v  %d %d %d   from   %d %d %d   dp=%d\n",i,j|(1<<k),v,i,j,u,dp[i][j|(1<<k)][v]);
                            }
                        }
                    }else{
                        rep(k,K){
                            if(!((i>>k)&1)&&!((j>>k)&1)&&ticket[k][v]){
                                dp[i][j|(1<<k)][v]=min(dp[i][j|(1<<k)][v],dp[i][j][u]+d[u][v]);
                            }
                            if(P[k]==v&&!((i>>k)&1)){
                                int tmp;
                                if((j>>k)&1)tmp=FT[k];
                                else tmp=T[k];
                                //cout<<"fuck"<<(j&(~(1<<k)))<<endl;
                                dp[i|(1<<k)][j&(~(1<<k))][v]=min(dp[i|(1<<k)][j&(~(1<<k))][v],dp[i][j][u]+tmp+d[u][v]);
                                
                                //pf(" to i,j,v %d %d %d     ---from  %d %d %d    %d= dp[from]+tmp+d  %d %d %d\n",i|(1<<k),j&(~(1<<k)),v,i,j,u,dp[i|(1<<k)][j&(~(1<<k))][v],dp[i][j][u],tmp,d[u][v]);
                            }
                        }
                    }
                }
            }
        }
    }
    /*
    int ans=INF;
    //for(int i=1;i<n;i++)ans=min(ans,dp[(1<<K)-1][0][i]+d[i][0]);
    rep(i,1<<K)rep(j,n-1)ans=min(ans,dp[(1<<K)-1][i][j+1]+d[j+1][0]);*/
    pf("%d\n",ans);
}
int main() {
    int tes;
    sf("%d",&tes);
    rep(cas,tes){
        pf("Case #%d: ",cas+1);
        init();
        input();
        pre();
        solve();
    }
    return 0;
}
