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
const int N=55;
using namespace std;
typedef pair<int,int>PII;
struct Edge{
    int v,next;
    double w;
}E[N*N];
int e=0;
int n,m;
int head[N];
void addEdge(int u,int v,double w){
    E[e].v=v;
    E[e].w=w;
    E[e].next=head[u];
    head[u]=e++;
}
double L,R,M;
void init(){
    memset(head,-1,sizeof head);
    e=0;
    L=0,R=0;
    sf("%d%d",&n,&m);
    int u,v;
    double w;
    rep(i,m){
       sf("%d%d%lf",&u,&v,&w);
       R=max(R,w);
       addEdge(u,v,w);
    }
}
queue<int>Q;
bool inq[N];
int cnt[N];
double d[N];
bool bellman(){
    memset(inq,0,sizeof inq);
    memset(cnt,0,sizeof cnt);
    while(!Q.empty())Q.pop();
    fab(i,1,n){
        Q.push(i);
        d[i]=0;
        inq[i]=1;
    }
    //pf("init bell sucessi\n");
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        //pf("die %d\n",u);
        inq[u]=0;
        for(int p=head[u];~p;p=E[p].next){
            int v=E[p].v;
            double w=E[p].w;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                if(!inq[v]){
                    inq[v]=1;
                    Q.push(v);
                     ++cnt[v];
                    if(cnt[v]>n)return 1;
                }
            }
        }
    }
    //pf("bel end");
    return 0;
}
bool ok(double x){
    //pf("%lf ok run\n",x);
    rep(i,e)E[i].w-=x;
    bool ret=bellman();
    //pf("%lf bell run\n",x);
    rep(i,e)E[i].w+=x;
    return ret;
}
const double eps = 1e-3;
void solve(){
   if(!ok(INF)){
       puts("No cycle found.");
       return;
   }
  // pf("sssssssss\n");
   //return;
   L=-INF;R=INF;
   while(R-L>eps){
     //  puts("fuck you");
       M=(L+R)/2.0;
       if(ok(M))R=M;
       else L=M;
   }
   pf("%.2lf\n",R);
}
int main(){
    int T;
    sf("%d",&T);
    rep(cas,T){
        init();
        pf("Case #%d: ",cas+1);
        solve();
    }
    return 0;
}


