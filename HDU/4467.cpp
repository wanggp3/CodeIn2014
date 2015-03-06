//By team8__
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <complex>
#include <cstring>
#include <iomanip>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define fab(i, a, b) for(int i=(a); i<=(b); i++)
#define PB push_back
#define MP make_pair
#define LL long long
#define sf scanf
#define pf printf
const int N = 110000;
int n,m;
int head[N],next[N*2],to[N*2];
LL WW[N*2];
int headW[N],nextW[N*2],toW[N*2];
LL W[N*2];
int used[N*2],col[N],d[N],isweight[N];
LL weight[N][2];
int e=0,eW;
LL light0_0,light0_1,light1_1;
LL weight0_0,weight0_1,weight1_1;
vector<int>cal;
int ecnt;
void bug();
struct Edge{
    int u,v;
    LL w;
    Edge(int u=0,int v=0,LL w=0):u(u),v(v),w(w){}
    bool operator<(const Edge& rhs)const{
        if(u!=rhs.u)return u<rhs.u;
        else if(v!=rhs.v)return v<rhs.v;
        else return w<rhs.w;
    }
}E[N*2];
void init(){
    cal.clear();
    e=eW=ecnt=0;
    light1_1=light0_0=light0_1=0;
    weight0_0=weight0_1=weight1_1=0;
   memset(used,0,sizeof used);
   memset(headW,-1,sizeof headW);
   memset(head,-1,sizeof head);
   memset(weight,0,sizeof weight);
   memset(d,0,sizeof d);
   memset(col,0,sizeof col);
   memset(isweight,0,sizeof isweight);
}
void addedge(int u,int v,LL w){
    d[v]++;
    to[e]=v;
    W[e]=w;
    next[e]=head[u];
    head[u]=e++;
}
void addedgeW(int u,int v,LL w){
    toW[eW]=v;
    WW[eW]=w;
    nextW[eW]=headW[u];
    headW[u]=eW++;
}
void input(){
   fab(i,1,n)sf("%d",&col[i]);
   rep(i,m){
       used[i]=0;
       int u,v;
       LL w;
       sf("%d%d%I64d",&u,&v,&w);
       if(u>v)swap(u,v);
       E[i].u=u;E[i].v=v;E[i].w=w;
       //addedge(u,v,w);
       //addedge(v,u,w);
   }
    sort(E,E+m);
    ecnt=0;
    for(int i=1;i<m;i++){
        if(E[i].u==E[ecnt].u&&E[i].v==E[ecnt].v)E[ecnt].w+=E[i].w;
        else{
            ecnt++;
            E[ecnt].u=E[i].u;
            E[ecnt].v=E[i].v;
            E[ecnt].w=E[i].w;
        }
    }
    for(int i=0;i<=ecnt;i++){
        addedge(E[i].u,E[i].v,E[i].w);
        addedge(E[i].v,E[i].u,E[i].w);
    }
}
void predo(){
    int mid=sqrt(n+0.5);
    fab(i,1,n){
        if(d[i]>mid){
            isweight[i]=1;
            cal.PB(i);
        }else{
            isweight[i]=0;
        }
    }
    fab(u,1,n){
        if(isweight[u]){
             for(int p=head[u];~p;p=next[p]){
                 int v=to[p];
                 if(isweight[v]&&v<u){
                     addedgeW(u,v,W[p]);
                     continue;
                 }
                 LL w=W[p];
                 weight[u][col[v]]+=w;
                 if(col[u]!=col[v])weight0_1+=w;
                 else{
                     if(col[u])weight1_1+=w;
                     else weight0_0+=w;
                 }
             }
        }else{
             for(int p=head[u];~p;p=next[p]){
                 int v=to[p];
                 if(isweight[v]||v<u)continue;
                 LL w=W[p];
                 if(col[v]!=col[u]){
                     light0_1+=w;
                 }else{
                     if(col[u])light1_1+=w;
                     else light0_0+=w;
                 }
             }
        }
    }
}
void Change(int x){
    if(isweight[x]){
        if(col[x]){
            weight0_1-=weight[x][0];
            weight1_1-=weight[x][1];
            weight0_1+=weight[x][1];
            weight0_0+=weight[x][0];
        }else{
            weight0_1-=weight[x][1];
            weight0_0-=weight[x][0];
            weight1_1+=weight[x][1];
            weight0_1+=weight[x][0];
        }
        for(int p=headW[x];~p;p=nextW[p]){
            int v=toW[p];
            LL w=WW[p];
            weight[v][col[x]]-=w;
            weight[v][col[x]^1]+=w;
            if(col[v]!=col[x]){
                weight0_1-=w;
                if(col[x]==0)weight1_1+=w;
                else weight0_0+=w;
            }else{
                if(col[x])weight1_1-=w;
                else weight0_0-=w;
                weight0_1+=w;
            }
        }
    }else{
        for(int p=head[x];~p;p=next[p]){
            int v=to[p];
            LL w=W[p];
            if(isweight[v]){
                 weight[v][col[x]]-=w;
                 weight[v][col[x]^1]+=w;
                 int a=col[v],b=col[x];
                 if(a!=b){
                     weight0_1-=w;
                     if(b)weight0_0+=w;
                     else weight1_1+=w;
                 }else{
                     if(a)weight1_1-=w;
                     else weight0_0-=w;
                     weight0_1+=w;
                 }
            }else{
                 if(col[x]!=col[v]){
                    light0_1-=w;
                    if(col[x])light0_0+=w;
                    else light1_1+=w;
                 }
                 else {
                     if(col[x]==0){
                        light0_0-=w;
                     }else {
                         light1_1-=w;
                     }
                     light0_1+=w;
                 }
            }
        }
    }
    col[x]^=1;
}
void Asksum(int a,int b){
    LL ans=0;
    
    if(a!=b){
        ans=light0_1+weight0_1;
    }else{
        if(a)ans=light1_1+weight1_1;
      else ans=light0_0+weight0_0;                                                                                               }
/*   
    if(a!=b)ans=light0_1;
    else if(a)ans=light1_1+weight1_1;
    else ans=light0_0+weight0_0;
    rep(i,cal.size()){
        int u=cal[i];
        if(a==0&&b==0){
            if(col[u]==0)ans+=weight[u][0];
        }else if((a==0&&b==1)||(a==1&&b==0)){
            ans+=weight[u][col[u]^1];
        }else if(a==1&&b==1){
            if(col[u])ans+=weight[u][1];
        }
    }*/
    pf("%I64d\n",ans);
}
void solve(){
     int Q;
     sf("%d",&Q);
     char op[20];
     int a,b;
     while(Q--){
        // bug();
        sf("%s",op);
        if(op[0]=='A'){
            sf("%d%d",&a,&b);
            Asksum(a,b);
        }else if(op[0]=='C'){
            sf("%d",&a);
            Change(a);
        }
     }
}
void bug(){
    puts("bug");
    /*fab(i,1,n){
        pf("is i = %d  weight %d\n",i,isweight[i]);
    }*/
    pf("light 0_0 = %I64d  0_1 = %I64d  1_1 = %I64d\n",light0_0,light0_1,light1_1);
    pf("weight 0_0 = %I64d  0_1 = %I64d  1_1 = %I64d\n",weight0_0,weight0_1,weight1_1);
    fab(i,1,n){
        if(isweight[i]){
            pf(" wieght i= %d:\n",i);
            pf(" --0 = %I64d    |  ---1 = %I64d \n",weight[i][0],weight[i][1]);
        }
    }
    /*
    fab(i,1,n){
        pf("i = %d :\n",i);
        for(int p=headW[i];~p;p=nextW[p])pf("%d ",to[p]);puts("");
    }*/
}
int main() {
    freopen("in","r",stdin);
    freopen("mywa","w",stdout);
    int cas=1;
    while(~sf("%d%d",&n,&m)){
        pf("Case %d:\n",cas++);
        init();
        input();
        predo();
       // bug();
        solve();
    }
    return 0;
}
