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
int n;
double x[N],y[N];
void init(){
  rep(i,n){
      sf("%lf%lf",&x[i],&y[i]);
  }
}
double sqr(double x){
    return x*x;
}
double getD(int i,int j){
    return sqr(x[i]-x[j])+sqr(y[i]-y[j]);
}
double getH(int i,int j,int k){
    double a=sqrt(getD(i,j));
    double b=sqrt(getD(i,k));
    double c=sqrt(getD(k,j));
    double p=(a+b+c)/2.0;
    double area=sqrt(p*(p-a)*(p-b)*(p-c));
    return 2.0*area/(min(a,min(b,c)));
}
void solve(){
  double ans=0;
  rep(i,n){
      double mx=0;
      int mxid=-1;
      rep(j,n){
          if(i==j)continue;
          if(getD(i,j)>mx){
              mx=getD(i,j);
              mxid=j;
          }
      }
      rep(j,n){
          if(j==mxid||j==i)continue;
          ans=max(ans,getH(i,j,mxid));
      }
  }
  pf("%.6lf\n",ans);
}
int main(){
    while(~sf("%d",&n)){
        init();
        solve();
    }
    return 0;
}

