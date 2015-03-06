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
int a[N];
int n;
void init(){
    sf("%d",&n);
    rep(i,n)sf("%d",&a[i]);
}
void solve(){
    int ans=0;
    rep(i,n){
        int cnt1=0,cnt2=0;
        rep(j,n){
            if(i==j)continue;
            if(__gcd(a[i],a[j])==1)cnt1++;
            else cnt2++;
        }
        ans+=cnt1*cnt2;
    }
    ans=n*(n-1)*(n-2)/6-ans/2;
    pf("%d\n",ans);
}
int main(){
    int T;sf("%d",&T);
    while(T--){
        init();solve();
    }
    return 0;
}

