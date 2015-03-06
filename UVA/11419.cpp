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
const int maxn=1005;
const int maxm=maxn*maxn;
using namespace std;
typedef pair<int,int>PII;
int R,C,n,e;
int head[maxn],next[maxm],to[maxm];
bool S[maxn],T[maxn];
int match[maxn];
void init(){
    memset(head,-1,sizeof head);
    memset(match,-1,sizeof match);
    e=0;
}
void addedge(int u,int v){
    to[e]=v;
    next[e]=head[u];
    head[u]=e++;
}
void input(){
    int u,v;
    rep(i,n){
        sf("%d%d",&u,&v);
        addedge(u,v);
    }
}
bool find(int x){
    S[x]=1;
    for(int p=head[x];~p;p=next[p]){
        if(!T[to[p]]){
            T[to[p]]=1;
            if(match[to[p]]==-1||find(match[to[p]])){
                match[to[p]]=x;
                return true;
            }
        }
    }
    return false;
}
bool tmp[maxn];
void solve(){
    int ans=0;
    fab(i,1,R){
        memset(S,0,sizeof S);
        memset(T,0,sizeof T);
        if(find(i))ans++;
    }
    memset(S,0,sizeof S);
    memset(T,0,sizeof T);
    memset(tmp,0,sizeof tmp);
    fab(i,1,C)tmp[match[i]]=1;
    fab(i,1,R)if(!tmp[i])find(i);
    pf("%d",ans);
    fab(i,1,R)if(!S[i])pf(" r%d",i);
    fab(i,1,C)if(T[i])pf(" c%d",i);
    puts("");
}
int main(){
    while(~sf("%d%d%d",&R,&C,&n)&&(n+R+C)){
        init();
        input();
        solve();
    }
    return 0;
}


