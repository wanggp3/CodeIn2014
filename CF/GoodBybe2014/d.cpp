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
const int N=110005;
using namespace std;
typedef pair<int,int>PII;
int n,Q;
double ans=0;
double num=0;
int head[N];
int e;
struct Edge{
    int v,w,next;
}E[2*N+100];
int size[N];
int Left[2*N+100],Right[2*N+100];
void init(){
    e=0;
    ans=0;
    num=1.0*n*(n-1)*(n-2);
    memset(head,-1,sizeof head);
}
void addedge(int u,int v,int w){
    E[e].next=head[u];
    E[e].w=w;
    E[e].v=v;
    head[u]=e++;
}
void dfs(int u,int fa,int id){
    size[u]=1;
    for(int i=head[u];~i;i=E[i].next){
        int v=E[i].v;
        if(v==fa)continue;
        dfs(v,u,i);
        size[u]+=size[v];
    }
    if(id!=-1){
        Left[id]=Left[id^1]=size[u];
        Right[id]=Right[id^1]=n-size[u];
    }
}
void bug(){
    puts("bug");
    rep(i,e)pf("%d %d\n",Left[i],Right[i]);
    puts("");
}
void solve(){
    for(int i=0;i<n-1;i++){
        int u,v,w;
        sf("%d%d%d",&u,&v,&w);
        addedge(u,v,w);
        addedge(v,u,w);
    }
    dfs(1,0,-1);
    //bug();
    for(int i=0;i<e;i+=2){
        double add=0;
        if(Left[i]>=2){
            add+=(Left[i]*1.0*(Left[i]-1))/2.0*Right[i]*2*E[i].w;
        }
        if(Right[i]>=2){
            add+=(Right[i]*1.0*(Right[i]-1))/2.0*Left[i]*2*E[i].w;
        }
        ans+=add;
    }
    ans*=6.0;
    //pf("ans =%lf\n",ans);
    //pf("%.6lf\n",ans/num);
    sf("%d",&Q);
    while(Q--){
        int a,b;
        sf("%d%d",&a,&b);
        a--;
        double sub=0;
        int sz;
        sz=Left[a<<1];
        if(sz>=2){
            sub+=(sz*1.0*(sz-1))/2.0*Right[a<<1]*2;
        }
        sz=Right[a<<1];
        if(sz>=2){
            sub+=(sz*1.0*(sz-1))/2.0*Left[a<<1]*2;
        }
        ans-=(E[a<<1].w-b)*1.0*sub*6;
        E[a<<1].w=b;
        E[(a<<1)^1].w=b;
        pf("%.7lf\n",ans/num);
    }
}
int main(){
    while(~sf("%d",&n)){
        init();
        solve();
    }
    return 0;
}


