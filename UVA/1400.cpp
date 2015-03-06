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
const int N=500105;
using namespace std;

struct Node{
    int x,y,suf,pre;
    Node(int x=0,int y=0,int suf=0,int pre=0):x(x),y(y),suf(suf),pre(pre){}
}node[N<<2];
LL sum[N];
int n,m;
void init(){
    sum[0]=0;
    int x;
    fab(i,1,n){
        sf("%d",&x);
        sum[i]=sum[i-1]+x*1LL;
    }
}
void push_up(int rt,int l,int r){
    if(sum[node[rt<<1].pre]-sum[l-1]>=sum[node[rt<<1|1].pre]-sum[l-1]){
        node[rt].pre=node[rt<<1].pre;
    }else node[rt].pre=node[rt<<1|1].pre;
    if(sum[r]-sum[node[rt<<1].suf-1]>=sum[r]-sum[node[rt<<1|1].suf-1]){
        node[rt].suf=node[rt<<1].suf;
    }else node[rt].suf=node[rt<<1|1].suf;
    node[rt].x=node[rt<<1].x;
    node[rt].y=node[rt<<1].y;
    if(sum[node[rt<<1|1].pre]-sum[node[rt<<1].suf-1]>sum[node[rt].y]-sum[node[rt].x-1]){
        node[rt].x=node[rt<<1].suf;
        node[rt].y=node[rt<<1|1].pre;
    }
    if(sum[node[rt<<1|1].y]-sum[node[rt<<1|1].x-1]>sum[node[rt].y]-sum[node[rt].x-1]){
        node[rt].x=node[rt<<1|1].x;
        node[rt].y=node[rt<<1|1].y;
    }
}
void build(int l,int r,int rt){
   if(l==r){
       node[rt].x=node[rt].y=node[rt].pre=node[rt].suf=l;
       return ;
   }
   int m=(l+r)>>1;
   build(lson);
   build(rson);
   push_up(rt,l,r);
}
Node qurry(int L,int R,int l,int r,int rt){
   if(L<=l&&r<=R)return node[rt];
   int m=(l+r)>>1;
   if(L>m)return qurry(L,R,rson);
   if(R<=m)return qurry(L,R,lson);
   Node Left=qurry(L,R,lson);
   Node Right=qurry(L,R,rson);
   Node ret;
   if(sum[Left.pre]-sum[Right.pre]>=0)ret.pre=Left.pre;
   else ret.pre=Right.pre;
   if(sum[Left.suf-1]<=sum[Right.suf-1])ret.suf=Left.suf;
   else ret.suf=Right.suf;
   if(sum[Right.pre]-sum[Left.suf-1]>sum[Left.y]-sum[Left.x-1]){
       ret.x=Left.suf;
       ret.y=Right.pre;
   }else{
       ret.x=Left.x;
       ret.y=Left.y;
   }
   if(sum[Right.y]-sum[Right.x-1]>sum[ret.y]-sum[ret.x-1]){
       ret.x=Right.x;
       ret.y=Right.y;
   }
   return ret;
}
void solve(){
    build(1,n,1);
    int L,R;
    while(m--){
        sf("%d%d",&L,&R);
        Node ans=qurry(L,R,1,n,1);
        pf("%d %d\n",ans.x,ans.y);
    }
}
int main(){
    int T=0;
    while(~sf("%d%d",&n,&m)){
        init();
        pf("Case %d:\n",++T);
        solve();
    }
    return 0;
}

