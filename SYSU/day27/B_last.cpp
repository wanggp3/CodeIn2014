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
const int N=15;
using namespace std;
char G[N][N];
int w[201][201];
int n,m,k;
int lx[201],ly[201];
bool vix[201],viy[201];
int linky[201];
int lack;
int X,Y;

bool find(int x){
    vix[x]=1;
    rep(y,Y){
        if(viy[y])continue;
        int t=lx[x]+ly[y]-w[x][y];
        if(t==0){
            viy[y]=1;
            if(linky[y]==-1||find(linky[y])){
                linky[y]=x;
                return 1;
            }
        }else lack=min(lack,t);
    }
    return 0;
}
void km(){
    memset(linky,-1,sizeof linky);
    memset(lx,0,sizeof lx);
    memset(ly,0,sizeof ly);
    rep(i,X){
        lx[i]=-INF;
        rep(j,Y){
            lx[i]=max(lx[i],w[i][j]);
        }
    }
    rep(x,X){
        while(true){
            memset(vix,0,sizeof vix);
            memset(viy,0,sizeof viy);
            lack=INF;
            if(find(x))break;
            rep(j,X){if(vix[j])lx[j]-=lack;
                     if(viy[j])ly[j]+=lack;}
        }
    }
    int ret=0;
    bool flag=0;
    rep(i,Y){
        if(linky[i]!=-1&&w[linky[i]][i]!=-INF)ret+=w[linky[i]][i];
        else flag=1;
    }
    if(flag)puts("-1");
    else pf("%d\n",ret);
}
/*bool path(int x){
    vix[x]=1;
    rep(y,Y){
        if(!viy[y]&&lx[x]+ly[y]==w[x][y]){
            viy[y]=1;
            if(linky[y]==-1||path(linky[y])){
                linky[y]=x;
                return 1;
            }
        }
    }
    return 0;
}
void KM(){
    memset(ly,0,sizeof ly);
    rep(i,X){
        lx[i]=-INF;
        rep(j,Y){
            lx[i]=max(lx[i],w[i][j]);
        }
    }
    memset(linky,-1,sizeof linky);
    rep(x,X){
        while(true){
            memset(vix,0,sizeof vix);
            memset(viy,0,sizeof viy);
            if(path(x))break;
            lack=INF;
            rep(j,Y){
                if(vix[j]){
                    rep(t,Y){
                        if(!viy[t])lack=min(lack,lx[j]+ly[t]-w[j][t]);
                    }
                }
            }
            rep(j,Y){
                if(vix[j])lx[j]-=lack;
                if(viy[j])ly[j]+=lack;
            }
        }
    }
    int ret=0;
    rep(x,X){
        if(linky[x]!=-1&&w[linky[x]][x]!=-INF)ret+=w[linky[x]][x];
        else {
            puts("-1");
            return;
        }
    }
    pf("%d\n",ret);
}*/
/*
int slack[1000]={0};
bool find_path(int x){
    vix[x]=1;
    rep(y,Y){
        if(viy[y])continue;
        if(lx[x]+ly[y]==w[x][y]){
            viy[y]=1;
            if(linky[y]==-1||find_path(linky[y])){
                linky[y]=x;
                return true;
            }
        }else slack[y]=min(slack[y],lx[x]+ly[y]-w[x][y]);
    }
    return false;
}
void km_ma(){
    rep(i,X){
        lx[i]=*max_element(w[i],w[i]+Y);
        ly[i]=0;
    }
    memset(linky,-1,sizeof linky);
    rep(x,X){
        memset(slack,-1,sizeof slack);
        //puts("fuck");
        while(true){
            //puts("fuck");
            memset(vix,0,sizeof vix);
            memset(viy,0,sizeof viy);
            if(find_path(x))break;
            else puts("fuckbreak");
            int sub=INF;
            rep(i,X){
                if(!viy[i])sub=min(sub,slack[i]);
            }
            rep(i,X)if(vix[i])lx[i]-=sub;
            rep(i,X){
                if(viy[i])ly[i]+=sub;
                else slack[i]-=sub;
            }
        }
    }
    int ret=0;
    rep(i,X){
        if(linky[i]!=-1&&w[linky[i]][i])ret+=w[linky[i]][i];
        else{
            puts("-1");
            return;
        }
    }
    pf("%d\n",ret);
}*/
void init(){
    sf("%d%d%d",&n,&m,&k);
    rep(i,n){
        sf("%s",G[i]);
    }
    rep(i,201)rep(j,201)w[i][j]=-INF;
    rep(i,k)w[i+n*m][i+n*m]=0;
    X=Y=n*m+k;
}
void solve(){
    rep(i,n){
        rep(j,m){
            rep(t,k){
                w[n*m+t][i*m+j]=w[i*m+j][n*m+t]=0;
            }
            for(int t=j+1;t<m;t++)w[i*m+j][i*m+t]=(G[i][j]==G[i][t]?G[i][j]-'0':0)-(t-j-1);
            for(int t=i+1;t<n;t++)w[i*m+j][t*m+j]=(G[i][j]==G[t][j]?G[i][j]-'0':0)-(t-i-1);
        }
    }
    //km();
    //KM();
    km_ma();
}
int main(){
    int T;sf("%d",&T);
    rep(cas,T){
        init();
        pf("Case %d : ",cas+1);
        solve();
    }
    return 0;
}
