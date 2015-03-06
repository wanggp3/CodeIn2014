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
#define INF 0x3f3f3f
#define MP make_pair
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define sf scanf
#define pf printf
#define LL long long
const int N=555;
using namespace std;
typedef pair<int,int>PII;
int n,m;
struct Edge{
    int v,next,w;
}E[N*7];
int e=0;
int head[N],cnt[N],d[N];
bool inq[N];
int L,R,M;
void addEdge(int u,int v,int w){
    E[e].v=v;
    E[e].w=w;
    E[e].next=head[u];
    head[u]=e++;
}
void init(){
    memset(head,-1,sizeof head);
    e=0;
    int u,v,w;
    R=0;
   rep(i,m){
       sf("%d%d%d",&u,&v,&w);
       R=max(R,w);
       addEdge(u,v,w);
   }
}
queue<int>Q;
bool bellman(){
    while(!Q.empty())Q.pop();
    fab(i,1,n){
        Q.push(i);
        d[i]=0;
        inq[i]=1;
        cnt[i]=0;
    }
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        inq[u]=0;
        for(int p=head[u];~p;p=E[p].next){
            int v=E[p].v;
            int w=E[p].w;
          //  pf("v%d u%d w%d\n",d[v],d[u],w);
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                if(!inq[v]){
                    inq[v]=1;
                    Q.push(v);
                    if(++cnt[v]>n)return 0;
                }
            }
        }
    }
    return 1;
}
bool ok(int x){
    rep(i,e)E[i].w-=x;
    //rep(i,e)pf("edge %d\n",E[i].w);
    bool ret=bellman();
    //fab(i,1,n)pf("cnt %d\n",cnt[i]);pf("\n");
    rep(i,e)E[i].w+=x;
    return ret;
}
void solve(){
    if(ok(R))puts("Infinite");
    else if(!ok(1))puts("No Solution");
    else{
       L=2;
       int ans=1;
       while(L<R){
           M=(L+R)>>1;
           if(!ok(M))R=M;
           else L=M+1,ans=M;
       }
      pf("%d\n",ans);
    }
}
int main(){
    while(~sf("%d%d",&n,&m)){
        init();
        solve();
    }
    return 0;
}


