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
#define cls(x) memset(x,0,sizeof(x))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define LL long long 
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define sf scanf
#define pf printf 
const int N=1005;
using namespace std;
int n,tot;
bool vis[N];
int ind[51],fa[51];
int head[51];
int u,v;
struct node{
    int v,next,id;
    node(int v=0,int next=0,int id=0)
        :v(v),next(next),id(id){}
}E[N*2];
vector<int>ans;
void add(int u,int v,int i){
    E[tot].v=v;
    E[tot].id=i;
    E[tot].next=head[u];
    head[u]=tot++;
}
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge_(int u,int v){
    int fu=find(u),fv=find(v);
    if(fu!=fv){
        fa[fu]=fv;
    }
}
void init(){
   tot=0;
   ans.clear();
   memset(head,-1,sizeof head);
   memset(ind,0,sizeof ind);
   memset(vis,0,sizeof vis);
   rep(i,51)fa[i]=i;
   sf("%d",&n);
   rep(i,n){
       sf("%d%d",&u,&v);
       add(u,v,i);
       add(v,u,i);
       ind[u]++;
       ind[v]++;
       //merge_(u,v);
   }
}
bool connect(){
    bool f=1;
    int root;
    fab(i,1,50){
        if(ind[i]!=0){
            if(ind[i]&1)return 0;
            /*if(f){
                root=find(i);
                f=0;
            }else if(root!=find(i))return 0;*/
        }
    }
    return 1;
}
void dfs(int u){
    for(int p=head[u];~p;p=E[p].next){
        if(vis[E[p].id])continue;
        vis[E[p].id]=1;
        dfs(E[p].v);
        pf("%d %d\n",E[p].v,u);
    }
    //ans.PB(u);
}
void print(){
    rep(i,ans.size()-1){
        pf("%d %d\n",ans[i],ans[i+1]);
    }
}
void solve(){
   if(!connect()){
       puts("some beads may be lost");
       return ;
   }else{
       dfs(u);
       //print();
   }
}
int main(){
    int T;sf("%d",&T);
    rep(cas,T){
        init();
        pf("Case #%d\n",cas+1);
        solve();
        if(cas<T-1)puts("");
    }
    return 0;
}

