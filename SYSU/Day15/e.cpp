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
const int N=105;
using namespace std;
struct node{
    int x,y,t;
    node(int x=0,int y=0,int  t=0)
         :x(x),y(y),t(t){
         }
}now;
queue<node>Q;
int f[N][N][N];
int temp[N][N];
char ch[N][N];
int ans,Time,m,n,K;
int sx,sy,ex,ey;
int dx[]={-1,0,0,1};
int dy[]={0,1,-1,0};
void init(){
    while(!Q.empty())Q.pop();
    
    rep(i,N){
        rep(j,N){
            temp[i][j]=INF;
            rep(h,N)f[i][j][h]=INF;
        }
    }
}
void input(){
  sf("%d%d%d%d",&n,&m,&Time,&K);
  rep(i,n){
      sf("%s",ch[i]);
      rep(j,m){
          if(ch[i][j]=='S'){
              sx=i,sy=j;
              ch[i][j]='0';
          }
          if(ch[i][j]=='L'){
              ex=i,ey=j;
              ch[i][j]='0';
          }
      }
  }
}
bool bound(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m)return true;
    else return false;
}
void solve(){
    ans=INF;
    f[sx][sy][0]=0;
    Q.push(node(sx,sy,0));
    while(!Q.empty()){
        now=Q.front();Q.pop();
        if(now.t>Time)continue; 
        temp[now.x][now.y]=min(temp[now.x][now.y],temp[ex][ey]);
        if(f[now.x][now.y][now.t]>=temp[now.x][now.y])continue;
        temp[now.x][now.y]=f[now.x][now.y][now.t];
        rep(k,4){
            int tot=0;
            int nx=now.x,ny=now.y,nt=now.t+1;
            for(int i=1;i<=K;i++){
                nx+=dx[k];
                ny+=dy[k];
                if(bound(nx,ny)){
                    if(ch[nx][ny]=='F'||nt>Time)break;
                    tot+=int(ch[nx][ny]-'0');
                    if(f[now.x][now.y][now.t]+tot*tot<f[nx][ny][nt]){
                        if(f[nx][ny][nt]==INF)Q.push(node(nx,ny,nt));
                        f[nx][ny][nt]=f[now.x][now.y][now.t]+tot*tot;
                        // Q.push(node(nx,ny,nt));
                    }
                }else break;
            }
        }
    }
    ans=temp[ex][ey];
    if(ans==INF)puts("胜败兵家事不期 卷土重来是大侠");
    else printf("%d\n",ans);
}
int main(){
    int T;
    sf("%d",&T);
    rep(cas,T){
        init();
        input();
        pf("Case %d: ",cas+1);
        solve();
    }
    return 0;
}

