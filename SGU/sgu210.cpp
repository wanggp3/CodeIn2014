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
const int N=555;
using namespace std;
typedef pair<int,int>PII;
int n;
bool g[N][N];
int match[N];
int ans[N];
bool vis[N];
struct Node{
    int id,v;
    Node(int id=0,int v=0):id(id),v(v){}
    bool operator<(const Node& rhs)const{
        return v>rhs.v;
    }
}node[N];
void init(){
    memset(g,0,sizeof g);
}
void input(){
    fab(i,1,n){
        sf("%d",&node[i].v);
        node[i].id=i;
    }
    fab(i,1,n){
        int k,x;
        sf("%d",&k);
        while(k--){
            sf("%d",&x);
            g[i][x]=1;
        }
    }
}
bool find(int x){
    fab(y,1,n){
        if(g[x][y]&&!vis[y]){
            vis[y]=1;
            if(match[y]==0||find(match[y])){
                match[y]=x;
                return true;
            }
        }
    }
    return false;
}
void bug(){
    puts("bug");
    fab(i,1,n)pf("%d %d\n",node[i].id,node[i].v);
}
void solve(){
    memset(match,0,sizeof match);
    sort(node+1,node+n+1);
    fab(i,1,n){
        memset(vis,0,sizeof vis);
        find(node[i].id);
    }
    memset(ans,0,sizeof ans);
    fab(i,1,n)if(match[i]!=0)ans[match[i]]=i;
    fab(i,1,n)if(i==n)pf("%d\n",ans[i]);else pf("%d ",ans[i]);
}
int main(){
    while(~sf("%d",&n)){
        init();
        input();
        solve();
    }
    return 0;
}


