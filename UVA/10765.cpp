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
const int N=10005;
using namespace std;
typedef pair<int,int>PII;
int pre[N],iscut[N],dfs_clock;
vector<int>G[N];
int dfs(int u,int fa){
    int lowu = pre[u] = ++dfs_clock;
    int child=0;
    rep(i,G[u].size()){
        int v=G[u][i];
        if(!pre[v]){
            child++;
            int lowv=dfs(v,u);
            lowu=min(lowu,lowv);
            if(lowv>=pre[u])iscut[u]++;
        }else if(pre[v]<pre[u] && v!=fa ){
            lowu=min(lowu,pre[v]);
        }
    }
    if(fa<0 && child==1) iscut[u]=0;
    return lowu;
}
struct Node{
    int px,val;
}ans[N];
void init(int n){
    rep(i,n){
        G[i].clear();
        ans[i].px=i;
    }
    memset(pre,0,sizeof pre);
    memset(iscut,0,sizeof iscut);
    dfs_clock=0;
}
bool cmp(Node a,Node b){
    if(a.val==b.val)return a.px<b.px;
    return a.val > b.val;
}
int main(){
    int n,m,u,v;
    while(sf("%d%d",&n,&m)&&(n+m)){
        init(n);
        while(sf("%d%d",&u,&v)){
            if(u==-1&&v==-1)break;
            G[u].PB(v);
            G[v].PB(u);
        }
        dfs(0,-1);
        if(iscut[0]==0)ans[0].val=1;
        for(int i=1;i<n;i++){
            if(iscut[i]==0)ans[i].val=1;
            else ans[i].val= ++iscut[i];
        }
        sort(ans,ans+n,cmp);
        rep(i,m)pf("%d %d\n",ans[i].px,ans[i].val);pf("\n");
    }
    return 0;
}


