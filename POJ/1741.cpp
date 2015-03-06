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
#define cls0(x) memset(x,0,sizeof(x))
#define cls1(x) memset(x,-1,sizeof(x))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1
#define LL long long
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define sf scanf
#define pf printf
const int N=10005;
using namespace std;
int size[N],dep[N];
bool vis[N];
int n,k,u,v,w,minx,le,ri;
struct Edge{
    int v,w;
    Edge(int v=0,int w=0):v(v),w(w){

    }
};
vector<Edge>G[N];
void init(){
    rep(i,N){
        G[i].clear();
        vis[i]=dep[i]=size[i]=0;
    }
}
void input(){
    rep(i,n-1){
        sf("%d%d%d",&u,&v,&w);
        G[u].PB(Edge(v,w));
        G[v].PB(Edge(u,w));
    }
}
int getsize(int u,int fa){
    size[u]=1;
    rep(i,G[u].size()){
        int v=G[u][i].v;
        if(v==fa||vis[v])continue;
        size[u]+=getsize(v,u);
    }
    return size[u];
}
void getroot(int u,int fa,int nodesize,int& root){
    int maxx=nodesize-size[u];
    rep(i,G[u].size()){
        int v=G[u][i].v;
        if(v==fa||vis[v])continue;
        getroot(v,u,nodesize,root);
        maxx=max(maxx,size[v]);
    }
    if(maxx<minx){
        minx=maxx;
        root=u;
    }
}
void getdep(int u,int fa,int d){
    dep[ri++]=d;
    rep(i,G[u].size()){
        int v=G[u][i].v;
        if(v==fa||vis[v])continue;
        getdep(v,u,d+G[u][i].w);
    }
}
int getans(int a,int b){
    sort(dep+a,dep+b);
    int ret=0,e=b-1;
    for(int i=a;i<b;i++){
        if(dep[i]>k)break;
        while(e>=a&&dep[e]+dep[i]>k)e--;
        ret+=e-a+1;
        if(e>i)ret--;
    }
    return ret>>1;
}
int solve(int u){
    int ret=0;
    minx=INF;
    int root=0;
    int nodesize=getsize(u,-1);
    //pf("size %d %d\n",u,nodesize);
    getroot(u,-1,nodesize,root);
    vis[root]=1;
    rep(i,G[root].size()){
        int v=G[root][i].v;
        if(vis[v])continue;
        ret+=solve(v);
    }
    le=ri=0;
    rep(i,G[root].size()){
        int v=G[root][i].v;
        if(vis[v])continue;
        getdep(v,root,G[root][i].w);
        ret-=getans(le,ri);
        le=ri;
    }
    ret+=getans(0,ri);
    /*pf("bug\n");rep(i,ri){
        pf("%d ",dep[i]);
    }*/
    rep(i,ri){
        if(dep[i]<=k)ret++;
        else break;
    }
    vis[root]=0;
    return ret;
}
int main(){
    while(~sf("%d%d",&n,&k)&&(n+k)){
        init();
        input();
        pf("%d\n",solve(1));
    }
    return 0;
}
