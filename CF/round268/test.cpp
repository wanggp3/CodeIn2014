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
int p[N],x[N];
bool cmp(int a,int b){
    return x[a]<x[b];
}
int main(){
    int n=10;
    rep(i,n){
        p[i]=i;
       if(i<5)  x[i]=i;
       else x[i]=11-i;
    }
    sort(p,p+n,cmp);
    rep(i,n){
        pf("%d %d\n",x[p[i]],p[i]);
    }
    return 0;
}

