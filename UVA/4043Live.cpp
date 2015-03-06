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
#define INF 1e10
#define MP make_pair
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define sf scanf
#define pf printf
#define LL long long
const int N=105;
using namespace std;
typedef pair<double,double>PII;
PII P[N];
int n;
int match[N];
double lx[N],ly[N],w[N][N],slack[N];
double lack;
const double eps = 1e-5;
bool vix[N],viy[N];
double sqr(double x){
    return x*x;
}
void init(){
    fab(i,1,n){
       sf("%lf%lf",&P[i].first,&P[i].second);
    }
    double x,y;
    fab(i,1,n){
        sf("%lf%lf",&x,&y);
        fab(j,1,n)w[i][j]=-sqrt(sqr(x-P[j].first)+sqr(y-P[j].second));
    }
}
/*
bool find(int x){
    vix[x]=1;
    fab(y,1,n){
        if(viy[y])continue;
        double t=lx[x]+ly[y]-w[x][y];
        if(fabs(t)<=eps){
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
}*/
bool dfs(int x){
    vix[x]=1;
    fab(y,1,n){
        if(viy[y])continue;
        double t=lx[x]+ly[y]-w[x][y];
        if(fabs(t)<=eps){
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
            double d=INF;
            fab(i,1,n)if(!viy[i]&&d>slack[i])d=slack[i];
            fab(i,1,n)if(vix[i])lx[i]-=d;
            fab(i,1,n)if(viy[i])ly[i]+=d;else slack[i]-=d;
        }
    }
}
void solve(){
    KM();
    fab(i,1,n)pf("%d\n",match[i]);
}
int main(){
    bool flag=0;
    while(~sf("%d",&n)){
        if(flag)puts("");
        flag=1;
        init();
        solve();
    }
    return 0;
}


