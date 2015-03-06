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
const int N=10;
using namespace std;
typedef pair<int,int> PII;
int dx[]={-1,0,0,1};
int dy[]={0,1,-1,0};
int n;
int ans=INF;
int a[N][N],vis[N][N];
int col[N];
void init(){
    rep(i,n)rep(j,n)sf("%d",&a[i][j]);
    memset(vis,0,sizeof vis);
    memset(col,0,sizeof col);
}
bool bound(int x,int y){
    return x>=0&&x<n&&y>=0&&y<n;
}
void dfs(int x,int y,int v){
    vis[x][y]=1;
    rep(k,4){
        int nx=x+dx[k];
        int ny=y+dy[k];
        if(!bound(nx,ny)||vis[nx][ny]==1)continue;
        if(a[nx][ny]==v)dfs(nx,ny,v);
        else vis[nx][ny]=2;
    }
}
int H(){
     memset(col,0,sizeof col);
     rep(i,n){
         rep(j,n){
             if(vis[i][j]!=1){
                 col[a[i][j]]=1;
             }
         }
     }
     int cnt=0;
     rep(i,6)if(col[i])cnt++;
     return cnt;
}
int getNum(int v){
    int cnt=0;
    rep(i,n){
        rep(j,n){
            if(vis[i][j]==2&&a[i][j]==v){
                cnt++;
                dfs(i,j,v);
            }
        }
    }
    return cnt;
}
bool idastar(int d){
    if(d==ans)return H()==0;
    if(d+H()>ans)return false;
    rep(i,6){
        int b[8][8];
        rep(j,n)rep(k,n)b[j][k]=vis[j][k];
        if(getNum(i)==0)continue;
        if(idastar(d+1))return true;
        rep(j,n)rep(k,n)vis[j][k]=b[j][k];
    }
    return false;
}
void solve(){
    dfs(0,0,a[0][0]);
    ans=H();
    while(1){
        if(idastar(0))break;
        ans++;
    }
    pf("%d\n",ans);
}
int main(){
    while(~sf("%d",&n)&&n){
        init();
        solve();
    }
    return 0;
}


