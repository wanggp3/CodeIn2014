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
const int N=52;
using namespace std;
typedef pair<int,int>PII;
int g[N][N];
int pass[N],P[N],T[N],FT[N];
int dp[1<<8][1<<8][N];
int n,m,K;
void init(){
    rep(i,1<<8)rep(j,1<<8)rep(k,N)dp[i][j][k]=INF;
    memset(pass,0,sizeof pass);
    rep(i,N){
        rep(j,N)g[i][j]=INF;
    }
}
void input(){
    sf("%d%d%d",&n,&m,&K);
    rep(i,m){
        int a,b,c;sf("%d%d%d",&a,&b,&c);
        g[a][b]=g[b][a]=c;
    }
    rep(i,K){
        sf("%d%d%d",&P[i],&T[i],&FT[i]);
        int cnt;sf("%d",&cnt);
        rep(j,cnt){
            int x;sf("%d",&x);
            pass[x]|=(1<<i);
        }
    }
}
void pre(){
    fab(k,1,n){
        fab(i,1,n){
            fab(j,1,n){
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    fab(i,1,n)g[i][i]=0;
}
void solve(){
   dp[0][0][1]=0;
   int ans=INF;
   rep(i,1<<K){
       rep(j,1<<K){
           fab(u,1,n){
               if(dp[i][j][u]==INF)continue;
               int cur=dp[i][j][u];
               if(i==((1<<K)-1))ans=min(ans,cur+g[u][1]);
               rep(k,K)if(!((i>>k)&1)){
                   int &nxt=dp[i|(1<<k)][j|pass[P[k]]][P[k]];
                   int tmp=g[u][P[k]];
                   if((j>>k)&1)tmp+=FT[k];
                   else tmp+=T[k];
                   nxt=min(nxt,tmp+cur);
               }
               fab(v,1,n){
                   int &nxt=dp[i][j|pass[v]][v];
                   int tmp=g[u][v];
                   nxt=min(nxt,tmp+cur);
               }
           }
       }
   }
   /*int ans=INF;
   rep(s,1<<K)fab(i,2,n)ans=min(ans,g[i][1]+dp[(1<<K)-1][s][i]);*/
   pf("%d\n",ans);
}
int main(){
    int tes;sf("%d",&tes);
    rep(cas,tes){
        pf("Case #%d: ",cas+1);
        init();
        input();
        pre();
        solve();
    }
    return 0;
}


