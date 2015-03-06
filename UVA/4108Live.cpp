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
const int N=100005;
using namespace std;
typedef pair<int,int>PII;
int maxv[N<<2],tag[N<<2],ans;
void push_down(int rt){
    if(tag[rt]!=-1){
        tag[rt<<1]=tag[rt<<1|1]=tag[rt];
        maxv[rt<<1]=maxv[rt<<1|1]=tag[rt];
        tag[rt]=-1;
    }
}
void push_up(int rt){
    maxv[rt]=max(maxv[rt<<1],maxv[rt<<1|1]);
}
int update(int L,int R,int v,int l,int r,int rt){
    if(tag[rt]>v)return 0;
    if(L<=l&&r<=R){
        if(v>=maxv[rt]){
            maxv[rt]=tag[rt]=v;
            return r-l+1;
        }
    }
    if(l==r)return v>=maxv[rt];
    push_down(rt);
    int m=(l+r)>>1;
    int ret=0;
    if(L<=m)ret+=update(L,R,v,lson);
    if(m<R)ret+=update(L,R,v,rson);
    push_up(rt);
    return ret;
}
int main(){
    int T;sf("%d",&T);
    while(T--){
        int n;
        sf("%d",&n);
        memset(tag,-1,sizeof tag);
        memset(maxv,0,sizeof maxv);
        ans=0;
        int L,R,v;
        rep(i,n){
            sf("%d%d%d",&L,&R,&v);
            ans+=update(L,R-1,v,1,N,1);
        }
        pf("%d\n",ans);
    }
    sf("%*d");
    return 0;
}


