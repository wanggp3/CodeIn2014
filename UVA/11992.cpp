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
const int N=1000005;
using namespace std;
int R,C,M;
int Min,Max;
int tag[21][N<<1],add[21][N<<1],minv[21][N<<1],maxv[21][N<<1],sum[21][N<<1];
void push_up(int i,int rt){
    maxv[i][rt]=max(maxv[i][rt<<1],maxv[i][rt<<1|1]);
    minv[i][rt]=min(minv[i][rt<<1],minv[i][rt<<1|1]);
    sum[i][rt]=sum[i][rt<<1]+sum[i][rt<<1|1];
}
void build(int i,int l,int r,int rt){
    tag[i][rt]=-1;
    add[i][rt]=0;
    if(l==r){
        minv[i][rt]=maxv[i][rt]=sum[i][rt]=0;
        return;
    }
    int m=(l+r)>>1;
    build(i,lson);
    build(i,rson);
    push_up(i,rt);
}
void init(){
    fab(i,1,R)build(i,1,C,1);
}
void push_down(int i,int rt,int l,int r){
    if(tag[i][rt]!=-1){
        tag[i][rt<<1]=tag[i][rt<<1|1]=tag[i][rt];
        sum[i][rt<<1]=((l+r)/2 - l + 1 )*tag[i][rt];
        sum[i][rt<<1|1]=(r - (l+r)/2  )*tag[i][rt];
        maxv[i][rt<<1]=maxv[i][rt<<1|1]=tag[i][rt];
        minv[i][rt<<1]=minv[i][rt<<1|1]=tag[i][rt];
        add[i][rt<<1]=add[i][rt<<1|1]=0;
        tag[i][rt]=-1;
    }
    if(add[i][rt]!=0){
        add[i][rt<<1]+=add[i][rt];
        add[i][rt<<1|1]+=add[i][rt];
        sum[i][rt<<1]+=((l+r)/2 -l + 1)*add[i][rt];
        sum[i][rt<<1|1]+=(r - (l+r)/2  )*add[i][rt];
        maxv[i][rt<<1]+=add[i][rt];
        minv[i][rt<<1]+=add[i][rt];
        maxv[i][rt<<1|1]+=add[i][rt];
        minv[i][rt<<1|1]+=add[i][rt];
        add[i][rt]=0;
    }
}
void update(int i,int L,int R,int v,int l,int r,int rt,int k){
   if(L<=l&&r<=R){
       if(k==1){
          sum[i][rt]+=v*(r-l+1);
          add[i][rt]+=v;
          minv[i][rt]+=v;
          maxv[i][rt]+=v;
       }else if(k==2){
          sum[i][rt]=v*(r-l+1);
          add[i][rt]=0;
          minv[i][rt]=maxv[i][rt]=v;
          tag[i][rt]=v;
       }
       return ;
   }
   push_down(i,rt,l,r);
   int m=(l+r)>>1;
   if(L<=m)update(i,L,R,v,lson,k);
   if(R>m)update(i,L,R,v,rson,k);
   push_up(i,rt);
}
int qurry(int i,int L,int R,int l,int r,int rt){
    //pf("%d %d %d %d %d \n",i,L,R,l,r);
    if(L<=l&&r<=R){
        Max=max(Max,maxv[i][rt]);
        Min=min(Min,minv[i][rt]);
        return sum[i][rt];
    }
    push_down(i,rt,l,r);
    int m=(l+r)>>1;
    int ret=0;
    if(L<=m)ret+=qurry(i,L,R,lson);
    if(R>m)ret+=qurry(i,L,R,rson);
    return ret;
}
void solve(){
    int op,xl,yl,xr,yr,v;
    while(M--){
       sf("%d%d%d%d%d",&op,&xl,&yl,&xr,&yr);
       if(op==1||op==2){
           sf("%d",&v);
           fab(i,xl,xr)update(i,yl,yr,v,1,C,1,op);
       }else if(op==3){
           int ret=0;
           Min=INF,Max=-INF;
           fab(i,xl,xr)ret+=qurry(i,yl,yr,1,C,1);
           pf("%d %d %d\n",ret,Min,Max);
       }
    }
}
int main(){
    while(~sf("%d%d%d",&R,&C,&M)){
        init();
        solve();
    }
    return 0;
}

