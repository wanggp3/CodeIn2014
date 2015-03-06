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
const int N=555;
using namespace std;
typedef pair<int,int>PII;
int lx[N],ly[N],w[N][N],matchX[N],matchY[N],lack,m,n,X,Y;
bool vix[N],viy[N];
bool find(int x){
    vix[x]=1;
    fab(y,1,Y){
        if(viy[y])continue;
        int t=lx[x]+ly[y]-w[x][y];
        if(t==0){
            viy[y]=1;
            if(matchY[y]==-1||find(matchY[y])){
                matchY[y]=x;
                matchX[x]=y;
                return  true;
            }
        }else lack=min(lack,t);
    }
    return false;
}
int KM(){
    memset(matchX,-1,sizeof matchX);
    memset(matchY,-1,sizeof matchY);
    memset(lx,0,sizeof lx);
    memset(ly,0,sizeof ly);
    fab(i,1,X){
        lx[i]=-INF;
        fab(j,1,Y)lx[i]=max(lx[i],w[i][j]);
    }
    fab(x,1,X){
        while(true){
            memset(vix,0,sizeof vix);
            memset(viy,0,sizeof viy);
            lack=INF;
            if(find(x))break;
            fab(i,1,X)if(vix[i])lx[i]-=lack;
            fab(i,1,Y)if(viy[i])ly[i]+=lack;
        }
    }
    int ret=0;
    fab(i,1,X){
        if(matchY[i]!=-1)ret+=w[matchY[i]][i];
    }
    return ret;
}
int s[N],t[N],rsize[N];
void init(){
    
    Y=m*n;
    rep(i,m)sf("%d",&rsize[i]);
    rep(i,n){
        int k;sf("%d",&k);
        rep(j,k)sf("%d%d",&s[j],&t[j]);
        rep(r,m){
            int p=0;
            if(rsize[r]<s[0])continue;
            while(p+1<k&&s[p+1]<=rsize[r])p++;
            rep(j,n){
                w[i+1][r*n+j+1]=-(j+1)*t[p];
            }
        }
    }
    X=n*m;
    for(int i=n+1;i<=X;i++){
        fab(j,1,n*m){
            w[i][j]=1;
        }
    }
    /*fab(i,1,n){
        fab(j,1,n*m)pf("%d ",w[i][j]);pf("\n");
    }*/
}
void solve(){
    int ans=-KM();
    pf("%lf\n",ans*1.0/n);
}
int main(){
    while(~sf("%d%d",&m,&n)){
        init();
        solve();
    }
    return 0;
}


