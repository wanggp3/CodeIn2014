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
int low[N],pre[N],iscut[N];
int ck=0;
void dfs(int u,int fa){
    low[u]=pre[u]=++ck;
    int child=0;
    rep(i,G[u].size()){
        int v=G[u][i];
        if(!pre[v]){
            dfs(v,u);
            child++;
            low[u]=min(low[u],low[v]);
            if(low[v]>=pre[u])iscutpoint[u]=1;
            if(low[v]>pre[u])iscutedge[G[u][i].id]=1;
        }else if(v!=fa&&pre[v]<pre[u]){ // fa!=v->low[u]=min(low[u],low[v]);
            low[u]=min(low[u],low[v]);
        }
    }
    if(child==1&&fa<0)iscur[u]=0;
}

int main(){
    
    return 0;
}

