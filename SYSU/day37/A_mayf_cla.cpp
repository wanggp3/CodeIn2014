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
const int N=55005;
const int E=N*8;
using namespace std;
struct Cla{
struct Edge{
int t, u;
Edge *nx, *op;
}*e[N], mem[E], *C;
int n, S, T;
int vh[N], h[N];
void init(int num){
n = num;
C = mem;
rep(i, n) e[i] = NULL;
}
void addedge(int u, int v, int c){
C->t = v, C->u = c, C->nx = e[u], e[u] = C++;
C->t = u, C->u = 0, C->nx = e[v], e[v] = C++;
e[u]->op = e[v];
e[v]->op = e[u];
}
int aug(int p, int m){
if (p == T) return m;
int d = m;
for(Edge *i = e[p]; i; i = i->nx){
if (i->u && h[p] == h[i->t] + 1){
int f = aug(i->t, min(i->u, d));
i->u -= f, i->op->u += f, d-= f;
if (h[S] == n || !d) return m - d;
}
}
int w = d < m ? min(n, h[p] + 2) : n;
for(Edge *i = e[p]; i; i = i->nx){
if (i->u) w = min(w, h[i->t] + 1);
}
++vh[w];
--vh[h[p]] ? h[p] = w : h[S] = n;
return m - d;
}
int maxflow(int s, int t){
S = s, T = t;
rep(i, n) vh[i] = 0, h[i] = 0;
vh[0] = n;
int ret = 0;
while(h[S] != n) ret += aug(S, INF);
return ret;
}
}solver;
int n,m,ans;
int s,t;
void input(){
    s=0,t=n+m+1;
    solver.init(t+1);
    int x;
    fab(i,1,n){
        sf("%d",&x);
        solver.addedge(m+i,t,x);
    }
    int u,v,w;
    ans=0;
    fab(i,1,m){
        sf("%d%d%d",&u,&v,&w);
        ans+=w;
        solver.addedge(s,i,w);
        solver.addedge(i,m+u,INF);
        solver.addedge(i,m+v,INF);
    }
}
void solve(){
    pf("%d\n",ans-solver.maxflow(s,t));
}
int main(){
    while(~sf("%d%d",&n,&m)){
        input();
        solve();
    }
    return 0;
}


