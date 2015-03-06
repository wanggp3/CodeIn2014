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
#define lowbit(x) x&-x
#define MP make_pair
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define sf scanf
#define pf printf
#define LL long long
const int N=10005;
using namespace std;
typedef pair<int,int>PII;
struct Node{
    int x,y;
    int id;
    Node(int x=0,int y=0,int id=0):x(x),y(y),id(id){}
}P[N];
struct Line{
    Node a,b;
}line[N];
int C[N*2];
int sum(int x){
    int ret=0;
    while(x){
        ret+=C[x];
        x-=lowbit(x);
    }
    return ret;
}
void update(int x,int v){
    while(x<2*N){
        C[x]+=v;
        x+=lowbit(x);
    }
}
int L=0;
vector<int>G[N];
bool vis[N];
bool cmpx(const Node & lhs,const Node & rhs){
    return lhs.x<rhs.x || lhs.x==rhs.x&&lhs.y<rhs.y;
}
bool cmpy(const Node& lhs,const Node & rhs){
    return lhs.y<rhs.y || lhs.y==rhs.y&&lhs.x<rhs.x;
}
int n;

bool flag=1;
void init(){
    memset(vis,0,sizeof vis);
    memset(C,0,sizeof C);
    L=0;
    rep(i,N)G[i].clear();
    flag=1;
    rep(i,n){
        sf("%d%d",&P[i].x,&P[i].y);
        P[i].id=i;
    }
}
int dis(int i,int j){
    if(P[i].x==P[j].x)return abs(P[i].y-P[j].y);
    else return abs(P[i].x-P[j].x);
}
void dfs(int u){
    vis[u]=1;
    if(G[u].size()!=2){
        flag=0;
        return ;
    }
    rep(i,G[u].size()){
        int v=G[u][i];
        if(!vis[v])dfs(v);
    }
}
struct Tmp{
    int x,yl,yr,val;
    Tmp(int x=0,int yl=0,int yr=0,int val=0):x(x),yl(yl),yr(yr),val(val){}
    bool operator<(const Tmp& rhs)const{
        if(x!=rhs.x)return x<rhs.x;
        else if(val!=rhs.val)return val<rhs.val;
        else return yl<rhs.yl;
    }
}event[N*2];
int e=0;
void xj(){
    e=0;
   Tmp tmp;
   rep(i,L){
       if(line[i].a.x==line[i].b.x){
          tmp.x=line[i].a.x;
          tmp.yl=N+min(line[i].a.y,line[i].b.y);
          tmp.yr=N+max(line[i].a.y,line[i].b.y);
          tmp.val=0;
          event[e++]=tmp;
       }else{
          tmp.x=min(line[i].a.x,line[i].b.x);
          tmp.yl=tmp.yr=line[i].a.y+N;
          tmp.val=1;
          event[e++]=tmp;

          tmp.x=max(line[i].a.x,line[i].b.x);
          tmp.val=-1;
          event[e++]=tmp;
       }
   }
   sort(event,event+e);
   rep(i,e){
       tmp=event[i];
       if(tmp.val==1){
           update(tmp.yl,1);
       }else if(tmp.val==-1){
           update(tmp.yl,-1);
       }else if(tmp.val==0){
           int L=tmp.yl,R=tmp.yr;
           R--;
           if(L<=R){
               if(sum(R)-sum(L)>0){
                   flag=0;
                   break;
               }
           }
       }
   }
}
void solve(){
   sort(P,P+n,cmpx);
   L=0;
   for(int i=1;i<n;i++){
      if(P[i].x==P[i-1].x){
          G[P[i].id].PB(P[i-1].id);
          G[P[i-1].id].PB(P[i].id);
          line[L].a=P[i];
          line[L].b=P[i-1];
          L++;
          i++;
      }
   }

   sort(P,P+n,cmpy);
   for(int i=1;i<n;i++){
       if(P[i].y==P[i-1].y){
           G[P[i].id].PB(P[i-1].id);
           G[P[i-1].id].PB(P[i].id);
           line[L].a=P[i];
           line[L].b=P[i-1];
           L++;
           i++;
       }
   }
   int cnt=0;
   rep(i,n){
       if(cnt>1)break;
       if(!vis[i]){
           cnt++;
           dfs(i);
       }
   }
   if(!flag||cnt!=1)pf("%d\n",0);
   else {
       xj();
       if(!flag){
           pf("%d\n",0);
           return;
       }
       int ans=0;
       rep(i,n){
           rep(j,G[i].size()){
               int v=G[i][j];
               ans+=dis(i,v);
           }
       }
       pf("%d\n",ans/2);
   }
}
int main(){
    while(~sf("%d",&n)){
        init();
        solve();
    }
    return 0;
}


