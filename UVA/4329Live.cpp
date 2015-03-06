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
#define lowbit(x) x&-x
const int N=20005;
using namespace std;
int n;
int a[N],b[N],c[N],C[100005];
int sum(int x){
    int ret=0;
    while(x>0){
        ret+=C[x];
        x-=lowbit(x);
    }
    return ret;
}
void add(int x){
    while(x<100005){
        C[x]++;
        x+=lowbit(x);
    }
}
void solve(){
    fab(i,1,n){
       b[i]=sum(a[i]-1);
       add(a[i]);
    }
    memset(C,0,sizeof C);
    fba(i,n,1){
       c[i]=sum(a[i]-1);
       add(a[i]);
    }
    LL ans=0;
    fab(i,1,n){
        ans+=1LL*b[i]*(n-i-c[i])+1LL*(c[i]*(i-1-b[i]));
    }
    pf("%lld\n",ans);
}
int main(){
    int T;sf("%d",&T);
    while(T--){
        memset(C,0,sizeof C);
        sf("%d",&n);
        rep(i,n){sf("%d",&a[i+1]);}
        solve();
    }
    return 0;
}

