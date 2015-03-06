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
const int N=1005;
using namespace std;
typedef pair<int,int>PII;
char s[N];
int sa[N],t[N],c[N],t2[N],n;
int rank[N],height[N];
void build(int n,int m=100){
    int *x=t,*y=t2;
    
    rep(i,m)c[i]=0;
    rep(i,n)c[x[i]=s[i]]++;
    fab(i,1,m-1)c[i]+=c[i-1];
    fba(i,n-1,0)sa[--c[x[i]]]=i;
    for(int k=1;k<=n;k<<=1){
       // rep(i,n)pf("%d ",sa[i]);pf("\n");
        int p=0;
        //sort second used sa
        fab(i,n-k,n-1)y[p++]=i;
        rep(i,n)if(sa[i]>=k)y[p++]=sa[i]-k;
        //sort the first 
        rep(i,m)c[i]=0;
        rep(i,n)c[x[y[i]]]++;
        rep(i,m)c[i]+=c[i-1];
        fba(i,n-1,0)sa[--c[x[y[i]]]]=y[i];
        //compute new x used sa and y
        swap(x,y);
        p=1;x[sa[0]]=0;
        fab(i,1,n-1)x[sa[i]]=y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++;
        if(p>=n)break;
        m=p;
    }
}
void getHeight(int n){
    rep(i,n)rank[sa[i]]=i;
    int k=0;
    rep(i,n){
      if(k)--k;
      int j=sa[rank[i]-1];
      while(s[i+k]==s[j+k])k++;
      height[rank[i]]=k;
    }
}
int find(char* P){
    int m=strlen(P);
    if(strncmp(P,s+sa[0],m)<0||strncmp(P,s+sa[n-1],m)>0)return -1;
    int L=0,R=n-1;
    while(L<=R){
        int M=(L+R)>>1;
        int t=strncmp(P,s+sa[M],m);
        if(t==0)return M;
        else if(t<0)R=M-1;
        else L=M+1;
    }
    return -1;
}
int main(){
    sf("%s",s);
    int m=strlen(s);
    s[m]='0';
    build(m+1,256);
    getHeight(m);
    rep(i,m+1){
        pf("%s %d %d\n",s+sa[i],height[i],rank[i]);
    }
    return 0;
}


