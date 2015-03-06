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
int n,k,L,R;
int a[N],now[N],temp[N];
bool vis[N],vis1[N];
inline void init(){
    rep(i,n)sf("%d",&a[i]);
    R=-1;
}
inline void dfs1(int cur,int ans){
    vis1[ans]=1;
    if(cur==k)return;
    dfs1(cur+1,ans);
    dfs1(cur+1,ans^now[cur]);
}
inline void dfs(int cur,int p){
    if(cur==k){
        memset(vis1,0,sizeof vis1);
        dfs1(0,0);
        for(int i=L;i<=R;i++)if(!vis1[i])return;
        //memcpy(temp,now,sizeof now);
        rep(i,k)temp[i]=now[i];
        do{
            memset(vis,0,sizeof vis);
            rep(i,k){
                int v=0;
                rep(j,k){
                    vis[v^=temp[(i+j)%k]]=1;
                }
            }
            int j=L;
            while(vis[j])j++;
            R=max(R,j-1);
        }while(next_permutation(temp,temp+k));
    }else{
        for(int i=p;i<n;i++){
            now[cur]=a[i];
            dfs(cur+1,i+1);
        }
    }
}
inline void solve(){
    sort(a,a+n);
    dfs(0,0);
    if(R<L)pf("0\n");
    else pf("%d\n",R);
}
int main(){
    while(~sf("%d%d%d",&n,&k,&L)){
        init();
        solve();
    }
    return 0;
}


