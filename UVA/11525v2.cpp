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
const int N=50015;
using namespace std;
typedef pair<int,int>PII;
int sz[3*N];
int K;
vector<int>ans;
void init(){
    memset(sz,0,sizeof sz);
    ans.clear();
    sf("%d",&K);
}
void push_up(int rt){
    sz[rt]=sz[rt<<1]+sz[rt<<1|1];
}
void build(int l,int r,int rt){
    if(l==r){
        sz[rt]=1;
        return ;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    push_up(rt);
}
int qurry(int v,int l,int r,int rt){
    if(l==r)return l;
    int m=(l+r)>>1;
    if(sz[rt<<1]>=v)return qurry(v,lson);
    else return qurry(v-sz[rt<<1],rson);
}
void update(int p,int v,int l,int r,int rt){
    if(l==r){
        sz[rt]+=v;
        return;
    }
    int m=(l+r)>>1;
    if(p<=m)update(p,v,lson);
    else if(p>m)update(p,v,rson);
    push_up(rt);
}
void solve(){
    int x;
    build(1,K,1);
    rep(i,K){
        sf("%d",&x);
        int id=qurry(x+1,1,K,1);
        ans.PB(id);
        update(id,-1,1,K,1);
    }
    rep(i,ans.size()){
        if(i==ans.size()-1)pf("%d\n",ans[i]);
        else pf("%d ",ans[i]);
    }
}
int main(){
    int T;sf("%d",&T);
    while(T--){
        init();
        solve();
    }
    return 0;
}


