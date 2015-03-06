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
#define INF 0x3f3f3f3f3f3f3f3f
#define MP make_pair
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define sf scanf
#define pf printf
const int N=2005;
#define LL long long
using namespace std;
typedef pair<LL,int>PII;
int n,m;
LL L;
struct Edge{
    int v,next,id;
    LL w;
}E[N];
int e;
LL d[N];
bool used[N][N];
int head[N];
LL tmp[N];
int fa[N];
void addEdge(int u,int v,LL w,int id){
    E[e].v=v;
    E[e].id=id;
    E[e].w=w;
    E[e].next=head[u];
    head[u]=e++;
}
void init(){
    memset(head,-1,sizeof head);
    memset(used,0,sizeof used);
    e=0;
    int u,v;
    LL w;
    rep(i,m){
      sf("%d%d%lld",&u,&v,&w);
      u--;v--;
      if(u==v)continue;
      addEdge(u,v,w,i);
      addEdge(v,u,w,i);
    }
}
priority_queue<PII,vector<PII>,greater<PII> >Q;
LL Dijkstra(int s,int tag){
    while(!Q.empty())Q.pop();
    fill(d,d+n,INF);
    memset(fa,-1,sizeof fa);
    d[s]=0;
    Q.push(MP(0,s));
    while(!Q.empty()){
        PII x=Q.top();Q.pop();
        int u=x.second;
        if(d[u]!=x.first)continue;
        for(int p=head[u];~p;p=E[p].next){
            if(tag==E[p].id)continue;
            int v=E[p].v;
            if(d[v]>d[u]+E[p].w){
                d[v]=d[u]+E[p].w;
                fa[v]=E[p].id;
                Q.push(MP(d[v],v));
            }
        }
    }
    if(tag==-1){
      rep(i,n){
        if(fa[i]!=-1)used[s][fa[i]]=1;
      }
    }
    LL ret=0;
    rep(i,n){
        if(d[i]!=INF)ret+=d[i];
        else ret+=L;
    }
    return ret;
}
void solve(){
    LL ans1=0,ans2=0;
    rep(i,n){
        tmp[i]=Dijkstra(i,-1);
        ans1+=tmp[i];
    }
    rep(i,m){
       LL ans=0;
       rep(j,n){
           if(used[j][i])ans+=Dijkstra(j,i);
           else ans+=tmp[j];
       }
       ans2=max(ans2,ans);
    }
    pf("%lld %lld\n",ans1,ans2);
}
int main(){
    //cout<<INF<<endl;
    while(~sf("%d%d%lld",&n,&m,&L)){
        init();
        solve();
    }
    return 0;
}
