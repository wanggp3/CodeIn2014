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
const int N=1005;
using namespace std;
typedef pair<int,int>PII;
int n,k,x;
void solve(){
    multiset<int>S;
    LL ans=0;
    rep(i,n){
        sf("%d",&k);
        rep(j,k){
            sf("%d",&x);
            S.insert(x);
        }
        int maxv=*S.rbegin(),minv=*S.begin();
        ans+=maxv-minv;
        S.erase(--S.end());
        S.erase(S.begin());
    }
    pf("%lld\n",ans);
}
int main(){
    while(~sf("%d",&n)&&n){
        solve();
    }
    return 0;
}


