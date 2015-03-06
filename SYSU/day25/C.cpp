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
const int N=40015;
using namespace std;
int n;
struct node{
    double x,y;
    node(double x=0,double y=0):x(x),y(y){
    }
}p[N];
void init(){
    for(int i=0;i<2*n;i+=2){
        sf("%lf%lf",&p[i].x,&p[i].y);
        if(i!=0){
            p[i-1].x=(p[i].x+p[i-2].x)/2.0;
            p[i-1].y=(p[i].y+p[i-2].y)/2.0;
        }
    }
    p[2*n-1].x=(p[0].x+p[2*n-2].x)/2.0;
    p[2*n-1].y=(p[0].y+p[2*n-2].y)/2.0;
}
double sqr(double x){
    return x*x;
}
double dis(int i,int j){
    return sqr(p[i].x-p[j].x)+sqr(p[i].y-p[j].y);
}
const double eps =1e-9;
void solve(){
    bool is=0;
    rep(i,n){
        double x=p[i].x-p[i+n].x;
        double y=p[i].y-p[i+n].y;
        int k=i-1;
        int j=i+1;
        for(;j<i+n;j++,k--){
            if(k<0)k=2*n-1;
            double x1=p[j].x-p[k].x;
            double yy1=p[j].y-p[k].y;
            if(x*x1+y*yy1!=0)break;
            if(dis(i,j)!=dis(i,k))break;
        }
        if(j==i+n){
            is=1;
            break;
        }
    }
    if(is)puts("YES");
    else puts("NO");
}
int main(){
    while(~sf("%d",&n)){
        init();
        solve();
    }
    return 0;
}

