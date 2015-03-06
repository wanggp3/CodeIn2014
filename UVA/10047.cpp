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
const int N=26;
using namespace std;
int n,m;
char G[N][N];
int d[N][N][4][5];
bool inq[N][N][4][5];
int sx,sy,ex,ey;
bool bound(int x,int y){
    return x>=0&&x<n&&y>=0&&y<m;
}
void init(){
    rep(i,n)sf("%s",G[i]);
    memset(inq,0,sizeof inq);
    rep(i,N){
        rep(j,N){
            rep(k,4){
                rep(t,5)d[i][j][k][t]=INF;
            }
        }
    }
}
struct node{
    int x,y,a,b;
    node(int x=0,int y=0,int a=0,int b=0)
        :x(x),y(y),a(a),b(b){}
};
int solve(){
    rep(i,n){
        rep(j,m){
            if(G[i][j]=='S'){
                sx=i,sy=j;
                G[i][j]='.';
            }
            if(G[i][j]=='T'){
                ex=i,ey=j;
            }
        }
    }
    int ret=INF;
    queue<node>Q;
    Q.push(node(sx,sy,0,0));
    d[sx][sy][0][0]=0;
    inq[sx][sy][0][0]=1;
    while(!Q.empty()){
        node u=Q.front();Q.pop();
        int x=u.x,y=u.y,a=u.a,b=u.b;
        inq[x][y][a][b]=0;
        if(x==ex&&y==ey&&b==0)ret=min(ret,d[x][y][a][b]);
        //left a->a+1
        int na=(a+1)%4;
        if(d[x][y][na][b]>d[x][y][a][b]+1){
            d[x][y][na][b]=d[x][y][a][b]+1;
            if(!inq[x][y][na][b]){
                Q.push(node(x,y,na,b));
                inq[x][y][na][b]=1;
            }
        }

        //right a->a-1
        na=(a-1+4)%4;
        if(d[x][y][na][b]>d[x][y][a][b]+1){
            d[x][y][na][b]=d[x][y][a][b]+1;
            if(!inq[x][y][na][b]){
                Q.push(node(x,y,na,b));
                inq[x][y][na][b]=1;
            }
        }

        //go
        int nx,ny,nb;
        if(a==1){
            nx=x;ny=y-1;na=a;nb=(b+1)%5;
            if(bound(nx,ny)&&G[nx][ny]!='#'&&d[nx][ny][na][nb]>d[x][y][a][b]+1){
                d[nx][ny][na][nb]=d[x][y][a][b]+1;
                if(!inq[nx][ny][na][nb]){
                    Q.push(node(nx,ny,na,nb));
                    inq[nx][ny][na][nb]=1;
                }
            }
        }
    
        
        if(a==3){
            nx=x;ny=y+1;na=a;nb=(b+1)%5;
            if(bound(nx,ny)&&G[nx][ny]!='#'&&d[nx][ny][na][nb]>d[x][y][a][b]+1){
                d[nx][ny][na][nb]=d[x][y][a][b]+1;
                if(!inq[nx][ny][na][nb]){
                    Q.push(node(nx,ny,na,nb));
                    inq[nx][ny][na][nb]=1;
                }
            }
        }

        
        if(a==0){
            nx=x-1;ny=y;na=a;nb=(b+1)%5;
            if(bound(nx,ny)&&G[nx][ny]!='#'&&d[nx][ny][na][nb]>d[x][y][a][b]+1){
                d[nx][ny][na][nb]=d[x][y][a][b]+1;
                if(!inq[nx][ny][na][nb]){
                    Q.push(node(nx,ny,na,nb));
                    inq[nx][ny][na][nb]=1;
                }
            }
        }


        if(a==2){
            nx=x+1;ny=y;na=a;nb=(b+1)%5;
            if(bound(nx,ny)&&G[nx][ny]!='#'&&d[nx][ny][na][nb]>d[x][y][a][b]+1){
                d[nx][ny][na][nb]=d[x][y][a][b]+1;
                if(!inq[nx][ny][na][nb]){
                    Q.push(node(nx,ny,na,nb));
                    inq[nx][ny][na][nb]=1;
                }
            }
        }
    }
    return ret;
}
int main(){
    bool f=0;
    int cas=1;
    while(sf("%d%d",&n,&m)&&(n+m)){
        init();
        if(f){
            puts("");
        }
        pf("Case #%d\n",cas++);
        f=1;
        int ans= solve();
        if(ans==INF)puts("destination not reachable");
        else pf("minimum time = %d sec\n",ans);
    }
    return 0;
}

