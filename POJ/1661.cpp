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
int n;
int x,y,Max;
int dp[N][2];
struct node{
    int L,R,H;
    node(int L=0,int R=0,int H=0):L(L),R(R),H(H){}
    bool operator<(const node& rhs)const{
        return H < rhs.H;
    }
}a[N];
void init(){
    sf("%d%d%d%d",&n,&x,&y,&Max);
    rep(i,n){
        sf("%d%d%d",&a[i].L,&a[i].R,&a[i].H);
        if(a[i].L>a[i].R)swap(a[i].L,a[i].R);
    }
    a[n].L=-20001;a[n].R=20001;a[n].H=0;
    a[n+1].L=x;a[n+1].R=x;a[n+1].H=y;
    n+=2;
}
void solve(){
   sort(a,a+n);
   /*rep(i,n){
       pf("%d %d %d\n",a[i].L,a[i].R,a[i].H);
   }*/
   rep(i,n){
       if(i)dp[i][0]=dp[i][1]=INF;
       else dp[i][0]=dp[i][1]=0;
       bool flag1=1,flag2=1;
       for(int j=i-1;j>=0;j--){
           if(a[i].H-a[j].H>Max||(!flag1&&!flag2))break;
           if(!j){
               if(flag1)dp[i][0]=min(dp[i][0],a[i].H);
               if(flag2)dp[i][1]=min(dp[i][1],a[i].H);
               continue;
           }
           if(a[i].L>=a[j].L&&a[i].L<=a[j].R&&flag1){
               dp[i][0]=min(dp[i][0],min(dp[j][0]+a[i].H-a[j].H+a[i].L-a[j].L,dp[j][1]+a[i].H-a[j].H+a[j].R-a[i].L));
               flag1=0;
           }
           if(a[i].R>=a[j].L&&a[i].R<=a[j].R&&flag2){
               dp[i][1]=min(dp[i][1],min(dp[j][0]+a[i].H-a[j].H+a[i].R-a[j].L,dp[j][1]+a[i].H-a[j].H+a[j].R-a[i].R));
               flag2=0;
           }
       }
   }
   /*rep(i,n){
       pf("%d %d\n",dp[i][0],dp[i][1]);
   }*/
   pf("%d\n",dp[n-1][0]);
}
int main(){
    int T;sf("%d",&T);
    while(T--){
        init();solve();
    }
    return 0;
}

