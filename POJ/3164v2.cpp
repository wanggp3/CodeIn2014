#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stdio.h>

#define rep(i,n) for(int i=0;i<n;++i)
#define fab(i,a,b) for(int i=a;i<=b;++i)
#define fba(i,b,a) for(int i=b;i>=a;--i)
//#define INF 0x3f3f3f3f
const double INF=1e20;
#define sf scanf
#define pf printf
#define LL long long
const int N=109;
using namespace std;
//pair<double,double>P[N];
struct point{
    double X,Y;
    void in(){
        sf("%lf%lf",&X,&Y);
    }
}P[N];
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
double Directed_MST(int root,int NV,int NE) {
	double ret = 0;
	while(true) {
		//1.找最小入边
		rep(i,NV) In[i] = INF;
		rep(i,NE) {
			int u = E[i].u;
			int v = E[i].v;
			if(E[i].w < In[v]  &&  u != v) {
				pre[v] = u;
				In[v] = E[i].w;
			}
		}
		rep(i,NV) {
			if(i == root) continue;
			if(In[i] == INF)	return -1;//除了跟以外有点没有入边,则根无法到达它
		}
		//2.找环
		int cntnode = 0;
		memset(ID,-1,sizeof ID);
        memset(vis,-1,sizeof vis);
		In[root] = 0;
		rep(i,NV) {//标记每个环
			ret += In[i];
			int v = i;
			while(vis[v] != i && ID[v] == -1 && v != root) {
				vis[v] = i;
				v = pre[v];
			}
			if(v != root && ID[v] == -1) {
				for(int u = pre[v] ; u != v ; u = pre[u]) {
					ID[u] = cntnode;
				}
				ID[v] = cntnode ++;
			}
		}
		if(cntnode == 0)	break;//无环
		rep(i,NV) if(ID[i] == -1) {
			ID[i] = cntnode ++;
		}
		//3.缩点,重新标记
		rep(i,NE) {
			int v = E[i].v;
			E[i].u = ID[E[i].u];
			E[i].v = ID[E[i].v];
			if(E[i].u != E[i].v) {
				E[i].w -= In[v];
			}
		}
		NV = cntnode;
		root = ID[root];
	}
	return ret;
}
int main(){
    while(sf("%d%d",&n,&m)!=EOF){
        rep(i,n){
            //sf("%lf%lf",&P[i].X,&P[i].Y);
            P[i].in();
        }
        int e=0;
        rep(i,m){
            /*
            sf("%d%d",&E[i].u,&E[i].v);
            E[i].v--;
            E[i].u--;
            if(E[i].u!=E[i].v)E[i].w=dis(E[i].u,E[i].v);
            else E[i].w=INF;*/
            int u,v;sf("%d%d",&u,&v);
            if(u==v)continue;
            u--;v--;
            E[e].u=u;E[e].v=v;
            E[e++].w=dis(u,v);
        }
        double ans=Directed_MST(0,n,e);
        if(ans<0)puts("poor snoopy");
        else pf("%.2lf\n",ans+ (1e-8) );
    }
    return 0;
}



