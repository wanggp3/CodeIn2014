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
const int N=105;
using namespace std;
typedef pair<int,int>PII;
#define type double
const type inf = 1e20;
#define eps 1e-8
struct Edge{
    int u,v;
    type cost;
}E[N*N+10];
int pre[N],ID[N],vis[N];
type In[N];
type MST(int root,int n,int m){
    type ret=0;
    while(true){
        rep(i,n)In[i]=inf;
        rep(i,m){
            int u=E[i].u;
            int v=E[i].v;
            if(E[i].cost < In[v] && u!=v ){
                pre[v]=u;
                In[v]=E[i].cost;
            }
        }
        rep(i,n){
            if(i==root)continue;
            if(In[i]==inf)return -1;
        }
        int cntnode=0;
        memset(ID,-1,sizeof ID);
        memset(vis,-1,sizeof vis);
        In[root]=0;
        rep(i,n){
            ret+=In[i];
            int v=i;
            while(vis[v]!=i&&ID[v]==-1&&v!=root){
                vis[v]=i;
                v=pre[v];
            }
            if(v!=root&&ID[v]==-1){
                for(int u=pre[v];u!=v;u=pre[u]){
                    ID[u]=cntnode;
                }
                ID[v]=cntnode++;
            }
        }
        if(cntnode==0)break;
        rep(i,n)if(ID[i]==-1)ID[i]=cntnode++;
        rep(i,m){
            int v=E[i].v;
            E[i].u=ID[E[i].u];
            E[i].v=ID[E[i].v];
            if(E[i].u!=E[i].v)E[i].cost-=In[v];
        }
        n=cntnode;
        root=ID[root];
    }
    return ret;
}
int n,m;
struct Point{
    double x,y;
    void in(){
        sf("%lf%lf",&x,&y);
    }
}p[N];
double dis(Point a,Point b){
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


