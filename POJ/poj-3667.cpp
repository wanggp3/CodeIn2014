#include<iostream>
#include<cstring>
#include<stdio.h>
#include<cmath>
#include<stack>

#define rep(i,n) for(int i=0;i<(n);++i)
#define fab(i,a,b) for(int i=(a);i<=(b);++i)
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x7FFFFFF

using namespace std;
const int N=50005;
int n,q;
int lsum[N<<2],rsum[N<<2],msum[N<<2],cover[N<<2];
void build(int l,int r,int rt){
    lsum[rt]=rsum[rt]=msum[rt]=r-l+1;
    cover[rt]=-1;
    if(l==r)return ;
    int m=(l+r)>>1;
    build(lson);
    build(rson);
}
void PushDown(int rt,int m){
    if(cover[rt]!=-1){
        cover[rt<<1]=cover[rt<<1|1]=cover[rt];
        msum[rt<<1]=lsum[rt<<1]=rsum[rt<<1]=cover[rt]?0:m-(m>>1);
        rsum[rt<<1|1]=lsum[rt<<1|1]=msum[rt<<1|1]=cover[rt]?0:(m>>1);
        cover[rt]=-1;
    }
}
void PushUp(int rt,int m){
    lsum[rt]=lsum[rt<<1];
    rsum[rt]=rsum[rt<<1|1];
    if(lsum[rt]==m-(m>>1))lsum[rt]+=lsum[rt<<1|1];
    if(rsum[rt]==(m>>1))rsum[rt]+=rsum[rt<<1];
    msum[rt]=max(max(msum[rt<<1],msum[rt<<1|1]),rsum[rt<<1]+lsum[rt<<1|1]);
}
int qurry(int cnt,int l,int r,int rt){
    if(l==r)return l;
    int m=(l+r)>>1;
   
    PushDown(rt,r-l+1);
    if(cnt<=msum[rt<<1])return qurry(cnt,lson);
    else if(cnt<=rsum[rt<<1]+lsum[rt<<1|1]) return m-rsum[rt<<1]+1;
    else return qurry(cnt,rson);
}
void update(int L,int R,int c,int l,int r,int rt){
    if(L<=l&&r<=R){
        msum[rt]=rsum[rt]=lsum[rt]=c?0:r-l+1;
        cover[rt]=c;
        return ;
    }
    PushDown(rt,r-l+1);
    int m=(l+r)>>1;
    if(L<=m)update(L,R,c,lson);
    if(R>m)update(L,R,c,rson);
    PushUp(rt,r-l+1);
}
int main(){
    scanf("%d%d",&n,&q);
    while(q--){
        int op,x,y;
        scanf("%d",&op);
        build(1,n,1);
        if(op==1){
            scanf("%d",&x);
            if(msum[1]<x)puts("0");
            else{
                int ans=qurry(x,1,n,1);
                printf("%d\n",ans);
                update(ans,ans+x-1,1,1,n,1);
            }
        }else if(op==2){
            scanf("%d%d",&x,&y);
            update(x,x+y-1,0,1,n,1);
        }
    }
}

