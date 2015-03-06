//斯坦纳树模板 让k个点联通的最小生成树 复杂度 n*3^k 
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
int n,m,k;
queue<int>Q;
int dp[N][1<<10],st[N],all;
bool  vis[N][1<<10];
int dpans[1<<10];
const int M =10010;
int head[N];
int to[M],next[M],cost[M];
int e;
void init(){
    memset(head,-1,sizeof head);
    while(!Q.empty())Q.pop();
    e=0;
}
void addedge(int u,int v,int w){
    to[e]=v;
    cost[e]=w;
    next[e]=head[u];
    head[u]=e++;
}
void input(){
    sf("%d%d%d",&n,&m,&k);
    rep(i,m){
        int u,v,w;
        sf("%d%d%d",&u,&v,&w);
        u--;v--;
        addedge(u,v,w);
        addedge(v,u,w);
    }
}
void stma_init(){
    all=(1<<(2*k));
    rep(i,n)rep(j,all)dp[i][j]=INF;
    memset(st,0,sizeof st);
    memset(vis,0,sizeof vis);
    rep(i,k){
        st[i]=(1<<i);
        st[n-k+i]= (1<<(i+k));
        dp[i][st[i]]=0;
        dp[n-k+i][st[n-k+i]]=0;
    }
}

void spfa(int state){
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        vis[u][state]=false;
        for(int p=head[u];~p;p=next[p]){
            int v=to[p];
            int w=cost[p];
            if(dp[v][st[v]|state]>dp[u][state]+w){
                dp[v][st[v]|state]=dp[u][state]+w;
                if(st[v]|state!=state||vis[v][state])continue;
                vis[v][state]=1;
                Q.push(v);
            }
        }
    }
}
void STMA(){
    stma_init();
    for(int j=1;j<all;j++){
        rep(i,n){
           if(st[i]&&(st[i]&j)==0)continue;
           for(int sub=(j-1)&j;sub;sub=(sub-1)&j){
               int x=st[i]|sub,y=st[i]|(j-sub);
               dp[i][j]=min(dp[i][j],dp[i][x]+dp[i][y]);
           }
           if(dp[i][j]<INF){
               Q.push(i);
               vis[i][j]=true;
           }
        }
        spfa(j);
    }
}
/*
void spfa(){
    while(!Q.empty()){
        int j=Q.front()/1200;
        int i=Q.front()%1200;
        Q.pop();
        vis[j][i]=0;
        for(int p=head[j];~p;p=next[p]){
            int v=to[p],w=cost[p];
            int nxt=i|st[v];
            if(dp[j][i]+w<dp[v][nxt]){
                dp[v][nxt]=dp[j][i]+w;
                if(nxt==i&&!vis[v][nxt]){
                    vis[v][nxt]=1;
                    Q.push(v*1200+nxt);
                }
            }
        }
    }
}
void STMA(){
    stma_init();
    rep(i,all){
        rep(j,n){
            for(int t=(i-1)&i;t;t=(t-1)&i){
                dp[j][i]=min(dp[j][i],dp[j][t|st[j]]+dp[j][(i-t)|st[j]]);
            }
            if(dp[j][i]<INF){
                Q.push(j*1200+i);
                vis[j][i]=1;
            }
        }
        spfa();
    }
}*/
bool check(int s){
    int cnt=0;
    rep(i,k){
        if(s&(1<<i))cnt++;
        if(s&(1<<(k+i)))cnt--;
    }
    return cnt==0;
}
void bug(){
    puts("bug");
    pf("%d\n",all);
    rep(i,all)pf("%d ",dpans[i]);
}
void solve(){
   STMA();//模板，求出来的是一颗树


   //因为这道题的解可能是森林，所以要对求出来的东东再进行dp
   rep(i,all){
      dpans[i]=INF;
      rep(j,n)dpans[i]=min(dpans[i],dp[j][i]);
   }
   for(int i=1;i<all;i++){
       if(check(i)){
           for(int j=(i-1)&i;j;j=(j-1)&i){
               if(check(j))dpans[i]=min(dpans[i],dpans[j]+dpans[i-j]);
           }
       }
   }
   if(dpans[all-1]<INF)pf("%d\n",dpans[all-1]);
   else puts("No solution");
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


