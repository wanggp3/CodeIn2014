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
bool ok(LL x){
    LL t=sqrt(x+0.5);
    if(t*t==x)return 1;
    else return 0;
}
int main(){
    int T;cin>>T;
    while(T--){
        LL a,b,c,n,m,k;
        cin>>a>>b>>c>>n>>m>>k;
        LL dab=2*a*b;
        LL abc=a*a+b*b-c*c;
        LL up=dab*dab-abc*abc;
        up=abs(up);
        LL down=dab*dab;
        LL gcd=__gcd(down,up);
        down/=gcd;
        up/=gcd;
        if(ok(up)&&ok(down))puts("YES");
        else puts("NO");
    }
    return 0;
}

