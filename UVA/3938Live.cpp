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
#define X first
#define Y second
const int N=500005;
using namespace std;
int n,q;
LL sum[N];
typedef pair<int,int>PII;
PII maxsum[N<<2],maxpre[N<<2],maxsuf[N<<2];
void push_up(int rt){
    maxsum[rt]=maxsum[rt<<1];
    if(sum[maxpre[rt<<1|1].Y]-sum[maxsuf[rt<<1].X-1]>sum[maxsum[rt].Y]-sum[maxsum[rt].X-1]){
        maxsum[rt]=MP(maxsuf[rt<<1].X,maxpre[rt<<1|1].Y);
    }
    if(sum[maxsum[rt<<1|1].Y]-sum[maxsum[rt<<1|1].X-1]>sum[maxsum[rt].Y]-sum[maxsum[rt].X-1]){
        maxsum[rt]=maxsum[rt<<1|1];
    }

    if(sum[maxpre[rt<<1|1].Y]-sum[maxpre[rt<<1].X-1]>sum[maxpre[rt<<1].Y]-sum[maxpre[rt<<1].X-1]){
        maxpre[rt]=MP(maxpre[rt<<1].X,maxpre[rt<<1|1].Y);
    }else maxpre[rt]=maxpre[rt<<1];
    if(sum[maxsuf[rt<<1|1].Y]-sum[maxsuf[rt<<1].X-1]>sum[maxsuf[rt<<1|1].Y]-sum[maxsuf[rt<<1|1].X-1]){
        maxsuf[rt]=MP(maxsuf[rt<<1].X,maxsuf[rt<<1|1].Y);
    }else maxsuf[rt]=maxsuf[rt<<1|1];
}
void build(int l,int r,int rt){
    if(l==r){
        maxsum[rt]=maxpre[rt]=maxsuf[rt]=MP(l,r);
        return;
    }
    maxsum[rt]=maxpre[rt]=maxsuf[rt]=MP(0,0);
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    push_up(rt);
}
void init(){
    sum[0]=0;
    int x;
    fab(i,1,n){
        sf("%d",&x);
        sum[i]=sum[i-1]+1LL*x;
    }
    //fab(i,1,n)pf("%lld ",sum[i]);pf("\n");
    build(1,n,1);
    /*fab(i,1,9){
        pf("id %d :%d %d\n",i,maxsum[i].X,maxsum[i].Y);
    }*/
}
PII qurry(int L,int R,int l,int r,int rt){
    //pf("%d %d %d\n",l,r,rt);
    if(L<=l&&r<=R){
       // pf("%d %d get %d %d\n",l,r,maxsum[rt].X,maxsum[rt].Y);
        return maxsum[rt];
    }
    int m=(l+r)>>1;
    PII ret;
    bool flag=0;
    if(L<=m){
        ret=qurry(L,R,lson);
        flag=1;
    }
    if(R>m){
        PII x=qurry(L,R,rson);
        if(!flag)ret=x;
        else {
            if(sum[maxpre[rt<<1|1].Y]-sum[maxsuf[rt<<1].X-1]>sum[ret.Y]-sum[ret.X-1]){
                ret=MP(maxsuf[rt<<1].X,maxpre[rt<<1|1].Y);
            }
            if(sum[maxsum[rt<<1|1].Y]-sum[maxsum[rt<<1|1].X-1]>sum[ret.Y]-sum[ret.X-1]){
                ret=maxsum[rt<<1|1];
            }
        }
    }
   // pf("%d %d get %d %d\n",l,r,ret.X,ret.Y);
    return ret;
}
void solve(){
    int L,R;
   while(q--){
      sf("%d%d",&L,&R);
      PII ret=qurry(L,R,1,n,1);
      pf("%d %d\n",ret.X,ret.Y);
   }
}
int main(){
    int cas=1;
    while(~sf("%d%d",&n,&q)){
       init();
       pf("Case %d:\n",cas++);
       solve();
    }
    return 0;
}

