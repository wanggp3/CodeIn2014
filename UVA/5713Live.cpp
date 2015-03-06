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
#define X first
#define Y second
#define LL long long
const int N=1005;
using namespace std;
typedef pair<double,double>PII;
int n,e;
double ans,sum;
PII P[N];
double maxv[N][N];
bool used[N][N];
int f[N];
double People[N];
double sqr(double x){
    return x*x;
}
double dis(int i,int j){
    return sqrt(sqr(P[i].X-P[j].X)+sqr(P[i].Y-P[j].Y));
}
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
struct Edge{
    int u,v;
    double w;
    bool flag;
    bool operator<(const Edge& rhs)const{
        return w<rhs.w;
    }
}E[N*N];
void init(){
    ans=0;
    e=sum=0;
    rep(i,N)f[i]=i;
    memset(used,0,sizeof used);
    sf("%d",&n);
    rep(i,n){
        sf("%lf%lf%lf",&P[i].X,&P[i].Y,&People[i]);
    }
    rep(i,n){
        fab(j,i+1,n-1){
            E[e].u=i;
            E[e].v=j;
            E[e++].w=dis(i,j);
        }
    } 
}

void kruskal(){
   sort(E,E+e);
   rep(i,e){
       int fu=find(E[i].u),fv=find(E[i].v);
       if(fu!=fv){
          used[E[i].u][E[i].v]=used[E[i].v][E[i].u]=1;
          f[fu]=fv;
          E[i].flag=1;
          sum+=E[i].w;
       }else E[i].flag=0;
   }
}
void dfs(int root,int u,int fa){
   rep(v,n){
       if(used[u][v]&&v!=fa){
           maxv[root][v]=max(maxv[root][u],dis(u,v));
           dfs(root,v,u);
       }
   }
}
void solve(){
   kruskal();
   memset(maxv,0,sizeof maxv);
   rep(i,n){
       maxv[i][i]=0;
       dfs(i,i,i);
   }
   rep(i,e){
   //    pf("%d %d %d %d\n",E[i].flag,E[i].u,E[i].v,maxv[E[i].u][E[i].v]);
       if(E[i].flag){
           ans=max(ans,(People[E[i].u]+People[E[i].v])*1.0/(sum-E[i].w));
       }else{
           ans=max(ans,(People[E[i].u]+People[E[i].v])*1.0/(sum-maxv[E[i].u][E[i].v]));
       }
   }
   pf("%.2lf\n",ans);
}
int main(){
    int T;sf("%d",&T);
    while(T--){
        init();
        solve();
    }
    return 0;
}


