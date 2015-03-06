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
#define cls0(x) memset(x,0,sizeof(x))
#define cls1(x) memset(x,-1,sizeof(x))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1
#define LL long long 
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define sf scanf
#define pf printf 
const int N=10005;
using namespace std;
int n,ans1,ans2;
int d[N],cnt[N];
struct Edge{
    int v,w;
    Edge(int v=0,int w=0):v(v),w(w){
    }
};
vector<Edge>g[N];
void init(){
    cls0(d);
    cls0(cnt);
    rep(i,N)g[i].clear();
    ans1=-1;
    ans2=1;
}
void dfs(int u,int fa){
    d[u]=0;cnt[u]=1;
    int temp;
    rep(i,g[u].size()){
        int  v=g[u][i].v,w=g[u][i].w;
        if(v==fa)continue;
        dfs(v,u);
        temp=d[v]+w;
        if(temp+d[u]>ans1){
            ans1=temp+d[u];
            ans2=cnt[u]*cnt[v];
        }else if(temp+d[u]==ans1){
            ans2+=cnt[v]*cnt[u];
        }
        if(d[u]<temp){
            d[u]=temp;
            cnt[u]=cnt[v];
        }else if(d[u]==temp){
            cnt[u]+=cnt[v];
        }
    }
}
int main(){
    while(~sf("%d",&n)) {
        init();
        int u,v,w;
        rep(i,n-1){
            sf("%d%d%d",&u,&v,&w);
            g[u].PB(Edge(v,w));
            g[v].PB(Edge(u,w));
        }
        dfs(1,-1);
        pf("%d %d\n",ans1,ans2);
    }
    return 0;
}
