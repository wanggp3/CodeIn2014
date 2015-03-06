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
#define LD  long double
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define sf scanf
#define pf printf 
const int N=1005;
using namespace std;
int xo,yo,c,t;
int vx,vy,xt,yt;
long double eps = 1e-8;
int n;

bool in(LD x,LL L,LD R){
    return x>L-eps&&x<R+eps;
}
bool OK(LD A,LD B,LD C,LD L,LD R){
   if(fabs(A)>=eps){
      if(B*B-4*A*C<-eps)return 0;
      LD x1=(-B+sqrt(B*B-4*A*C))/2.0/A;
      LD x2=(-B-sqrt(B*B-4*A*C))/2.0/A;
      return in(x1,L,R)||in(x2,L,R);
   }else{
      if(fabs(B)<eps)return fabs(C)<eps;
      else return in(-C/B,L,R);
   }
}
void solve(){
    sf("%d",&n);
    int ans=0;
    rep(i,n){
        sf("%d%d%d%d",&xt,&yt,&vx,&vy);
        LD A=(LD)vx*vx+(LD)vy*vy-(LD)c*c;
        LD B=(LD)2*(xt-xo)*vx+(LD)2*(yt-yo)*vy;
        LL C=(LD)(xt-xo)*(xt-xo)+(LD)(yt-yo)*(yt-yo);
        if(OK(A,B,C,0,t)){
            ans++;
            continue;
        }
        B=B+(LD)4*t*c*c;
        C=C-(LD)4*t*c*c;
        if(OK(A,B,C,t,2*t)){
           ans++;
           continue;
        }
    }
    pf("%d\n",ans);
}
int main(){
     while(~sf("%d%d%d%d",&xo,&yo,&c,&t)){
         solve();
     }
    return 0;
}

