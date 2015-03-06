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
const int N=200015;
const int M=1005;
using namespace std;
typedef pair<int,int>PII;
int wa[N],wb[N],wv[N],wd[N];
int sa[N],rank[N],h[N];
int a[N],sta[N];
char s1[N],s2[N];
LL ans;
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
// 求出的 h [1,n] 对应sa中的[1,n]
// 求出的 rank [0,n-1] 对应sa中的[1,n]
// 调用时候最后添加的0不用加进去
void calh(int *r, int n){           //  求h数组。  
    int i, j, k = 0;  
    for(i = 1; i <= n; i ++) rank[sa[i]] = i;  
    for(i = 0; i < n; h[rank[i++]] = k){  
        for(k ? k -- : 0, j = sa[rank[i]-1]; r[i+k] == r[j+k]; k ++);  
    }  
}
/*
//为了统一，所有的下标从0开始,左闭右开！
void fix(int n){
    rep(i,n)sa[i]=sa[i+1],rank[i]--,h[i]=h[i+1];
}*/
int len,len1;
int k;
void init(){
    sf("%s %s",s1,s2);
    len1=strlen(s1);
    rep(i,len1)a[i]=s1[i];
    a[len1]='$';
    len=strlen(s2);
    rep(i,len)a[len1+i+1]=s2[i];
    a[len1+len+1]=0;
    len+=len1+1;
    da(a,len+1,300);
    calh(a,len);
}
LL num[N];
void solve(){
    ans=0;
    LL tmp=0,tp=0;
    int tail=0;
    fab(i,1,len){
       if(h[i]<k)tmp=tail=0;
       else{
           tp=0;
           if(sa[i-1]>len1){
               tmp+=h[i]-k+1;
               tp=1;
           }
           while(tail>0&&sta[tail]>=h[i]){
               tmp-=num[tail]*(sta[tail]-h[i]);
               tp+=num[tail];
               tail--;
           }
           sta[++tail]=h[i];
           num[tail]=tp;
           if(sa[i]<len1)ans+=tmp;
       }
    }
    fab(i,1,len){
        if(h[i]<k)tail=tmp=0;
        else{
            tp=0;
            if(sa[i-1]<len1){
                tmp+=h[i]-k+1;
                tp=1;
            }
            while(tail>0&&sta[tail]>=h[i]){
                tmp-=num[tail]*(sta[tail]-h[i]);
                tp+=num[tail];
                tail--;
            }
            sta[++tail]=h[i];
            num[tail]=tp;
            if(sa[i]>len1)ans+=tmp;
        }
    }
    pf("%lld\n",ans);
}
int main(){
    while(~sf("%d",&k)&&k){
        init();
        solve();
    }
    return 0;
}


