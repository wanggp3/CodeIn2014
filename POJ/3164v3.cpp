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
#define MP make_pair
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define sf scanf
#define pf printf
#define LL long long
#define eps 1e-8
const int N=109;
using namespace std;
const double INF=1e20;
typedef pair<int,int>PII;
struct Edge{
    int u,v;
    double cost;
}E[N*N+5];
int pre[N],ID[N],vis[N];
double IN[N];
double MST(int root,int n,int m){
    double ret=0;
    while(true){
        rep(i,n)IN[i]=INF;
        rep(i,m){
            int u=E[i].u;
            int v=E[i].v;
            if(E[i].cost < IN[v] && u!=v){
                pre[v]=u;
                IN[v]=E[i].cost;
            }
        }
        rep(i,n){
            if(i==root)continue;
            if(IN[i]==INF)return -1;
        }
        int cnt=0;
        memset(ID,-1,sizeof ID);
        memset(vis,-1,sizeof vis);
        IN[root]=0;
        rep(i,n){
            ret+=IN[i];
            int v=i;
            while(vis[v]!=i && ID[v]==-1 && v!=root){
                vis[v]=i;
                v=pre[v];
            }
            if(v!=root && ID[v]==-1){
                for(int u=pre[v];u!=v;u=pre[u]){
                    ID[u]=cnt;
                }
                ID[v]=cnt++;
            }
        }
            if(!cnt)break;
            rep(i,n){
                if(ID[i]==-1)ID[i]=cnt++;
            }
            rep(i,m){
                int v=E[i].v;
                E[i].u=ID[E[i].u];
                E[i].v=ID[E[i].v];
                if(E[i].u!=E[i].v)E[i].cost-=IN[v];
            }
            n=cnt;
            root=ID[root];
     }
    return ret;
}
int n,m;
struct point{
    double x,y;
    void in(){
        sf("%lf%lf",&x,&y);
    }
}p[N];
double dis(point a,point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void init(){
    rep(i,n)p[i].in();
    int h=0;
    rep(i,m){
        int x,y;
        sf("%d%d",&x,&y);
        if(x==y)continue;
        x--;y--;
        E[h].u=x;
        E[h].v=y;
        E[h++].cost=dis(p[x],p[y]);
    }
    double ans=MST(0,n,h);
    if(ans<0)puts("poor snoopy");
    else pf("%.2lf\n",ans+eps);
}
int main(){
    while(sf("%d%d",&n,&m)!=EOF){
        init();
    }
    return 0;
}
