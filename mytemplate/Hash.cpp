#include<iostream>
#include<cstring>
#include<set>
#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<algorithm>
#include<stdio.h>
#include<iomanip>

#define rep(i,n) for(int i=0;i<n;++i)
#define fab(i,a,b) for(int i=a;i<=b;++i)
#define fba(i,b,a) for(int i=b;i>=a;--i)
#define PB push_back
#define INF 0x3f3f3f3f
#define MP make_pair
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define sf scanf
#define pf printf
#define LL long long
const int N=1005;
using namespace std;
typedef pair<int,int>PII;
#define ULL unsigned long long
ULL xp[N],H[N],hash[N];
int n;
const int X=1007;
char str[N];
void init(){
    H[n]=0;
    fba(i,n-1,0)H[i]=H[i+1]*X+(str[i]-'a');
    xp[0]=1;
    fab(i,1,n)xp[i]=xp[i-1]*X;
}
int main(){
    
    return 0;
}


