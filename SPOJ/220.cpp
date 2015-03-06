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
const int N=110005;
using namespace std;
typedef pair<int,int>PII;
int wa[N],wb[N],wv[N],wd[N];
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
int n,r[N],minv[15],maxv[15],no[N],len;
char str[N];
void init(){
    memset(no,0,sizeof no);
}
bool ok(int k){
    memset(minv,-1,sizeof minv);
    memset(maxv,-1,sizeof maxv);
    fab(i,1,len){
        if(height[i]<k){
            int cnt=0;
            fab(j,1,n)if(maxv[j]-minv[j]>=k)cnt++;
            if(cnt==n)return true;
            memset(minv,-1,sizeof minv);
            memset(maxv,-1,sizeof maxv);
        }
        if(no[sa[i]]){
            if(maxv[no[sa[i]]]==-1)maxv[no[sa[i]]]=minv[no[sa[i]]]=sa[i];
            else{
                maxv[no[sa[i]]]=max(maxv[no[sa[i]]],sa[i]);
                minv[no[sa[i]]]=min(minv[no[sa[i]]],sa[i]);
            }
        }
    }
    int cnt=0;
    fab(i,1,n)if(maxv[i]-minv[i]>=k)cnt++;
    return cnt==n;
}
void solve(){
    sf("%d",&n);
    int L=0,R=INF;
    len=0;
    int add=33;
    fab(i,1,n){
        sf("%s",str);
        int t=strlen(str);
        R=min(t,R);
        rep(j,t){
           r[len]=str[j]-'a'+1;
           no[len++]=i;
        }
        r[len]=add++;
        no[len++]=0;
    }
    r[--len]=0;
    da(r,len+1,300);
    calHeight(r,len);
    while(L+1<R){
        int mid=L+(R-L)/2;
        if(ok(mid))L=mid;
        else R=mid;
    }
    pf("%d\n",L);
}
int main(){
    int T;sf("%d",&T);
    while(T--){
        init();
        solve();
    }
    return 0;
}


