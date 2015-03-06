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
const int N=35;
using namespace std;
LL a[N][1<<11],b[N][1<<11];
bool g[N][N];
int n,m,p,q;
void init(){
    cls0(a);
    cls0(b);
    rep(i,N)rep(j,N)g[i][j]=1;
}
LL solve(){
    a[0][0]=b[0][0]=1;
    rep(i,n){
        for(int j=0;j<(1<<m);j++){
            if(a[i][j]==0)continue;
            for(int k=1;k<=m;k++){
                if(!(j&(1<<(k-1)))&&g[i+1][k+n])
                    a[i+1][j|(1<<(k-1))]+=a[i][j];
            }
        }
    }
    rep(i,p){
        for(int j=0;j<(1<<m);j++){
            if(b[i][j]==0)continue;
            b[i+1][j]+=b[i][j];
            for(int k=1;k<=m;k++){
                if(!(j&(1<<(k-1)))&&g[i+1+n+m][k+n])
                    b[i+1][j|(1<<(k-1))]+=b[i][j];
            }
        }
    }
   LL ret=0;
   for(int i=0;i<(1<<m);i++)ret+=a[n][i]*b[p][i];
   return ret;
}
int main(){
    while(~sf("%d %d %d",&n,&m,&p)){
        sf("%d",&q);
        init();
        rep(i,q){
            int u,v;
            sf("%d %d",&u,&v);
            g[u][v]=g[v][u]=0;
        }
        pf("%lld\n",solve());
    }
    return 0;
}
