#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include <iostream>
#define eps 1e-8
using namespace std;
/*
最小树形图图模版-朱刘算法
模版说明：点标号必须0-(N-1)
		 必须去除到自身的点（到自身的边的边权赋无限大）
*/
#define M 109
#define type long long 
#define rep(i,n) for(int i=0;i<n;i++)
#define sf scanf
#define pf printf
#define fab(i,a,b) for(int i=a;i<=b;i++)
const type inf=0x3f3f3f3f3f3f3f;
struct Node{
	int u , v;
	type cost;
}E[M*M],G[M*M];
int pre[M],ID[M],vis[M];
type In[M];
type Directed_MST(int root,int NV,int NE) {
	type ret = 0;
	while(true) {
		//1.找最小入边
		for(int i=0;i<NV;i++) In[i] = inf;
		for(int i=0;i<NE;i++){
			int u = E[i].u;
			int v = E[i].v;
			if(E[i].cost < In[v] && u != v) {
				pre[v] = u;
				In[v] = E[i].cost;
			}
		}
		for(int i=0;i<NV;i++) {
			if(i == root) continue;
			if(In[i] == inf)	return -1;//除了跟以外有点没有入边,则根无法到达它
		}
		//2.找环
		int cntnode = 0;
	memset(ID,-1,sizeof(ID));
	memset(vis,-1,sizeof(vis));
		In[root] = 0;
		for(int i=0;i<NV;i++) {//标记每个环
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
		for(int i=0;i<NV;i++) if(ID[i] == -1) {
			ID[i] = cntnode ++;
		}
		//3.缩点,重新标记
		for(int i=0;i<NE;i++) {
			int v = E[i].v;
			E[i].u = ID[E[i].u];
			E[i].v = ID[E[i].v];
			if(E[i].u != E[i].v) {
				E[i].cost -= In[v];
			}
		}
		NV = cntnode;
		root = ID[root];
	}
	return ret;
}
int n,m,C,e;
int bit[M*M+60];
void init(){
    sf("%d%d%d",&n,&m,&C);
    rep(i,m){
        sf("%d%d%d%lld",&G[i].u,&G[i].v,&bit[i],&G[i].cost);
    }
}
int cas=1;
void solve(){
    pf("Case %d: ",cas++);
    int R=0;
    rep(i,m){
        E[i].u=G[i].u;
        E[i].v=G[i].v;
        E[i].cost=G[i].cost;
        R=max(R,bit[i]);
    }
    type ans=Directed_MST(0,n,m);
    if(ans==-1||ans>C)puts("impossible");
    else{
        int L=1,mid;
        R++;
        while(L+1<R){
            mid=L+(R-L)/2;
            e=0;
            rep(i,m){
                if(bit[i]>=mid){
                   E[e].u=G[i].u;
                   E[e].v=G[i].v;
                   E[e].cost=G[i].cost;
                   e++;
                }
            }
            ans=Directed_MST(0,n,e);
            if(ans!=-1&&ans<=C)L=mid;
            else R=mid;
        }
        pf("%d kbps\n",L);
    }
}
int main(){
    int T;sf("%d",&T);
    while(T--){
        init();
        solve();
    }
    return 0;
}
