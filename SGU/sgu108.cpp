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
int n,k;
int cnt=0;
struct node{
    int x,id,ans;
}a[5001];
bool d[64];
int getcnt(int x){
    int ret=0;
    while(x){
        ret+=x%10;
        x/=10;
    }
    return ret;
}
bool cmp1(node x,node y){
    if(x.x!=y.x)return x.x<y.x;
    else return x.id<y.id;
}
bool cmp2(node x,node y){
    return x.id<y.id;
}
int main(){
    sf("%d%d",&n,&k);
    rep(i,k){
        sf("%d",&a[i].x);
        a[i].id=i;
    }
    int j=0;
    sort(a,a+k,cmp1);
    fill(d,d+64,1);
    for(int i=1;i<=n;i++){
       if(d[i&63]){
          ++cnt;
          while(j<k&&a[j].x==cnt)a[j++].ans=i;
       }
       int to=i+getcnt(i);
       //pf("to %d\n",to);
       d[i&63]=1;
       d[to&63]=0;
    }
    pf("%d\n",cnt);
    sort(a,a+k,cmp2);
    rep(i,k){
        if(i==k-1)pf("%d\n",a[i].ans);
        else pf("%d ",a[i].ans);
    }
    return 0;
}

