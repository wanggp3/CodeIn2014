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
LL a,b,c,x[2],y[2];
LL extgcd(LL a,LL b,LL &x,LL &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }else{
        LL ret=extgcd(b,a%b,x,y);
        LL tmp=x;
        x=y;
        y=tmp-y*(a/b);
        return ret;
    }
}
void solve(){
    LL ans=0;
    sf("%I64d%I64d",&x[0],&x[1]);
    sf("%I64d%I64d",&y[0],&y[1]);
    c=-c;
    if(a==0&&b==0){
        if(c==0){
            ans=(x[1]-x[0]+1)*(y[1]-y[0]+1);
        }else ans=0;
    }else if(a==0){
        if(c%b==0 && c/b>=y[0]&&c/b<=y[1])ans=x[1]-x[0]+1;
        else ans=0;
    }else if(b==0){
        if(c%a==0 && c/a>=x[0]&&c/a<=x[1])ans=y[1]-y[0]+1;
        else ans=0;
    }else{
        LL xo,yo;
        LL gcd=extgcd(a,b,xo,yo);
        if(c%gcd==0){
            xo*=c/gcd;
            yo*=c/gcd;
            LL lx,ly,rx,ry;
            lx=(x[0]<=xo||(x[0]-xo)*gcd%b==0)?((x[0]-xo)*gcd/b):((x[0]-xo)*gcd/b+1);
            rx=(x[1]>=xo||(x[1]-xo)*gcd%b==0)?((x[1]-xo)*gcd/b):((x[1]-xo)*gcd/b-1);
            if(lx>rx)swap(lx,rx);
            ly=(yo>=y[0]||(yo-y[0])*gcd%a==0)?((yo-y[0])*gcd/a):((yo-y[0])*gcd/a-1);
            ry=(yo<=y[1]||(yo-y[1])*gcd%a==0)?((yo-y[1])*gcd/a):((yo-y[1])*gcd/a+1);
            if(ly>ry)swap(ly,ry);
            if(ry>=lx&&rx>=ly)ans=min(rx,ry)-max(lx,ly)+1;
            else ans=0;
                
        }else ans=0;
    }
    pf("%I64d\n",ans);
}
int main(){
    while(~sf("%I64d%I64d%I64d",&a,&b,&c)){
        solve();
    }
    return 0;
}

