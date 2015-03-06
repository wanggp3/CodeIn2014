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
#define X first
#define Y second
const int N=50005;
using namespace std;
int n;
pair<double,double>P[N];
const double eps=1e-7;
double get(double x){
    double ret=0;
    rep(i,n){
        ret+=fabs(x-P[i].X)*P[i].Y;
    }
    return ret;
}
void init(){
    double L=INF,R=-INF;
    sf("%d",&n);
    rep(i,n){
        sf("%lf%lf",&P[i].X,&P[i].Y);
        L=min(L,P[i].X);
        R=max(R,P[i].X);
    }
   /* pf("%lf %lf\n",L,R);
    rep(i,n){
        pf("%lf %lf\n",P[i].X,P[i].Y);
    }*/
    double sm=INF;
    while(R-L>eps){
        double M1=L+(R-L)/3.0;
        double M2=R-(R-L)/3.0;
        sm=min(sm,get(M1));
        sm=min(sm,get(M2));
        if(get(M1)>get(M2))L=M1;
        else R=M2;
    }
    pf("%lf\n",sm);
    pf("%.5lf\n",get(L));
}
int main(){
    init();
    return 0;
}

