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
const int N=1005;
using namespace std;
int n;
int a[N];
int sum=0,maxLen;
bool ok=1;
bool vis[N];
void init(){
    memset(vis,0,sizeof vis);
    sum=0;
    maxLen=0;
    sf("%d",&n);
    rep(i,n){
        sf("%d",&a[i]);
        sum+=a[i];
        maxLen=max(maxLen,a[i]);
   
    }
}
bool dfs(int id,int len,int cnt){
    if(cnt==4)return 1;
    for(int i=id;i<n;i++){
        if(vis[i]||(i&&!vis[i-1]&&a[i]==a[i-1]))continue;
        if(len+a[i]==maxLen){
            vis[i]=1;
            if(dfs(0,0,cnt+1))return 1;
            vis[i]=0;
            return 0;
        }else if(len+a[i]<maxLen){
            vis[i]=1;
            if(dfs(i+1,len+a[i],cnt))return 1;
            vis[i]=0;
            if(len==0)return 0;
        }
    }
    return 0;
}
void solve(){
   sort(a,a+n,greater<int>());
   if(sum%4||4*maxLen>sum){
       ok=0;
   }else{
       maxLen=sum/4;
       ok=dfs(0,0,0);
   }
   if(ok)puts("yes");
   else puts("no");
}
int main(){
    int T;sf("%d",&T);
    while(T--){
        init();
        solve();
    }
    return 0;
}

