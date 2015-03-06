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
#define LD double
LD a,b;
void solve(){
    if(a<b)swap(a,b);
    LD ans;
    if(a-b>=31){
        ans=a;
    }else{
        LD tmp=pow(2.0,a-b)+1;
        tmp=log(tmp)/log(2.0);
        ans=b+tmp;
    }
    //pf("%.9llf\n",ans);
    cout<<fixed<<setprecision(9)<<ans<<endl;
}
int main(){
    int T;sf("%d",&T);
    rep(cas,T){
        //sf("%llf%llf",&a,&b);
        cin>>a>>b;
        pf("Case %d: ",cas+1);
        solve();
    }
    return 0;
}

