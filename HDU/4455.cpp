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
const int N=1000005;
using namespace std;
typedef pair<int,int>PII;
int n,Q,w;
LL dp[N];
int pre[N],a[N],d[N],cnt[N],tmp[N],end[N];
void init(){
    memset(cnt,0,sizeof cnt);
   memset(pre,0,sizeof pre);
   memset(tmp,0,sizeof tmp);
}
void solve(){
    fab(i,1,n){
        sf("%d",&a[i]);
        d[i]=i-pre[a[i]];
        pre[a[i]]=i;
    }
    fab(i,1,n){
        cnt[d[i]]++;
    }
    int t=0;
    fba(i,n,1){
        if(!tmp[a[i]]){
            tmp[a[i]]=1;
            t++;
        }
        end[n-i+1]=t;
    }
    dp[1]=n;
    int sum=n;
    fab(i,2,n){
        dp[i]=dp[i-1]-end[i-1];
        sum-=cnt[i-1];
        dp[i]+=sum;
    }
    sf("%d",&Q);
    while(Q--){
        int x;sf("%d",&x);
        pf("%lld\n",dp[x]);
    }
}
int main(){
    while(~sf("%d",&n)&&n){
        init();
        solve();
    }
    return 0;
}


