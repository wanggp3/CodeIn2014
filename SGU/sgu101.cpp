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
const int N=7;
using namespace std;
struct Edge{
    int v,next,id;
}G[201];
int head[N],f[N],d[N];
bool used[201];
int ans[201];
int n,tot,num;
int find(int x){
    return x==f[x]?x:f[x]=find(f[x]);
}
void merge_(int u,int v){
    int fu=find(u),fv=find(v);
    if(fu!=fv)f[fu]=fv;
}
void dfs(int u){
    for(int p=head[u];~p;p=G[p].next){
        if(used[p])continue;
        used[p]=used[p^1]=1;
        dfs(G[p].v);
        ans[num++]=G[p].id;
    }
}
void init(){
    tot=num=0;
    memset(ans,0,sizeof ans);
    memset(used,0,sizeof used);
    memset(head,-1,sizeof head);
    memset(d,0,sizeof d);
    rep(i,7)f[i]=i;
    int u,v;
    fab(i,1,n){
        sf("%d%d",&u,&v);
        G[tot].v=v;
        G[tot].next=head[u];
        G[tot].id=i;
        head[u]=tot++;
    
        G[tot].v=u;
        G[tot].next=head[v];
        G[tot].id=-i;
        head[v]=tot++;

        merge_(u,v);
        d[u]++;
        d[v]++;
       /* rep(j,7){
            pf("the i %d : fafa %d %d\n",i,j,find(j));
        }*/
    }
}
void solve(){
    int odd=0;
    int root;
    bool flag=0;
    bool fir=1;
    rep(i,7){
       // pf("fa %d %d\n",i,find(i));
        if(d[i]==0)continue;
        if(d[i]&1)odd++;
        if(fir)root=find(i),fir=0;
        else if(find(i)!=root)flag=1;
    }
    //pf("%d %d\n",flag,odd);
    if(flag||odd>2)puts("No solution");
    else{
        if(odd==0)dfs(G[0].v);
        else{
            rep(i,7){
                if(d[i]&1){
                    dfs(i);
                    break;
                }
            }
        }
        for(int i=num-1;i>=0;i--){
            pf("%d %c\n",(int)abs(ans[i]),ans[i]>0?'+':'-');
        }
    }
}
int main(){
    while(~sf("%d",&n)){
        init();
        solve();
    }
    return 0;
}

