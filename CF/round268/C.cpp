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
void print1(){
    for(int i=5;i<=n;i+=2){
        if(i!=5)pf("%d * 1 = %d\n",i,i);
        pf("%d - %d = 1\n",i+1,i);
    }
    if(n!=4) pf("1 * 4 = 4\n");
    pf("1 * 4 = 4\n");
    pf("2 * 3 = 6\n");
    pf("4 * 6 = 24\n");
}
void print2(){
   for(int i=6;i<=n;i+=2){
       if(i!=6)pf("%d *1 = %d\n",i,i);
       pf("%d - %d = 1\n",i+1,i);
   }
   if(n!=5)pf("1 * 5 = 5\n");
   pf("5 - 1 = 4\n");
   pf("4 - 2 = 2\n");
   pf("2 * 3 = 6\n");
   pf("6 * 4 = 24\n");
}
int main(){
    sf("%d",&n);
    if(n>=4){
        puts("YES");
        if((n-4)%2==0)print1();
        else print2();
    }else puts("NO");
    return 0;
}

