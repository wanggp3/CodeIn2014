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
const int N=40005;
using namespace std;
int dp[N];
int ma[N<<2];
int n;
void push_up(int rt){
    ma[rt]=max(ma[rt<<1],ma[rt<<1|1]);
}
void update(int p,int x,int l,int r,int rt){
    if(l==r)ma[rt]=x;
    else{
        int m=(l+r)>>1;
        if(p<=m)update(p,x,lson);
        else update(p,x,rson);
        push_up(rt);
    }
}
int qurry(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R){
        return ma[rt];
    }
    int m=(l+r)>>1;
    int ret=0;
    if(m>=L)ret=max(ret,qurry(L,R,lson));
    if(m<R)ret=max(ret,qurry(L,R,rson));
    return ret;
}
void solve(){
    sf("%d",&n);
    memset(ma,0,sizeof ma);
    int x;
    int ans=0;
    fab(i,1,n){
       sf("%d",&x);
       ans=qurry(1,x,1,n,1)+1;
       update(x,ans,1,n,1);
    }
    pf("%d\n",ma[1]);
}
int main(){
    int T;sf("%d",&T);
    while(T--){
       solve();
    }
    return 0;
}

