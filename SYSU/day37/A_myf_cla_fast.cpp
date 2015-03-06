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
const int maxn=55005;
const int maxm=8*maxn;
using namespace std;
struct cla {   
    struct Edge {
        int a, b, c, f;//from, to, c, flow;
        int xv(int u) { return u == a ? b : a; }//other
        int xf(int u) { return u == a ? c - f : f; }//limit
        void add(int u, int xf){ u == a ? f += xf : f -= xf; }
    } e[maxn*10];
    //  edge[maxn*maxn], * adj[maxn][maxn*2], *path[maxn];

    int n, m, up;
    int rn[maxn], p[maxn];
    vector<int> r[maxn];
    int h[maxn], cur[maxn];
    int hn[maxn*2], pre[maxn];

    void st(int x) {
        n=x;
        for(int i=0;i<=n;i++)rn[i]=0;
        for (int i = 0; i <= n; ++ i) r[i].clear();
        up = 0;
    }

    void addedge(int x, int y, int w) {
        e[up].a = x;
        e[up].b = y;
        e[up].c = w;
        //      r[x][rn[x]++] = up;
        //      r[y][rn[y]++] = up;
        r[x].push_back(up);
        r[y].push_back(up);
        ++ rn[x];
        ++ rn[y];
        up++;
    }

    void ch(int h0,int n) {   
        if (hn[h0] != 0) return;
        for (int i = 0; i < n; i++)
            if (h[i] > h0)
            {
                hn[h[i]]--;
                hn[n]++;
                h[i] = n;
            }
    }

    int maxflow(int s,int t) {
        int i, c = s, v, ex, flow = 0, oldh;
        fill(h,h+n+1,0);//memset
        fill(hn,hn+2*n+1,0);//memset 
        hn[0]=n;
        for(i=0;i<up;i++) e[i].f=0;
        for (i = 0; i < n; i++) cur[i] = rn[i] - 1;
        while (h[s] < n) {
            for (; cur[c] >= 0; cur[c]--){
                if (e[r[c][cur[c]]].xf(c)>0 && h[c]==h[e[r[c][cur[c]]].xv(c)]+1) break;
			}
            if (cur[c] >= 0) {
                v = e[r[c][cur[c]]].xv(c);
                pre[v] = c;
                p[v] = r[c][cur[c]];
                c = v;
                if (c == t) {
                    ex = INF;
                    for (; c != s; c = pre[c]){
                        ex = min(ex, e[p[c]].xf(pre[c]));
					}
                    for (c = t; c != s; c = pre[c]) {
                        e[p[c]].add(pre[c], ex);
					}
                    flow += ex;
                }
            }
            else {
                oldh = h[c];
                h[c] = n;
                for (i = 0; i < rn[c]; i++){
                    if (e[r[c][i]].xf(c) > 0){
                        h[c] = min(h[c], h[e[r[c][i]].xv(c)] + 1);
					}
				}
                cur[c] = rn[c] - 1;
                hn[oldh]--;
                hn[h[c]]++;
                if (c != s) c = pre[c];
                ch(oldh,n);
            }
        }
        return flow;
    }
}solver;
int n,m,ans;
int s,t;
void input(){
    s=0,t=n+m+1;
    solver.st(t+1);
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


