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
const int N=67;
using namespace std;
int stick[N];
bool vis[N];
int n;
int sum=0;
int Len=0;
void init(){
    memset(vis,0,sizeof vis);
    sum=0;
    rep(i,n){
        sf("%d",&stick[i]);
        sum+=stick[i];
    }
    sort(stick,stick+n,greater<int>());
}
bool dfs(int now,int id,int cnt){
   if(Len*cnt==sum)return 1;
   for(int i=id;i<n;i++){
       if(vis[i]||(i&&!vis[i-1]&&stick[i]==stick[i-1]))continue;
       if(now+stick[i]==Len){
           vis[i]=true;
           if(dfs(0,0,cnt+1))return true;
           vis[i]=0;
           return false;
       }else if(now+stick[i]<Len){
            vis[i]=1;
            if(dfs(now+stick[i],i+1,cnt))return 1;
            vis[i]=0;
            if(now==0)return 0;
       }
   }
   return 0;
}
void solve(){
    for(Len=stick[0];Len<=sum;Len++){
        if(sum%Len)continue;
        memset(vis,0,sizeof vis);
        if(dfs(0,0,0)){
            pf("%d\n",Len);
            break;
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

