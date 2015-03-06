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
const int N=105;
using namespace std;
typedef pair<int,int>PII;
const int UP=0,LEFT=1,DOWN=2,RIGHT=3;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int w[N][N][6];
int R,C,r1,c1,r2,c2;
int d[N][N][6];
int cas=1;
bool inq[N][N][6];
struct Node{
    int x,y,dir;
    Node(int x=0,int y=0,int dir=0):x(x),y(y),dir(dir){}
};
inline int ri(){
    int x;sf("%d",&x);return x;
}
bool bound(int x,int y){
    return x>=0&&x<R&&y>=0&&y<C;
}
void init(){
   r1--,c1--,r2--,c2--;
   rep(r,R){
       rep(c,C-1)w[r][c][RIGHT]=w[r][c+1][LEFT]=ri();
       if(r!=R-1){
           rep(c,C)w[r][c][DOWN]=w[r+1][c][UP]=ri();
       }
   }
   /*rep(r,R){
       rep(c,C){
           rep(k,4)pf("%d %d %d %d\n",r,c,k,w[r][c][k]);
           pf("\n");
       }
       pf("\n");
   }*/
}
int cnt=1;
void solve(){
    queue<Node>Q;
    rep(i,N){
        rep(j,N){
            rep(k,5)d[i][j][k]=INF;
        }
    }
    memset(inq,0,sizeof inq);
    Q.push(Node(r1,c1,4));
    d[r1][c1][4]=0;
    inq[r1][c1][4]=1;
    while(!Q.empty()){
        Node u=Q.front();Q.pop();
        //pf("%d %d %d %d\n",u.x,u.y,u.dir,d[u.x][u.y][u.dir]);
        inq[u.x][u.y][u.dir]=0;
        if(u.dir==4){
            rep(k,4){
                int nx=u.x+dx[k];
                int ny=u.y+dy[k];
                if(!bound(nx,ny)||w[u.x][u.y][k]==0)continue;
                if(d[nx][ny][k]>d[u.x][u.y][4]+w[u.x][u.y][k]*2){
                    d[nx][ny][k]=d[u.x][u.y][4]+w[u.x][u.y][k]*2;
                    if(!inq[nx][ny][k]){
                        inq[nx][ny][k]=1;
                        Q.push(Node(nx,ny,k));
                //        pf("%d %d %d %d %d\n",cnt++,nx,ny,k,d[nx][ny][k]);
                    }
                }
                
                if(d[nx][ny][4]>d[u.x][u.y][4]+w[u.x][u.y][k]*2){
                    d[nx][ny][4]=d[u.x][u.y][4]+w[u.x][u.y][k]*2;
                    if(!inq[nx][ny][4]){
                        inq[nx][ny][4]=1;
                        Q.push(Node(nx,ny,4));

                 //       pf("%d %d %d %d %d\n",cnt++,nx,ny,4,d[nx][ny][4]);
                    }
                }
            }
            
        }else{
                int nx=u.x+dx[u.dir];
                int ny=u.y+dy[u.dir];
                if(bound(nx,ny)&&w[u.x][u.y][u.dir]!=0){
                    if(d[nx][ny][u.dir]>d[u.x][u.y][u.dir]+w[u.x][u.y][u.dir]){
                        d[nx][ny][u.dir]=d[u.x][u.y][u.dir]+w[u.x][u.y][u.dir];
                        if(!inq[nx][ny][u.dir]){
                            inq[nx][ny][u.dir]=1;
                            Q.push(Node(nx,ny,u.dir));
                   //         pf("%d %d %d %d %d\n",cnt++,nx,ny,u.dir,d[nx][ny][u.dir]);
                        }
                    }
                }
                int nd;
                if(u.dir==0)nd=2;
                else if(u.dir==1)nd=3;
                else if(u.dir==2)nd=0;
                else if(u.dir==3)nd=1;
                if(d[u.x][u.y][4]>d[u.x][u.y][u.dir]+w[u.x][u.y][nd] ){
                   d[u.x][u.y][4]=d[u.x][u.y][u.dir]+w[u.x][u.y][nd];
                   if(!inq[u.x][u.y][4]){
                       inq[u.x][u.y][4]=1;
                       Q.push(Node(u.x,u.y,4));
                     //  pf("%d %d %d %d %d\n",cnt++,u.x,u.y,4,d[nx][ny][4]);
                   }
                }
        }
    }
    int ans=d[r2][c2][4];
    //rep(i,5)ans=min(ans,d[r2][c2][i]);
    if(ans==INF)pf("Case %d: Impossible\n",cas++);
    else pf("Case %d: %d\n",cas++,ans);
}
int main(){
    while(~sf("%d%d%d%d%d%d",&R,&C,&r1,&c1,&r2,&c2)&&(R+C)){
        init();
        solve();
    }
    return 0;
}


