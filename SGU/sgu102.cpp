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
void solve1(int n){
    int ans=0;
    fab(i,1,n){
        if(__gcd(i,n)==1)ans++;
    }
    pf("%d\n",ans);
}
void solve2(int n){
    int ans=n;
    for(int i=2;n!=1;i++){
        if(n%i==0){
            ans=ans-ans/i;
            while(n%i==0)n/=i;
        }
    }
    pf("%d\n",ans);
}
int main(){
    int n;
    while(sf("%d",&n)!=EOF){
        solve2(n);
    }
    return 0;
}

