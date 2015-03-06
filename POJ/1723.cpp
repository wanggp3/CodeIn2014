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
#define cls0(x) memset(x,0,sizeof(x))
#define cls1(x) memset(x,-1,sizeof(x))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1
#define LL long long 
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define sf scanf
#define pf printf 
const int N=10005;
using namespace std;
int n,x[N],y[N];
int main(){
    sf("%d",&n);
    rep(i,n)sf("%d %d",&x[i],&y[i]);
    int ans=0;
    sort(y,y+n);
    sort(x,x+n);
    rep(i,n){
        ans+=abs(y[i]-y[n/2]);
        x[i]=x[i]-i;
    }
    sort(x,x+n);
    rep(i,n){
        ans+=abs(x[i]-x[n/2]);
    }
    pf("%d\n",ans);

    return 0;
}

