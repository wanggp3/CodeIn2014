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
#define INF 0x3f3f3f3f3f3f3f
#define MP make_pair
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define sf scanf
#define pf printf
#define LL long long
const int N=3000005;
using namespace std;
typedef pair<int,int>PII;
struct Edge{
   int v,next;
   LL w;
   Edge(int v=0,LL w=0,int next=0):v(v),w(w),next(next){
   }
}E[2*N];
int e=0,n,m;
int cas=1;
LL W[N],d[N];
int head[N];
priority_queue<PII,vector<PII>,greater<PII> >Q;
void add(int u,int v,LL w){
    E[e].v=v;
    E[e].w=w;
    E[e].next=head[u];
    head[u]=e++;

    E[e].v=u;
    E[e].w=w;
    E[e].next=head[v];
    head[v]=e++;
}
int getid(int i,int j){return (i-1)*(m-1)+j;}
LL dijkstra(int s,int t){
    rep(i,N)d[i]=INF;
    Q.push(MP(0,s));
    d[s]=0;
    while(!Q.empty()){
        PII x=Q.top();Q.pop();
        int u=x.second;
        if(d[u]!=x.first)continue;
        for(int p=head[u];~p;p=E[p].next){
           int v=E[p].v;
           LL w=E[p].w;
           if(d[v]>d[u]+w){
               d[v]=d[u]+w;
               Q.push(MP(d[v],v));
           }
        }
    }
    return d[t];
}
void solve(){
   e=0;
   memset(head,-1,sizeof head); 
   while(!Q.empty())Q.pop();
   int s=0,t=2*(n-1)*(m-1)+1;
   fab(i,1,n){
       fab(j,1,m-1){
           LL x;
           sf("%lld",&x);
           if(i==1){
               int id=getid(i,j);
               add(2*id+1,t,x);
           }else if(i==n){
               int id=getid(i-1,j);
               add(s,2*id,x);
           }else{
               int id1=getid(i-1,j),id2=getid(i,j);
               add(2*id2+1,2*id1,x);
           }
       }
   }
   fab(i,1,n-1){
       fab(j,1,m){
           LL x;
           sf("%lld",&x);
           if(j==1){
              int id=getid(i,j);
              add(s,2*id,x);
           }else if(j==m){
              int id=getid(i,j-1);
              add(2*id+1,t,x);
           }else {
              int id1=getid(i,j-1);
              int id2=getid(i,j);
              add(2*id1+1,2*id2,x);
           }
       }
   }
   fab(i,1,n-1){
       fab(j,1,m-1){
           LL x;sf("%lld",&x);
           int id=getid(i,j);
           add(2*id+1,2*id,x);
       }
   }
   pf("Case %d: Minimum = %lld\n",cas++,dijkstra(s,t));
}
int main(){
    while(~sf("%d%d",&n,&m)&&(n+m)){
        solve();
    }
    return 0;
}


