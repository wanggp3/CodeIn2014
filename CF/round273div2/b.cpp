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
LL n,m;
int main(){
    cin>>n>>m;
    LL ans1=0,ans2=0;
    ans1=(n-m+1)*(n-m)/2;
    LL tmp=n/m;
    LL a=n%m;
    ans2=(m-a)*tmp*(tmp-1)/2;
    ans2+=a*tmp*(tmp+1)/2;
    cout<<ans2<<' '<<ans1<<endl;
    return 0;
}


