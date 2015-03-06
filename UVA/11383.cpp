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
const int N=505;
using namespace std;
int n;
int match[N];
int lx[N],ly[N],w[N][N],slack[N];
int lack;
bool vix[N],viy[N];
void init(){
    fab(i,1,n){
        fab(j,1,n)sf("%d",&w[i][j]);
    }
}

bool find(int x){
    vix[x]=1;
    fab(y,1,n){
        if(viy[y])continue;
        int t=lx[x]+ly[y]-w[x][y];
        if(t==0){
            viy[y]=1;
            if(match[y]==-1||find(match[y])){
                match[y]=x;
                return 1;
            }
        }else lack=min(lack,t);
    }
    return 0;
}
void KM(){
    memset(match,-1,sizeof match);
    fab(i,1,n)ly[i]=0;
    fab(i,1,n){
        lx[i]=-INF;
        fab(j,1,n)lx[i]=max(lx[i],w[i][j]);
    }
    fab(x,1,n){
        while(true){
            memset(vix,0,sizeof vix);
            memset(viy,0,sizeof viy);
            lack=INF;
            if(find(x))break;
            fab(i,1,n){
                if(vix[i])lx[i]-=lack;
                if(viy[i])ly[i]+=lack;
            }
        }
    }
}
/*bool dfs(int x){
    vix[x]=1;
    fab(y,1,n){
        if(viy[y])continue;
        int t=lx[x]+ly[y]-w[x][y];
        if(t==0){
            viy[y]=1;
            if(match[y]==-1||dfs(match[y])){
               match[y]=x;
               return 1;
            }
        }else slack[y]=min(slack[y],t);
    }
    return 0;
}
void KM(){
    memset(match,-1,sizeof match);
    fab(i,1,n)ly[i]=0;
    fab(i,1,n){
        lx[i]=-INF;
        fab(j,1,n){
            lx[i]=max(lx[i],w[i][j]);
        }
    }
    fab(x,1,n){
        fab(i,1,n)slack[i]=INF;
        while(true){
            memset(vix,0,sizeof vix);
            memset(viy,0,sizeof viy);
            if(dfs(x))break;
            int d=INF;
            fab(i,1,n)if(!viy[i]&&d>slack[i])d=slack[i];
            fab(i,1,n)if(vix[i])lx[i]-=d;
            fab(i,1,n)if(viy[i])ly[i]+=d;else slack[i]-=d;
        }
    }
}*/
void solve(){
    KM();
    int ans=0;
    fab(i,1,n){
        ans+=lx[i];
        if(i==n)pf("%d\n",lx[i]);
        else pf("%d ",lx[i]);
    }
    fab(i,1,n){
        ans+=ly[i];
        if(i==n)pf("%d\n",ly[i]);
        else pf("%d ",ly[i]);
    }
    pf("%d\n",ans);
}
int main(){
    while(~sf("%d",&n)){
        init();
        solve();
    }
    return 0;
}


