//By skyler
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define sf scanf
#define pf printf
typedef pair<int, int> PII;
typedef pair<PII, PII> PPP;
const int N = 150000;
int d2[N], sz[N], n, m, cnt;
double d1[N], amp[N];
vector<PPP> q;
vector<int> Y;
map<PII, int> mp;
map<int, int> my;
struct Point {
    int x, y, flag;
    double val;
}p[N];

bool comp(Point a, Point b) {
    if (a.x!=b.x) return a.x<b.x;
    if (a.y!=b.y) return a.y<b.y;
    if (a.flag!=b.flag) return a.flag>b.flag;
}

void add(int x, int y, double val, int flag) {
    p[cnt].x = x;
    p[cnt].y = y;
    p[cnt].val = val;
    p[cnt++].flag = flag;
}

void update(int cur) {
    int x = my[p[cur].y];
    double val = p[cur].val;
    while (x<=Y.size()) {
        d1[x] += val;
        d2[x]++;
        x += x&-x;
    }
}

void query(int cur) {
    int x = my[p[cur].y];
    while (x) {
        amp[cur] += d1[x];
        sz[cur] += d2[x];
        x -= x&-x;
    }
}

void query(double& ans1, int& ans2, PII a, PII b) {
    int ld = mp[MP(a.F-1, a.S-1)], ru = mp[b];
    int lu = mp[MP(a.F-1, b.S)], rd = mp[MP(b.F, a.S-1)];
    ans1 = amp[ru]+amp[ld]-amp[lu]-amp[rd];
    ans2 = sz[ru]+sz[ld]-sz[lu]-sz[rd];
}

void init() {
    cnt = 0;
    Y.clear();
    rep(i, n) {
        int x, y;
        double val;
        sf("%d%d%lf", &x, &y, &val);
        add(x, y, val, 1);
        Y.PB(y);
    }
    q.clear();
    rep(i, m) {
        int x1, y1, x2, y2;
        sf("%d%d%d%d", &x1, &y1, &x2, &y2);
        q.PB(MP(MP(x1, y1), MP(x2, y2)));
        add(x1-1, y1-1, 0, 0);
        add(x1-1, y2, 0, 0);
        add(x2, y1-1, 0, 0);
        add(x2, y2, 0, 0);
        Y.PB(y1-1); Y.PB(y2);
    }
    sort(Y.begin(), Y.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());
    my.clear();
    rep(i, Y.size()) {
        my[Y[i]] = i+1;
        d1[i+1] = d2[i+1] = 0;
    }
    sort(p, p+cnt, comp);
    mp.clear();
    rep(i, cnt) {
        mp[MP(p[i].x, p[i].y)] = i;
        amp[i] = 0;
        sz[i] = 0;
    }
    rep(i, cnt) {
        if (p[i].flag==1) {
            update(i);
        }
        else {
            query(i);
        }
    }
}

void solve() {
    rep(i, q.size()) {
        PPP tmp = q[i];
        double ans1 = 0;
        int ans2 = 0;
        query(ans1, ans2, q[i].F, q[i].S);
        pf("%.2lf/%d\n", ans1, ans2);
    }
}

int main() {
    while (~sf("%d%d", &n, &m)) {
        init();
        solve();
    }
    return 0;
}
