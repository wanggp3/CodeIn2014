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
const int N=20005;
using namespace std;
int fa[N],d[N];
int n;
void init(){
  rep(i,N){
      fa[i]=i;
      d[i]=0;
  }
}
int find(int x){
    if(fa[x]==x)return x;
    else{
        int ret=find(fa[x]);
        d[x]+=(d[fa[x]]);
        fa[x]=ret;
        return ret;
    }
}
void solve(){
    sf("%d",&n);
    char op[2];
    int a,b;
    while(sf("%s",op)&&op[0]!='O'){
        if(op[0]=='E'){
            sf("%d",&a);
            find(a);
            pf("%d\n",d[a]);
        }else if(op[0]=='I'){
            sf("%d%d",&a,&b);
            d[a]=abs(a-b)%1000;
            fa[a]=b;
        }
    }
}
int main(){
    int T;sf("%d",&T);
    while(T--){
        init();
        solve();
    }
    return 0;
}

