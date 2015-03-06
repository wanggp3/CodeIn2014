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
map<int,LL>ans,mp1,mp2;
map<int,LL>::iterator it;
int n;
int main(){
    sf("%d",&n);
    int x;
    sf("%d",&x);
    ans[x]=1;
    mp1[x]=1;
    rep(i,n-1){
        sf("%d",&x);
        ans[x]++;
        mp2[x]++;
        for(it=mp1.begin();it!=mp1.end();it++){
            int gcd=__gcd(it->first,x);
            mp2[gcd]+=it->second;
            ans[gcd]+=it->second;
        }
        mp1.clear();
        for(it=mp2.begin();it!=mp2.end();it++){
            mp1[it->first]=it->second;
        }
        mp2.clear();
    }
    sf("%d",&n);
    rep(i,n){
        sf("%d",&x);
        pf("%d\n",ans[x]);
    }
    return 0;
}


