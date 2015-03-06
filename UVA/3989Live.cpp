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
const int N=1005;
using namespace std;
typedef pair<int,int>PII;
int n;
int pre[N][N],order[N][N],next[N],matchX[N],matchY[N];
queue<int>Q;
void init(){
    while(!Q.empty())Q.pop();
}
void input(){
    sf("%d",&n);
    fab(i,1,n){
        fab(j,1,n)sf("%d",&pre[i][j]);
        next[i]=1;
        matchX[i]=0;
        Q.push(i);
    }
    fab(i,1,n){
        fab(j,1,n){
            int x;sf("%d",&x);
            order[i][x]=j;
        }
        matchY[i]=0;
    }
}
void Marry(int u,int v){
    int m=matchY[v];
    if(m){
        matchX[m]=0;
        Q.push(m);
    }
    matchX[u]=v;
    matchY[v]=u;
}
void solve(){
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        int v=pre[u][next[u]++];
        if(!matchY[v])Marry(u,v);
        else if(order[v][u]<order[v][matchY[v]])Marry(u,v);
        else Q.push(u);
    }
    fab(i,1,n)pf("%d\n",matchX[i]);
}
int main(){
    int T;sf("%d",&T);
    int cas=0;
    while(T--){
        if(cas)puts("");
        cas=1;
        init();
        input();
        solve();
    }
    return 0;
}


