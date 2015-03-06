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
const int N=105;
using namespace std;
int d[N];
char str[N];
int n;
void init(){
    memset(d,0,sizeof d);
    sf("%d%s",&n,str);
}
void solve(){
    int k=0;
    fab(i,1,n){
        fab(j,i,n){
            if(str[k]=='+')d[j]++;
            else if(str[k]=='-')d[i-1]++;
            k++;
        }
    }
    fab(i,1,n){
        if(i==n)pf("%d\n",d[i]-d[i-1]);
        else pf("%d ",d[i]-d[i-1]);
    }
}
int main(){
    int T;sf("%d",&T);
    while(T--){
        init();
        solve();
    }
    return 0;
}

