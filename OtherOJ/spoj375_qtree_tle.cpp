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
const int N=10025;
using namespace std;
typedef pair<int,int>PII;
int father[N],size[N],son[N],dep[N],tree[N],top[N];
struct Edge{int v,next;}E[N*2];
int ecnt,tcnt;
int head[N],d[N][3];
int n;
int maxv[N<<2];

void init(){
    memset(son,0,sizeof son);
    memset(head,-1,sizeof head);
    ecnt=tcnt=0;
}
void addedge(int u,int v){
    E[ecnt].v=v;
    E[ecnt].next=head[u];
    head[u]=ecnt++;
}
void dfs1(int u,int fa,int lev){
    size[u]=1;
    father[u]=fa;
    dep[u]=lev;
    for(int i=head[u];~i;i=E[i].next){
        int v=E[i].v;
        if(v==fa)continue;
        dfs1(v,u,lev+1);
        size[u]+=size[v];
        if(son[u]||size[son[u]]<size[v])son[u]=v;
    }
}
void input(){
    sf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v,w;
        sf("%d%d%d",&u,&v,&w);
        d[i][0]=u,d[i][1]=v,d[i][2]=w;
        addedge(u,v);
        addedge(v,u);
    }
}
void dfs2(int u,int t){
    top[u]=t;
    tree[u]=++tcnt;
    if(!son[u])return;
    dfs2(son[u],t);
    for(int i=head[u];~i;i=E[i].next){
        int v=E[i].v;
        if(v!=son[u]&&v!=father[u])dfs2(v,v);
    }
}
void push_up(int rt){
    maxv[rt]=max(maxv[rt<<1],maxv[rt<<1|1]);
}
void update(int p,int v,int l,int r,int rt){
    if(l==r){
        maxv[rt]=v;
        return;
    }
    int m=(l+r)>>1;
    if(p<=m)update(p,v,lson);
    if(p>m)update(p,v,rson);
    push_up(rt);
}
void Change(int x,int y){
    update(tree[d[x][1]],y,1,n,1);
}
int query_max(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R)return maxv[rt];
    int m=(l+r)>>1;
    int ret=-INF;
    if(L<=m)ret=max(ret,query_max(L,R,lson));
    if(R>m)ret=max(ret,query_max(L,R,rson));
    return ret;
}
int Query(int x,int y){
    int f1=top[x],f2=top[y],ret=-INF;
    while(f1!=f2){
        if(dep[f1]<dep[f2]){
            swap(f1,f2);
            swap(x,y);
        }
        ret=max(ret,query_max(tree[f1],tree[x],1,tcnt,1));
        x=father[f1];
        f1=top[f1];
    }
    if(x==y)return ret;
    if(dep[x]>dep[y]){
        swap(x,y);
    }
    return max(ret,query_max(tree[son[x]],tree[y],1,tcnt,1));
}
void solve(){
    dfs1(1,0,1);
    dfs2(1,1);
    for(int i=1;i<n;i++){
        if(dep[d[i][0]]>dep[d[i][1]])swap(d[i][0],d[i][1]);//!!
        update(tree[d[i][1]],d[i][2],1,tcnt,1);
    }
    char op[20];
    int x,y;
    while(sf("%s",op)&&op[0]!='D'){
        sf("%d%d",&x,&y);
        if(op[0]=='Q'){
            pf("%d\n",Query(x,y));
        }else if(op[0]=='C'){
            Change(x,y);
        }
    }
}
int main(){
    int T;sf("%d",&T);
    while(T--){
        init();
        input();
        solve();
    }
    return 0;
}


