#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define X first
#include<cstring>
#define Cls(x) memset(x,0,sizeof x)
#define Y second
#include<algorithm>
const int N = 10000 + 10;
typedef pair<int,int> PII;
int n, k;
vector<PII> E[N];
int tot, top, mi, root;
int size[N], f[N];
int q[N];
bool use[N];

void getDist(int x, int dist, int fa){
    q[top++] = dist;
    rep(i, E[x].size()){
        int y = E[x][i].X, c = E[x][i].Y;
        if (use[y] || y == fa) continue;
        getDist(y, dist + c, x);
    }
}

int count(int x, int dist){
    int s = 0;
    top = 0;
    getDist(x, dist, -1);
    sort(q, q + top);
    for(int i = 0,j = top - 1; i <= j; i++){
        while(q[i] + q[j] > k && i < j) j--;
        if (i < j) s += j - i;
    }
    return s;
}

void getRoot(int x, int fa){
    int big = -1;
    size[x] = 1;
    rep(i, E[x].size()){
        int y = E[x][i].X, c = E[x][i].Y;
        if (use[y] || y == fa) continue;
        getRoot(y, x);
        size[x] += size[y];
        big=max(big, size[y]);
    }
    big = max(big, tot - size[x]);
    if (big < mi) mi = big, root = x;
}

void dfs(int x){
     tot = mi = size[x];
     getRoot(x, -1);
     x = root;
     f[x] = count(x, 0);
     use[x] = true;
     rep(i, E[x].size()){
         int y = E[x][i].X, c = E[x][i].Y;
         if (use[y]) continue;
         f[x] -= count(y, c);
         dfs(y);
     }
}
#define PB push_back
#define MP make_pair
int main(){
    while(scanf("%d%d", &n, &k)){
        if (!n && !k) break;
        Cls(use);
        int x,y,c;
        rep(i, n) E[i].clear();
        rep(i, n - 1){
            scanf("%d%d%d", &x, &y, &c);
            x--, y--;
            E[x].PB(MP(y, c));
            E[y].PB(MP(x, c));
        }
        size[0] = n;
        dfs(0);
        int ans = 0;
        rep(i,n) ans += f[i];
        printf("%d\n", ans);
    }
    return 0;
}
