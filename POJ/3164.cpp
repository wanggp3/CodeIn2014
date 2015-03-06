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
#define INF 1e20
#define MP make_pair
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define sf scanf
#define pf printf
#define LL long long
#define X first
#define Y second
const int N=105;
using namespace std;
typedef pair<int,int>PII;
pair<double,double>P[N];
struct Edge{
    int u,v;
    double w;
}E[N*N];
double sqr(double x){
    return x*x;
}
double dis(int i,int j){
   return sqrt(sqr(P[i].X-P[j].X)+sqr(P[i].Y-P[j].Y));
}

int n,m;
int pre[N],ID[N],vis[N];
double In[N];
//n: point   ;  m:edge 
double MST(int root){
    double ret=0;
    while(true){
        rep(i,n)In[i]=INF;
        rep(i,m){
            int u=E[i].u,v=E[i].v;
            if(E[i].w<In[v]&&v!=u){
                pre[v]=u;
                In[v]=E[i].w;
            }
        }
        rep(i,n){
            if(i==root)continue;
            if(In[i]==INF)return -1;
        }
        int cntnode=0;
        rep(i,n){
            vis[i]=ID[i]=-1;
        }
        In[root]=0;
        rep(i,n){
            ret+=In[i];
            int v=i;
            while(vis[v]!=i&&ID[v]==-1&&v!=root){
                vis[v]=i;
                v=pre[v];
            }
            if(v!=root&&ID[v]==-1){
                for(int u=pre[v];u!=v;u=pre[u])ID[u]=cntnode;
                ID[v]=cntnode++;
            }
        }
        if(cntnode==0)break;
        rep(i,n){
          if(ID[i]==-1)ID[i]=cntnode++;
        }
        rep(i,m){
            int v=E[i].v;
            E[i].u=ID[E[i].u];
            E[i].v=ID[E[i].v];
            if(E[i].u!=E[i].v)E[i].w-=In[v];
        }
        n=cntnode;
        root=ID[root];
    }
    return ret;
}

int main(){
    while(~sf("%d%d",&n,&m)){
        rep(i,n){
            sf("%lf%lf",&P[i].X,&P[i].Y);
        }
        rep(i,m){
            sf("%d%d",&E[i].u,&E[i].v);
            E[i].v--;
            E[i].u--;
            if(E[i].u!=E[i].v)E[i].w=dis(E[i].u,E[i].v);
            else E[i].w=INF;
        }
        double ans=MST(0);
        if(ans<0)puts("poor snoopy");
        else pf("%.2lf\n",ans);
    }
    return 0;
}


