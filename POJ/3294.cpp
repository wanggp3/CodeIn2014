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
const int N=100105;
const int M=100105;
using namespace std;
typedef pair<int,int>PII;
int wa[N],wb[N],wv[N],wd[M];
int sa[N],rank[N],height[N];
int cmp(int *r, int a, int b, int l){  
    return r[a] == r[b] && r[a+l] == r[b+l];  
}  
//r数组的长度n从[0,n)
//求出的sa为从[1,n]
//调用时候r[n-1]=0
void da(int *r, int n, int m){          //  倍增算法 r为待匹配数组  n为总长度 m为字符范围  
    int i, j, p, *x = wa, *y = wb, *t;  
    for(i = 0; i < m; i ++) wd[i] = 0;  
    for(i = 0; i < n; i ++) wd[x[i]=r[i]] ++;  
    for(i = 1; i < m; i ++) wd[i] += wd[i-1];  
    for(i = n-1; i >= 0; i --) sa[-- wd[x[i]]] = i;  
    for(j = 1, p = 1; p < n; j *= 2, m = p){  
        for(p = 0, i = n-j; i < n; i ++) y[p ++] = i;  
        for(i = 0; i < n; i ++) if(sa[i] >= j) y[p ++] = sa[i] - j;  
        for(i = 0; i < n; i ++) wv[i] = x[y[i]];  
        for(i = 0; i < m; i ++) wd[i] = 0;  
        for(i = 0; i < n; i ++) wd[wv[i]] ++;  
        for(i = 1; i < m; i ++) wd[i] += wd[i-1];  
        for(i = n-1; i >= 0; i --) sa[-- wd[wv[i]]] = y[i];  
        for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i ++){  
            x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p - 1: p ++;  
        }  
    }  
}  
// 求出的 height [1,n] 对应sa中的[1,n]
// 求出的 rank [0,n-1] 对应sa中的[1,n]
// 调用时候最后添加的0不用加进去
void calHeight(int *r, int n){           //  求height数组。  
    int i, j, k = 0;  
    for(i = 1; i <= n; i ++) rank[sa[i]] = i;  
    for(i = 0; i < n; height[rank[i++]] = k){  
        for(k ? k -- : 0, j = sa[rank[i]-1]; r[i+k] == r[j+k]; k ++);  
    }  
}
/*
//为了统一，所有的下标从0开始,左闭右开！
void fix(int n){
    rep(i,n)sa[i]=sa[i+1],rank[i]--,height[i]=height[i+1];
}*/
char str[1100];
int a[N],no[N],vis[110]={0};
int len=0,cas=0,n;
int ans[N],num=0,id=0;
void init(){
    id=0;
    if(cas)puts("");
    cas=1;
    len=0;
    int add=50;
    fab(i,1,n){
        sf("%s",str);
        int t=strlen(str);
        rep(j,t){
           a[len]=str[j]-'a'+1;
           no[len]=i;
           len++;
        }
        a[len]=add++;
        no[len++]=0;
    }
    //puts("a");rep(i,len)pf("%d",a[i]);puts("");
    --len;
    a[len]=0;
    da(a,len+1,300);
    calHeight(a,len);
}
bool ok(int k){
   int cnt=0,j;
   bool flag=0;
   for(int i=2;i<=len;i=j+1){
      while(height[i]<k&&i<=len)i++;
      j=i;
      while( height[j]>=k && j<=len )j++;
      if(j-i+1<n/2+1)continue;
      //cout<<"length = "<<k<<"from to "<< i-1<<' '<<j-1<<endl;
      id++;cnt=0;
      for(int t=i-1;t<j;t++)
      if(vis[no[sa[t]]]!=id)
              vis[no[sa[t]]]=id,cnt++;
      if(cnt>=n/2+1)
         if(flag)
             ans[num++]=sa[i-1];
         else
             flag=1, ans[num=0]=sa[i-1],num++;
       
      
   }
   return flag;
}
void print(int k){
    rep(i,num){
        int st=ans[i];
        rep(j,k)putchar(a[st+j]+'a'-1);puts("");
    }
}
void solve(){
    if(n==1)pf("%s\n",str);
    else {
        int L=1,R=1001;
        int mid,ans=0;
        while(L<=R){
            mid=L+(R-L)/2;
            if(ok(mid)){
                ans=mid;
                L=mid+1;
            }else R=mid-1;
        }
        if(ans==0)puts("?");
        else {
            print(ans);
        }
    }
}
int main(){
    while(~sf("%d",&n)&&n){
        init();
        solve();
    }
    return 0;
}


