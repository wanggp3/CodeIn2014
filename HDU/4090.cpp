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
#define LL unsigned long long
const int N=1005;
using namespace std;
typedef pair<int,int>PII;
int n,m,k;
map<LL,int>Hash;
int ans;
void init(){
    ans=0;
    Hash.clear();
}
int dig[7];
int f(int a[][9]){
    rep(i,k+1)dig[i]=0;
    rep(i,n)rep(j,m)dig[a[i][j]]++;
    int ret=0;
    fab(i,1,k)ret+=dig[i]*dig[i];
    return ret;
}
int QX[66],QY[66];
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={0,-1,1,-1,1,1,0,-1};
bool bound(int x,int y){
    return x>=0&&x<n&&y>=0&&y<m;
}
void move(int a[][9]){
    rep(j,m){
        int p=n-1;
        fba(i,n-1,0)if(a[i][j])a[p--][j]=a[i][j];
        fba(i,p,0)a[i][j]=0;
    }
    int p=0;
    rep(j,m){
        bool flag=0;
        rep(i,n)if(a[i][j])flag=1;
        if(flag){
            rep(i,n)a[i][p]=a[i][j];
            p++;
        }
    }
    fab(i,p,m-1)rep(j,n)a[j][i]=0;
}
void dfs(int a[][9],int v){
    if(v+f(a)<=ans)return;
    ans=max(ans,v);
    int vis[9][9];
    int b[9][9];
    bool flag=0;
    rep(i,n)rep(j,m){
        vis[i][j]=0;
        if(a[i][j])flag=1;
    }
    if(!flag)return;
    int head=0,tail=0;
    int cnt=0;
    rep(i,n){
        rep(j,m){
            head=tail=0;
            if(a[i][j]&&!vis[i][j]){
                cnt++;
                QX[tail]=i;
                QY[tail++]=j;
                vis[i][j]=cnt;
                int nx,ny,x,y;
                while(head<tail){
                    nx=QX[head];
                    ny=QY[head++];
                    rep(t,8){
                        x=nx+dx[t];
                        y=ny+dy[t];
                        if(bound(x,y)&&a[x][y]==a[nx][ny]&&!vis[x][y]){
                            vis[x][y]=cnt;
                            QX[tail]=x;
                            QY[tail++]=y;
                        }
                    }
                }
            }
            if(tail<3)continue;
            rep(t,n)rep(tt,m)b[t][tt]=(vis[t][tt]==cnt?0:a[t][tt]);
            move(b);
            dfs(b,v+tail*tail);
        }
    }
}
void solve(){
   int a[9][9];
   rep(i,n){
       rep(j,m){
           sf("%d",&a[i][j]);
       }
   }
   dfs(a,0);
   pf("%d\n",ans);
}
int main(){
    while(~sf("%d%d%d",&n,&m,&k)){
        init();
        solve();
    }
    return 0;
}


