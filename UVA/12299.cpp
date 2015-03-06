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
const int N=100015;
using namespace std;
typedef pair<int,int>PII;
int minv[N<<2],a[N];
int n,Q;
void init(){
    memset(minv,0,sizeof minv);
    rep(i,n)sf("%d",&a[i+1]);
}
void push_up(int rt){
    minv[rt]=min(minv[rt<<1],minv[rt<<1|1]);
}
void build(int l,int r,int rt){
    if(l==r){
        minv[rt]=a[l];
        return ;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    push_up(rt);
}
int args[50],k;
char cmd[50];
int tmp[50];
int qurry(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R)return minv[rt];
    int m=(l+r)>>1;
    int ret=INF;
    if(L<=m)ret=min(ret,qurry(L,R,lson));
    if(R>m)ret=min(ret,qurry(L,R,rson));
    return ret;
}
void update(int p,int v,int l,int r,int rt){
    if(l==r){
        a[l]=minv[rt]=v;
        return;
    }
    int m=(l+r)>>1;
    if(p<=m)update(p,v,lson);
    else if(p>m)update(p,v,rson);
    push_up(rt);
}
void print(int l,int r,int rt){
    if(l==r)pf("%d %d %d\n",r,a[l],minv[rt]);
    else{
        int m=(l+r)>>1;
        print(lson);
        print(rson);
    }
}
void bug(){
    fab(i,1,n)pf("%d ",a[i]);pf("\n");
}
void solve(){
    build(1,n,1);
    //bug();
    while(Q--){
        args[k=0]=0;
        sf("%s",cmd);
        int len=strlen(cmd);
        for(int i=6;i<len;i++){
            if(isdigit(cmd[i]))args[k]=args[k]*10+(cmd[i]-'0');
            else k++,args[k]=0;
        }
        if(cmd[0]=='q'){
            pf("%d\n",qurry(args[0],args[1],1,n,1));
        }else {
            rep(i,k)tmp[i]=a[args[i]];
            rep(i,k){
                update(args[i],a[args[i]]=tmp[(i+1)%k],1,n,1);
            }
        }
    }
}
int main(){
    while(~sf("%d%d",&n,&Q)){
        init();
        solve();
    }
    return 0;
}


