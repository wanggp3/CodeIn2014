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
const int maxn = 400005;
const int node=26;
struct Trie{
    int ch[maxn][node];
    int cnt[node];
    int sz;
    void init(){
        memset(ch[0],0,sizeof ch[0]);
        memset(cnt,0,sizeof cnt);
        sz=1;
    }
    int idx(char c){return c-'a';}
    void insert(char* s){
        int n=strlen(s),u=0;
        rep(i,n){
            int c=idx(s[i]);
            if(!ch[u][c]){
                memset(ch[sz],0,sizeof ch[sz]);
                ch[u][c]=sz++;
                if(i)cnt[c]++;
            }
            u=ch[u][c];
        }
    }
}pre,suf;
bool vis[node];
char s[200];
int n;
void init(){
    memset(vis,0,sizeof vis);
    pre.init();
    suf.init();
}
void solve(){
    rep(i,n){
        sf("%s",s);
        if(strlen(s)==1)vis[s[0]-'a']=1;
        pre.insert(s);
        reverse(s,s+strlen(s));
        suf.insert(s);
    }
    LL ans=0;
    ans=(LL)(pre.sz-1)*(suf.sz-1);
    rep(i,node)ans-=(LL)pre.cnt[i]*suf.cnt[i];
    rep(i,node)if(vis[i])ans++;
    pf("%lld\n",ans);
}
int main(){
    while(~sf("%d",&n)){
        init();
        solve();
    }
    return 0;
}


