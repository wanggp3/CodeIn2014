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
const int N=155;
const double eps= 1e-8;
using namespace std;
typedef pair<int,int>PII;
int n,m;
double C[N][N],T[N][N],d[N];
int fa[N];
int cnt[N];
bool inq[N];
void init(){
    rep(i,N){
        rep(j,N)C[i][j]=T[i][j]=0;
        d[i]=cnt[i]=inq[i]=0;
    }
}
void input(){
    rep(i,m){
        int u,v;
        double c,t;
        sf("%d%d%lf%lf",&u,&v,&c,&t);
        C[u][v]=c;T[u][v]=t;
    }
}
queue<int>Q;
int ans[N];
int tot;
int ok(double x){
    while(!Q.empty())Q.pop();
    fab(i,1,n){
        //Q.push(i);
        fa[i]=i;
        cnt[i]=0;
        d[i]=INF;
        inq[i]=0;
    }
    Q.push(1);
    inq[1]=1;
    d[1]=0;
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        inq[u]=0;
        fab(v,1,n){
            if(C[u][v]<eps)continue;
            //pf("from u to v : %d %d\n",u,v);
            double w=x*T[u][v]-C[u][v];
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                fa[v]=u;
                if(!inq[v]){
                    Q.push(v);
                    inq[v]=1;
                    if(++cnt[v]>n){
                        return v;
                    }
                }
            }
        }
    }
    return 0;
}
void solve(){
    if(!ok(0)){
        puts("0");
        return;
    }
    double L=eps,R=101,M;
    while(L+eps<R){
        //pf("%lf %lf %lf %lf\n",L,R,R-L,eps);
        M=(L+R)/2.0;
        if(ok(M))L=M;
        else R=M;
    }
    int u=ok(R-eps);
    int v=fa[u];
    //pf(" v = %d\n",v);
    tot=0;
    ans[tot++]=u;;
    while(v!=u){
        //cout<<v<<endl;
        ans[tot++]=v;
        v=fa[v];
    }
    pf("%d\n",tot);
    for(int i=tot-1;i>=0;i--)//if(i==0)pf("%d\n",ans[i]);
    pf("%d ",ans[i]);pf("\n");
}
int main(){
    while(sf("%d%d",&n,&m)==2){
        init();
        input();
        solve();
    }
    return 0;
}


