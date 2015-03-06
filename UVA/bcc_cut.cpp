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
struct Edge{
    int u,v;
    Edge(int u=0,int v=0):u(u),v(v){}
};
stack<Edge>S;
int pre[N],low[N],bccno[N],dfs_clock,bcc_cnt;
vector<int>bcc[N];
void dfs(int u,int fa){
    low[u]=pre[u]=++dfs_clock;
    int child=0;
    rep(i,G[u].size()){
        int v=G[u][i];
        Edge e=Edge(u,v);
        if(!pre[v]){
            S.push(e);
            child++;
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=pre[u]){
                iscut[u]=1;
                bcc_cnt++;
                while(1){
                    Edge x=S.top();S.pop();
                    if(bccno[x.u]!=bcc_cnt){
                        bcc[bcc_cnt].PB(x.u);
                        bccno[x.u]=bcc_cnt;
                    }
                    if(bccnp[x.v]!=bcc_cnt){
                        bcc[bcc_cnt].PB(x.v);
                        bccno[x.v]=bcc_cnt;
                    }
                    if(x.u==u&&x.v==v)break;
                }
            }else if(fa!=v&&pre[v]<pre[u]){
                S.push(e);
                low[u]=min(low[u],pre[v]);
            }
            if(fa<0&&child==1)iscut[u]=0;
        }
    }
}
void find_bcc(){
    dfs_clock=bcc_cnt=0;
    rep(i,n){
        if(!pre[i]){
            dfs(i,-1);
        }
    }
}
int main(){

    return 0;
}
