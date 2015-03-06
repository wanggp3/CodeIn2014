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
const int N=505;
using namespace std;
typedef pair<int,int>PII;

int n,m;
char g[N][N];
int bx[N*N],by[N*N],id[N][N];
int head[N*N],next[360000],to[N*N];
int match[N*N],vis[N*N];
int ID,e;
void init(){
    e=0;
    memset(head,-1,sizeof head);
}
void addedge(int u,int v){
    to[e]=v;next[e]=head[u];head[u]=e++;
}
bool dfs(int x){
    for(int i=head[x];~i;i=next[i]){
        int y=to[i];
        if(vis[y]!=ID){
            vis[y]=ID;
            if(match[y]==-1||dfs(match[y])){
                match[y]=x;
                return true;
            }
        }
    }
    return false;
}
bool hungry(int B,int W){
    memset(match,-1,sizeof match);
    memset(vis,0,sizeof vis);
    ID=0;
    fab(i,1,B){
        ++ID;
        //memset(vis,0,sizeof vis);
        if(!dfs(i))return false;
    }
    return true;
}
void solve(){
    sf("%d%d",&n,&m);
    fab(i,1,n){
        sf("%s",g[i]+1);
    }
    int B=0,W=0;
    fab(i,1,n){
        fab(j,1,m){
            if(g[i][j]=='B')bx[++B]=i,by[B]=j;
            else if(g[i][j]=='W')id[i][j]=++W;
        }
    }
    if(2*B!=W){
        puts("NO");
        return;
    }
    fab(b,1,B){
        int i=bx[b],j=by[b];
        if(g[i-1][j]=='W')addedge(b,id[i-1][j]);
        if(g[i+1][j]=='W')addedge(b,id[i+1][j]);
        if(g[i][j-1]=='W')addedge(b+B,id[i][j-1]);
        if(g[i][j+1]=='W')addedge(b+B,id[i][j+1]);
    }
    if(hungry(B*2,W))puts("YES");
    else puts("NO");
}
int main(){
    int T;sf("%d",&T);
    while(T--){
        init();
        solve();
    }
    return 0;
}


