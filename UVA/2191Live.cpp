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
const int N=200105;
using namespace std;
typedef pair<int,int>PII;
int n,C[N],a[N];
void add(int x,int v){
    while(x<N){
        C[x]+=v;
        x+=(x&-x);
    }
}
int sum(int x){
    int ret=0;
    while(x){
        ret+=C[x];
        x-=(x&-x);
    }
    return ret;
}
void init(){
    memset(C,0,sizeof C);
    int x;
    rep(i,n){
        sf("%d",&x);
        add(i+1,x);
        a[i+1]=x;
    }
}
void solve(){
    char op[10];
    int x,y;
    while(sf("%s",op)&&op[0]!='E'){
        if(op[0]=='S'){
            sf("%d%d",&x,&y);
            add(x,-a[x]+y);
            a[x]=y;
        }else {
            sf("%d%d",&y,&x);
            int t;
            if(y==1)t=0;
            else t=sum(y-1);
            pf("%d\n",sum(x)-t);
        }
    }
}
int main(){
    int cas=0;
    while(~sf("%d",&n)&&n){
        if(cas)pf("\n");
        pf("Case %d:\n",++cas);
        init();
        solve();
    }
    return 0;
}


