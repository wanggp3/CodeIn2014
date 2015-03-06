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
const int N=20005;
const int M=1000010;
using namespace std;
typedef pair<int,int>PII;
int wa[N],wb[N],wv[N],wd[M];
int rank[N],h[N],sa[N];
int K,n,a[N];
int cmp(int *r,int a,int b,int l){
    return r[a]==r[b] && r[a+l]==r[b+l];
}
void Da(int* r,int n,int m){
    int i,j,p,*x=wa,*y=wb;
    rep(i,m)wd[i]=0;
    rep(i,n)wd[x[i]=r[i]]++;
    fab(i,1,m-1)wd[i]+=wd[i-1];
    fba(i,n-1,0)sa[--wd[x[i]]]=i;
    for(j=1,p=1;p<n;j*=2,m=p){
        p=0;
        fab(i,n-j,n-1)y[p++]=i;
        rep(i,n)if(sa[i]>=j)y[p++]=sa[i]-j;
        rep(i,n)wv[i]=x[y[i]];
        rep(i,m)wd[i]=0;
        rep(i,n)wd[wv[i]]++;
        fab(i,1,m-1)wd[i]+=wd[i-1];
        fba(i,n-1,0)sa[--wd[wv[i]]]=y[i];
        swap(x,y);p=1;x[sa[0]]=0;
        fab(i,1,n-1)x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
}
void calH(int* r,int n){
    fab(i,1,n)rank[sa[i]]=i;
    for(int i=0,k=0,j;i<n;h[rank[i++]]=k)
        for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
}
void init(){
   rep(i,n)sf("%d",&a[i]);
   a[n]=0;
}
void fix(int n){
    rep(i,n)sa[i]=sa[i+1],rank[i]--,h[i]=h[i+1];
}
void solve(){
    Da(a,n+1,M);
    calH(a,n);
    fix(n);
    int L=1,R=n;
    int ans=1;
    while(L<=R){
        int mid=(L+R)>>1;
        int cnt=1;
        rep(i,n){
            if(h[i]>=mid)cnt++;
            else cnt=1;
            if(cnt>=K)break;
        }
        if(cnt>=K)L=mid+1,ans=mid;
        else R=mid-1;
        
    }
    pf("%d\n",ans);
}
int main(){
    while(~sf("%d%d",&n,&K)){
        init();
        solve();
    }
    return 0;
}


