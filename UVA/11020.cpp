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
#define X first
#define Y second
#define LL long long
const int N=1005;
using namespace std;
typedef pair<int,int>PII;
int n;
PII u;
multiset<PII>S;
void solve(){
    S.clear();
    multiset<PII>::iterator it;
    while(n--){
        sf("%d%d",&u.X,&u.Y);
        it=S.lower_bound(u);
        if(it==S.begin()||(--it)->Y > u.Y ){
            it=S.upper_bound(u);
            while(it!=S.end()&&it->Y >= u.Y ){
                S.erase(it++);
            }
            S.insert(u);
        }
        pf("%d\n",int(S.size()));
    }
}
int main(){
    int T;sf("%d",&T);
    rep(cas,T){
        if(cas)puts("");
        sf("%d",&n);
        pf("Case #%d:\n",cas+1);
        solve();
    }
    return 0;
}


