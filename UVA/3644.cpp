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
const int N=100005;
using namespace std;
int f[N];
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
int main(){
    int x,y;
    while(~sf("%d",&x)){
        int cnt=0;
        rep(i,N)f[i]=i;
        while(x!=-1){
            sf("%d",&y);
            x=find(x);y=find(y);
            if(x==y)cnt++;
            else f[x]=y;
            sf("%d",&x);
        }
        pf("%d\n",cnt);
    }
    return 0;
}

