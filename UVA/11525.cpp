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
#define lowbit(x) x&-x
#define rson m+1,r,rt<<1|1
#define sf scanf
#define pf printf
#define LL long long
const int N=50015;
using namespace std;
typedef pair<int,int>PII;
int C[N];
int K;
void add(int x,int v){
    while(x<=K){
        C[x]+=v;
        x+=lowbit(x);
    }
}
int sum(int x){
    int ret=0;
    while(x){
        ret+=C[x];
        x-=lowbit(x);
    }
    return ret;
}
vector<int>ans;
void init(){
    ans.clear();
    memset(C,0,sizeof C);
    sf("%d",&K);
    fab(i,1,K)add(i,1);
}
int bs(int x){
    int L=0,R=K;
    while(L+1<R){
        int M=L+(R-L)/2;
        if(sum(M)>=x+1)R=M;
        else L=M;
    }
    add(R,-1);
    return R;
}
void solve(){
    int x;
    rep(i,K){
        sf("%d",&x);
        ans.PB(bs(x));
    }
    rep(i,ans.size())if(i==ans.size()-1)pf("%d\n",ans[i]);
    else pf("%d ",ans[i]);
}
int main(){
    int T;sf("%d",&T);
    while(T--){
        init();
        solve();
    }
    return 0;
}


