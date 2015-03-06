#include<iostream>
#include<cstring>
#include<stdio.h>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<iomanip>
#include<cmath>
#include<list>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)
#define fab(i,a,b) for(int i=(a);i<=(b);i++)
#define fba(i,b,a) for(int i=(b);i>=(a);i--)
#define cls(x) memset(x,0,sizeof(x))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define LL long long 
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define sf scanf
#define pf printf 
const int N=1005;
using namespace std;
int n;
vector<int>G[N];
vector<int>ans;
int size[N];
int root;
int root_size=INF;
int dfs1(int u,int fa){
    size[u]=1;
    int maxson=1;
    rep(i,G[u].size()){
        int v=G[u][i];
        if(v==fa)continue;
        int tmp=dfs1(v,u);
        size[u]+=tmp;
        maxson=max(maxson,tmp);
    }
    maxson=max(maxson,n-size[u]);
    if(maxson<root_size){
        root_size=maxson;
        ans.clear();
        ans.PB(u);
    }
    else if(maxson==root_size){
        ans.PB(u);
    }
    return size[u];
}
void solve(){
    root=1;
    dfs1(1,1);
    rep(i,ans.size())
    pf("root is %d\n",ans[i]);
}
int main(){
    sf("%d",&n);
    rep(i,n-1){
        int u,v;
        sf("%d%d",&u,&v);
        G[u].PB(v);
        G[v].PB(u);
    }
    solve();
    return 0;
}

