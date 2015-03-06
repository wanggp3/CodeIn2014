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
const int N=205;
using namespace std;
typedef pair<int,int>PII;
int lx[N],ly[N],w[N][N],match[N],slack[N],n,m;
bool vix[N],viy[N];
void init(){
    fab(i,1,n)fab(j,1,n)w[i][j]=-INF;
}
void input(){
    fab(i,1,n){
        int u,v;
        while(sf("%d",&u)&&u){
            sf("%d",&v);
            w[i][u]=max(-v,w[i][u]);
        }
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
                return true;
            }
        }else slack[y]=min(slack[y],t);
    }
    return false;
}
void bug(){
    puts("bug");
    fab(i,1,n)pf("%d \n",match[i]);
}
void solve(){
    memset(match,-1,sizeof match);
    memset(ly,0,sizeof ly);
    fab(i,1,n){
        lx[i]=-INF;
        fab(j,1,n)lx[i]=max(lx[i],w[i][j]);
    }
    fab(x,1,n){
        fab(i,1,n)slack[i]=INF;
        while(true){
            memset(vix,0,sizeof vix);
            memset(viy,0,sizeof viy);
            int d=INF;
            if(find(x))break;
            fab(i,1,n)if(!viy[i]&&d>slack[i])d=slack[i];
            fab(i,1,n)if(vix[i])lx[i]-=d;
            fab(i,1,n)if(viy[i])ly[i]+=d;else slack[i]-=d;
        }
    }
    int ans=0;
    fab(i,1,n){
        if(match[i]==-1||w[match[i]][i]==-INF){
            puts("N");
            return;
        }else ans-=w[match[i]][i];
    }
    pf("%d\n",ans);
}
int main(){
    while(~sf("%d",&n)&&n){
        init();
        input();
        solve();
    }
    return 0;
}


