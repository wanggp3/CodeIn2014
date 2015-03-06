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
const int N=30005;
using namespace std;
typedef pair<int,int>PII;
int top[N];
int n,father[N],dep[N],son[N],size[N],tree[N],id[N];
int value[N];
struct Edge{int v,next;}E[N*3];
int ecnt,tcnt;
int head[N];
int sum[N<<2],maxv[N<<2];
void addedge(int u,int v){
    E[ecnt].v=v;
    E[ecnt].next=head[u];
    head[u]=ecnt++;
}
void init(){
   memset(head,-1,sizeof head);
   memset(son,0,sizeof son);
   ecnt=0;
   tcnt=0;
}
char C;
void read(int &x){
    while(C=getchar(),C<'0'||C>'9');x=C-'0';
    while(C=getchar(),C>='0'&&C<='9')x=x*10+C-'0';
}
void input(){
    int u,v;
    for(int i=1;i<n;i++){
        read(u);read(v);
        addedge(u,v);
        addedge(v,u);
    }
    fab(i,1,n){
        sf("%d",&value[i]);
        //read(value[i]);
    }
}
void dfs1(int u,int fa,int d){
    dep[u]=d;
    father[u]=fa;
    size[u]=1;
    for(int i=head[u];~i;i=E[i].next){
       int v=E[i].v;
       if(v==fa)continue;
       dfs1(v,u,d+1);
       size[u]+=size[v];
       if(!son[u]||size[v]>size[son[u]])son[u]=v;
    }
}
void dfs2(int u,int t){
    top[u]=t;
    tree[u]=++tcnt;
    id[tcnt]=u;
    if(!son[u])return;
    dfs2(son[u],t);
    for(int i=head[u];~i;i=E[i].next){
        int v=E[i].v;
        if(v!=son[u]&&v!=father[u])dfs2(v,v);
    }
}
void push_up(int rt){
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
    maxv[rt]=max(maxv[rt<<1],maxv[rt<<1|1]);
}
void build(int l,int r,int rt){
    if(l==r){
        sum[rt]=maxv[rt]=value[id[l]];
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    push_up(rt);
}
int query_max(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R){
        return maxv[rt];
    }
    int m=(l+r)>>1;
    int ret=-INF;
    if(L<=m)ret=max(ret,query_max(L,R,lson));
    if(R>m)ret=max(ret,query_max(L,R,rson));
    return ret;
}
int findmax(int L,int R){
    int f1=top[L],f2=top[R],ret=-INF;
    while(f1!=f2){
        if(dep[f1]<dep[f2]){
            swap(f1,f2);
            swap(L,R);
        }
        ret=max(ret,query_max(tree[f1],tree[L],1,n,1));
        L=father[f1];
        f1=top[L];
    }
    if(dep[L]<dep[R])swap(L,R);
    ret=max(ret,query_max(tree[R],tree[L],1,n,1));
    return ret;
}
void update(int p,int v,int l,int r,int rt){
    if(l==r){
        maxv[rt]=sum[rt]=v;
        return ;
    }
    int m=(l+r)>>1;
    if(p<=m)update(p,v,lson);
    else if(p>m)update(p,v,rson);
    push_up(rt);
}
int query_sum(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R){
        return sum[rt];
    }
    int m=(l+r)>>1;
    int ret=0;
    if(L<=m)ret+=query_sum(L,R,lson);
    if(R>m)ret+=query_sum(L,R,rson);
    return ret;
}
int findsum(int L,int R){
    int f1=top[L],f2=top[R],ret=0;
    while(f1!=f2){
        if(dep[f1]<dep[f2]){
            swap(f1,f2);
            swap(L,R);
        }
        ret+=query_sum(tree[f1],tree[L],1,n,1);
        L=father[f1];
        f1=top[L];
    }
    if(dep[L]<dep[R])swap(L,R);
    ret+=query_sum(tree[R],tree[L],1,n,1);
    return ret;
}
void print(int a){
    if(a<0){
        putchar('-');
        a=-a;
    }
    if(a>=10)print(a/10);
    putchar(a%10+'0');
}
void solve(){
    dfs1(1,0,1);
    dfs2(1,1);
    build(1,n,1);
    int Q;sf("%d",&Q);
    char op[20];
    int x,y;
    while(Q--){
        sf("%s %d %d",op,&x,&y);
        if(op[0]=='C')update(tree[x],y,1,n,1),value[x]=y;
        else if(op[1]=='M')print(findmax(x,y)),puts("");
        else print(findsum(x,y)),puts("");
    }
}
int main(){
    while(~sf("%d",&n)){
        init();
        input();
        solve();
    }
    return 0;
}


