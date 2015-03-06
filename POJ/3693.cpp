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
using namespace std;
typedef pair<int,int>PII;
int wa[N],wb[N],wv[N],wd[N];
int sa[N],rank[N],height[N];
char str[N];
int a[N];
int cmp(int *r, int a, int b, int l){  
    return r[a] == r[b] && r[a+l] == r[b+l];  
}  
//r数组的长度n从[0,n)
//求出的sa为从[1,n]
//调用时候r[n-1]=0
void da(char *r, int n, int m){          //  倍增算法 r为待匹配数组  n为总长度 m为字符范围  
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
void calHeight(char *r, int n){           //  求height数组。  
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
int dp[N][30];
void init_rmq(int n){
    fab(i,1,n)dp[i][0]=height[i];
    for(int j=1;(1<<j)<=n;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
        }
    }
}
int cas=1;
int ans[N];
int rmq(int L,int R){
    L=rank[L],R=rank[R];
    if(L>R)swap(L,R);
    L++;
    int k=0;
    while((1<<(k+1))<=R-L+1)k++;
    return min(dp[L][k],dp[R-(1<<k)+1][k]);
}
void solve(){
    int n=strlen(str);
    str[n]=0;
    da(str,n+1,200);
    calHeight(str,n);
    init_rmq(n);
    int maxv=-1;
    int cnt=0;
    for(int len=1;len<n;len++){
       for(int i=0;i+len<n;i+=len){
           int lcp=rmq(i,i+len);
           int tmp=lcp/len+1;
           int ni=i-(len-lcp%len);
           if(ni>=0&&lcp%len!=0){
               tmp=max(tmp,rmq(ni,ni+len)/len+1);
           }
           if(tmp>maxv){
               maxv=tmp;
               cnt=0;
               ans[cnt++]=len;
           }else if(tmp==maxv){
               ans[cnt++]=len;
           }
       }
    }

    //pf("cnt ");rep(i,cnt)pf("%d ",ans[i]);pf("\n");
    int len=-1,st;
    for(int i=1;i<=n&&len==-1;i++){
        rep(j,cnt){
           if(rmq(sa[i],sa[i]+ans[j])>=(maxv-1)*ans[j]){
               len=ans[j]*maxv;
               st=sa[i];
               break;
           }
        }
    }
    //pf("st %d %d\n",st,len);
    pf("Case %d: ",cas++);
    rep(i,len)putchar(str[i+st]);
    puts("");
}
int main(){
    while(~sf("%s",str)&&str[0]!='#'){
        solve();
    }
    return 0;
}


