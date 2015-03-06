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
const int N=2005;
using namespace std;
int p,q,l,r;
int A[N];
int a[N],b[N];
int sum[N];
bool ok(int T){
    rep(i,q){
        int L=a[i]+T,R=b[i]+T;
        if(sum[R]-sum[L-1]>0)return 1;
    }
    return 0;
}

int main(){
    sf("%d%d%d%d",&p,&q,&l,&r);
    memset(A,0,sizeof A);
    memset(sum,0,sizeof sum);
    rep(i,p){
        int L,R;
        sf("%d%d",&L,&R);
        L++;
        R++;
        fab(j,L,R)A[j]=1;//pf("%dgg\n",j);
    }
    fab(i,1,2003)sum[i]=sum[i-1]+A[i];
   // rep(i,30)pf("%d ",A[i]);puts("");
    rep(i,q){
        sf("%d%d",&a[i],&b[i]);
        a[i]++;
        b[i]++;
    }
    int ans=0;
    fab(T,l,r){
        if(ok(T))ans++;
    }
    pf("%d\n",ans);
    return 0;
}

