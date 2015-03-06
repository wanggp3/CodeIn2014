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
int n;
int C[N];
vector<int>X;
int m;
struct point{
    int x,y;
    point(int x=0,int y=0):x(x),y(y){}
}P[N];
void solve(){
    memset(C,0,sizeof C);
    X.clear();
    rep(i,n){
        sf("%d%d",&P[i].x,&P[i].y);
        X.PB(P[i].x);
        X.PB(P[i].y);
    }
    sort(X.begin(),X.end());
    m=unique(X.begin(),X.end())-X.begin();
    rep(i,m)pf("%d ",X[i]);
}
int main(){
    while(~sf("%d",&n)){
        solve();
    }
    return 0;
}

