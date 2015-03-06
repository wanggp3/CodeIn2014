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
const int N=21005;
using namespace std;
typedef pair<int,int>PII;
vector<PII>E;
vector<int>G[N],vec;
int pre[N],cnt[N*100],sta[N*100],ans[N*100],top,n,m;
void init(){
    memset(pre,0,sizeof pre);
    memset(cnt,0,sizeof cnt);
    memset(ans,0,sizeof ans);
    top=0;
    rep(i,N)G[i].clear();
    E.clear();
    vec.clear();
}
void input(){
    rep(i,m){
        int k,u,v;
        sf("%d%d",&k,&u);
        for(int j=1;j<k;j++){
            sf("%d",&v);
            E.PB(MP(u,v));
            G[u].PB(E.size()-1);
            G[v].PB(E.size()-1);
            u=v;
        }
    }
}
void dfs(int u,int fa,int lev){
    pre[u]=lev;
    rep(i,G[u].size()){
        PII x=E[G[u][i]];
        int v=(x.first==u?x.second:x.first);
        if(v==fa)continue;
        if(!pre[v]){
           sta[top++]=G[u][i];
           dfs(v,u,lev+1);
           --top;
        }else{
           if(pre[v]<=pre[u]){
               int k=pre[u]-pre[v];
               rep(j,k)cnt[sta[top-1-j]]++;
               cnt[G[u][i]]++;
               vec.PB(k+2);
           }
        }
    }
}
void bug(){
    rep(i,vec.size())pf("%d ",vec[i]);pf("\n");
}
int len;
void mul(int x){
    rep(i,len)ans[i]*=x;
    rep(i,len){
        ans[i+1]+=ans[i]/10;
        ans[i]%=10;
    }
    while(ans[len]){
        ans[len+1]+=ans[len]/10;
        ans[len]%=10;
        len++;
    }
}
void print(){
    len=1;
    ans[len-1]=1;
    rep(i,vec.size())mul(vec[i]);
    for(int i=len-1;i>=0;i--)pf("%d",ans[i]);
    puts("");
}
void solve(){
    dfs(1,0,1);
    int flag=1;
    fab(i,1,n)if(!pre[i])flag=0;
    rep(i,E.size())if(cnt[i]>1)flag=0;
    if(!flag)puts("0");
    else{
        print();
    }
}
int main(){
    int cas=0;
    while(~sf("%d%d",&n,&m)){
        if(cas++)puts("");
        init();
        input();
        solve();
    }
    return 0;
}


