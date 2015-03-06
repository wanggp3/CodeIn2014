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
const int N=1000005;
using namespace std;
int n,m;
int a[N];
void init(){
    sf("%d",&n);
    memset(a,0,sizeof a);
    int x;
    int last=1;
    rep(i,n){
        sf("%d",&x);
        for(int cnt=0;cnt<x;cnt++,last++)a[last]=i+1;
    }
    sf("%d",&m);
    rep(i,m){
        sf("%d",&x);
        pf("%d\n",a[x]);
    }
}
int main(){
    init();
    return 0;
}

