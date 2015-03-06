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
int R,C;
char G[N][N];
int d[N][N],dp[N][N];
bool inq[N][N];
int dx[]={-1,0,0,1};
int dy[]={0,1,-1,0};
typedef pair<int,int>PII;
bool bound(int x,int y){
    return x>=0&&x<R&&y>=0&&y<C;
}
void init(){
  sf("%d%d",&R,&C);
  rep(i,R){
      sf("%s",G[i]);
  }
}
void getFire(){
    rep(i,R)rep(j,C)d[i][j]=INF,inq[i][j]=0;
    queue<PII>Q;
    rep(i,R){
        rep(j,C)
        if(G[i][j]=='F'){
            Q.push(MP(i,j));
            d[i][j]=0;
            inq[i][j]=1;
        }
    }
    while(!Q.empty()){
        PII u=Q.front();Q.pop();
        int x=u.first,y=u.second;
        inq[x][y]=0;
        rep(k,4){
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(bound(nx,ny)&&G[nx][ny]!='#'&&d[nx][ny]>d[x][y]+1){
                d[nx][ny]=d[x][y]+1;
                if(!inq[nx][ny]){
                    Q.push(MP(nx,ny));
                    inq[nx][ny]=1;
                }
            }
        }
    }
   /* rep(i,R){
        rep(j,C)pf("%d ",d[i][j]);puts("");
    }*/
}
int spfa(){
    int ret=INF;
    int sx,sy;
    queue<PII>Q;
    rep(i,R)rep(j,C){
        dp[i][j]=INF;
        inq[i][j]=0;
        if(G[i][j]=='J'){
            sx=i;
            sy=j;
            dp[i][j]=0;
            Q.push(MP(i,j));
            inq[i][j]=1;
        }
    }
    while(!Q.empty()){
        PII u=Q.front();Q.pop();
        int x=u.first,y=u.second;
        inq[x][y]=0;
        rep(k,4){
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(G[nx][ny]=='#')continue;
            if(bound(nx,ny)){
                if(dp[x][y]+1>=d[nx][ny])continue;
                if(dp[x][y]+1<dp[nx][ny]){
                    dp[nx][ny]=dp[x][y]+1;
                    if(!inq[nx][ny]){
                        Q.push(MP(nx,ny));
                        inq[nx][ny]=1;
                    }
                }
            }else{
                ret=min(ret,1+dp[x][y]);
            }
        }
    }
    return ret;
}
void solve(){
    getFire();
    int ans= spfa();
    if(ans<INF)pf("%d\n",ans);
    else puts("IMPOSSIBLE");
}
int main(){
    int T;sf("%d",&T);
    while(T--){
        init();
        solve();
    }
    return 0;
}

