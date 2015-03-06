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
vector<int>G[N];
int col[N];
void init(){
    memset(col,0,sizeof col);
    rep(i,N)G[i].clear();
}
bool bip(int u){
    rep(i,G[u].size()){
        int v=G[u][i];
        if(col[v]==col[u])return false;
        if(!col[v]){
            col[v]=3-col[u];
            if(!bip(v))return false;
        }
    }
    return true;
}
void solve(){
    m=0;
    int u,v;
    while(~sf("%d%d",&u,&v)&&(u+v)){
        G[u].PB(v);
        G[v].PB(u);
        m++;
    }
    col[1]=1;
    if(n*3==2*m&&bip(1))puts("YES");
    else puts("NO");
}
int main(){
    while(~sf("%d",&n)&&n){
        init();
        solve();
    }
    return 0;
}


