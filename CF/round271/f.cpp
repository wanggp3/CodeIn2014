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
int L[N],R[N];
int n;
int a[N];
int main(){
    sf("%d",&n);
    fab(i,1,n){
        sf("%d",&a[i]);
    }
    L[0]=R[n+1]=0;
    L[1]=0;
    for(int i=2;i<=n;i++){
        if(a[i-1]%a[i]==0)L[i]=L[i-1]+1;
        else L[i]=0;
    }
    R[n]=0;
    for(int i=n-1;i>=1;i--){
        if(a[i+1]%a[i]==0)R[i]=R[i+1]+1;
        else R[i]=0;
    }
    fab(i,1,n){
        pf("%d %d\n",L[i],R[i]);
    }

    return 0;
}

