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
const int N=40005;
using namespace std;
typedef pair<int,int>PII;

int main(){
    int n,t;
    bool ok[N];
    int a[N];
    while(~sf("%d%d",&n,&t)){
        memset(ok,0,sizeof ok);
        rep(i,n-1)sf("%d",&a[i+1]);
        int i=1;
        while(i<n){
            ok[i]=1;
            i=i+a[i];
        }
        if(ok[t])puts("YES");
        else puts("NO");
    }
    return 0;
}


