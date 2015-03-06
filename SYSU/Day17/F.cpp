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
#define cls0(x) memset(x,0,sizeof(x))
#define cls1(x) memset(x,-1,sizeof(x))
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
int maxv[N<<2],tag[N<<2];
int n,q;
void push_up(int rt){
    maxv[rt]=max(maxv[rt<<1],maxv[rt<<1|1]);
}
void push_down(int rt){
    if(tag[rt]!=-1){
        tag[rt<<1]=tag[rt];
        tag[rt<<1|1]=tag[rt];
        maxv[rt<<1]=tag[rt];
        maxv[rt<<1|1]=tag[rt];
        tag[rt]=-1;
    }
}
void build(int l,int r,int rt){
    if(l==r){
        sf("%d",&maxv[rt]);
        tag[rt]=-1;
    }else {
        int m=(l+r)>>1;
        build(lson);
        build(rson);
        push_up(rt);
        tag[rt]=-1;
    }
}
void update1(int L,int R,int x,int l,int r,int rt){
    if(L<=l&&r<=R){
        tag[rt]=x;
        maxv[rt]=x;
        return ;
    }
    int m=(l+r)>>1;
    push_down(rt);
    if(L<=m)update1(L,R,x,lson);
    if(R>m)update1(L,R,x,rson);
    push_up(rt);
}
void update2(int L,int R,int x,int l,int r,int rt){
    if(maxv[rt]<=x)return;
    if(L<=l&&r<=R){
        if(maxv[rt]<=x)return;
        if(tag[rt]!=-1){
            tag[rt]=__gcd(tag[rt],x);
            maxv[rt]=tag[rt];
            return;
        }
        if(l==r){
            maxv[rt]=__gcd(maxv[rt],x);
            return ;
        }
    }
    int m=(l+r)>>1;
    push_down(rt);
    if(L<=m)update2(L,R,x,lson);
    if(R>m)update2(L,R,x,rson);
    push_up(rt);
}
void print(int l,int r,int rt){
   if(l==r){
       pf("%d ",maxv[rt]);
       return;
   }
   int m=(l+r)>>1;
   push_down(rt);
   print(lson);
   print(rson);
}
int main(){
    int T;
    sf("%d",&T);
    while(T--){
        sf("%d",&n);
        build(1,n,1);
        sf("%d",&q);
        while(q--){
            int L,R,x,op;
            sf("%d%d%d%d",&op,&L,&R,&x);
            if(op==1){
                update1(L,R,x,1,n,1);
            }else if(op==2){
                update2(L,R,x,1,n,1);
            }
        }
        print(1,n,1);
        puts("");
    }
    return 0;
}

