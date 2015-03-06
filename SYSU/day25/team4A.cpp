// by team3
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cctype>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <complex>
#include <cassert>

using namespace std;

#define REP(i,n) for (int i = 0; i < (n); ++i)
#define FOR(i,s,t) for (int i = (s); i <= (t); ++i)
#define FOREACH(i,c) for (__typeof(c.begin()) i = c.begin(); i != c.end(); ++i)
#define foreach(i,c) for (__typeof(c.begin()) i = c.begin(); i != c.end(); ++i)

typedef long long LL;
typedef pair<int, int> Pii;

const int inf = 0x3f3f3f3f;
const LL infLL = 0x3f3f3f3f3f3f3f3fLL;

const int maxn = 18 + 5;

int n, vip;
int xl[maxn], yl[maxn], xr[maxn], yr[maxn];
int type[maxn];
int g[6][6];
map<LL, int> dis;
void print(){
    REP(i,6){
        REP(j,6)printf("%2d ",g[i][j]);puts("");
    }
}
int bfs()
{
    LL S = 0;
    for (int i = n - 1; i >= 0; --i)
        S = (S << 3) | (type[i] < 2? yl[i]: xl[i]);
    queue<LL> que;
    dis.clear();
    dis[S] = 0; que.push(S);
    while (!que.empty()) {
        S = que.front(); que.pop();
        int w = dis[S] + 1, p;
        LL t = S;
        memset(g, -1, sizeof(g));
        REP(i,n) {
            int d = i * 3;
            LL mask = 7LL << d;
            int l = (S & mask) >> d;
            if (type[i] < 2) {
                REP(j,2+type[i]) g[xl[i]][l+j] = i;
            } else {
                REP(j,type[i]) g[l+j][yl[i]] = i;
            }
            if (i == vip) p = l + type[i] + 2;
        }
        print();
        int TT;scanf("%d",&TT);
        bool ok = true;
        FOR(j,p,5) if (g[xl[vip]][j] != -1) {
            ok = false;
            break;
        }
        if (ok) return w;
        //REP(i,6) {
        //    REP(j,6) printf("%3d", g[i][j]);
        //    puts("");
        //}
        //puts("");
        REP(i,n) {
            int d = i * 3;
            LL mask = 7LL << d;
            int l = (S & mask) >> d;
            if (type[i] < 2) {
                FOR(j,1,6) {
                    int p = l + j - 1 + type[i] + 2;
                    if (p >= 6 || g[xl[i]][p] != -1) break;
                    LL T = (S & ~mask) | ((LL)(l + j) << d);
                    if (!dis.count(T)) {
                        que.push(T);
                        dis[T] = w;
                    }
                }
            } else {
                FOR(j,1,6) {
                    int p = l + j - 1 + type[i];
                    if (p >= 6 || g[p][yl[i]] != -1) break;
                    LL T = (S & ~mask) | ((LL)(l + j) << d);
                    if (!dis.count(T)) {
                        que.push(T);
                        dis[T] = w;
                    }
                }
            }
        }
        REP(i,n) {
            int d = i * 3;
            LL mask = 7LL << d;
            int l = (S & mask) >> d;
            if (type[i] < 2) {
                FOR(j,1,6) {
                    int p = l - j;
                    if (p < 0 || g[xl[i]][p] != -1) break;
                    LL T = (S & ~mask) | ((LL)(l - j) << d);
                    if (!dis.count(T)) {
                        que.push(T);
                        dis[T] = w;
                    }
                    --p;
                }
            } else {
                FOR(j,1,6) {
                    int p = l - j;
                    if (p < 0 || g[p][yl[i]] != -1) break;
                    LL T = (S & ~mask) | ((LL)(l - j) << d);
                    if (!dis.count(T)) {
                        que.push(T);
                        dis[T] = w;
                    }
                }
            }
        }
    }
    return -1;
}

int main()
{
    while (scanf("%d", &n) != EOF) {
        REP(i,n) {
            int id;
            scanf("%d", &id);
            scanf("%d%d%d%d", &yl[id], &xl[id], &yr[id], &xr[id]);
            if (xl[id] == xr[id]) {
                type[id] = (yr[id] - yl[id] == 1? 0: 1);
            } else {
                type[id] = (xr[id] - xl[id] == 1? 2: 3);
            }
        }
        scanf("%d", &vip);
        printf("%d\n", bfs());
    }

    return 0;
}
