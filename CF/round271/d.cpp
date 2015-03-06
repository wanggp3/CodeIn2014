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
const int N=100005;
using namespace std;
LL f[N];
LL M=1e9+7;
int K;
LL sum[N];
void init(){
    for(int i=1;i<K;i++)f[i]=1;
    f[K]=2;
    for(int i=K+1;i<N;i++)f[i]=(f[i-1]+f[i-K])%M;
    sum[0]=0;
    for(int i=1;i<N;i++)sum[i]=(sum[i-1]+f[i])%M;
}
int main(){
    int T;
    sf("%d%d",&T,&K);
    int a,b;
    init();
    while(T--){
        sf("%d%d",&a,&b);
        LL ans=(sum[b]-sum[a-1]+M)%M;
        pf("%lld\n",ans);
    }
    return 0;
}

