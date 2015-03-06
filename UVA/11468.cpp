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
const int N=1005;
using namespace std;
typedef pair<int,int>PII;
const int maxnode=20*20+100;
const int sg=65;
int k,n;
char str[29][29];
int idx[266];
struct AC{
    int ch[maxnode][sg],f[maxnode],match[maxnode];
    int sz;
    void init(){
        memset(ch[0],0,sizeof ch[0]);
        sz=1;
        memset(match,0,sizeof match);
    }
    void insert(char* s){
        int n=strlen(s),u;
        rep(i,n){
          int c=idx[s[i]];
          if(!ch[u][c]){
              memset(ch[sz],0,sizeof ch[sz]);
              match[sz]=0;
              ch[u][c]=sz++;
          }
          u=ch[u][c];
        }
        match[u]=1;
    }
    void getFail(){
        queue<int>Q;
        f[0]=0;
        rep(c,sg){
            int u=ch[0][c];
            if(u){
                Q.push(u);
                f[u]=0;
            }
        }
        while(!Q.empty()){
            int r=Q.front();Q.pop();
            rep(c,sg){
                int u=ch[r][c];
                if(!u){
                    ch[r][c]=ch[f[r]][c];
                    continue;
                }
                Q.push(u);
                int v=f[r];
                while(v&&!ch[v][c])v=f[v];
                f[u]=ch[v][c];
                match[u]|=match[f[u]];
            }
        }
    }
}ac;
bool vis[maxnode][105];
double pr[105];
double dp[maxnode][105];
double dfs(int u,int L){
   if(!L)return 1.0;
   if(vis[u][L])return dp[u][L];
   double& ans=dp[u][L];
   ans=0;
   vis[u][L]=1;
   rep(i,n){
       if(!ac.match[ac.ch[u][i]])ans+=pr[i]*dfs(ac.ch[u][i],L-1);
   }
   return ans;
}
void init(int cas){
   sf("%d",&k);
   rep(i,k){
       sf("%s",str[i]);
   }
   sf("%d",&n);
   rep(i,n){
       char tmp[5];
       sf("%s",tmp);
       sf("%lf",&pr[i]);
       idx[tmp[0]]=i;
   }
   ac.init();
   rep(i,k)ac.insert(str[i]);
   ac.getFail();
   int L;
   sf("%d",&L);
   memset(vis,0,sizeof vis);
   pf("Case #%d: %.6lf\n",cas,dfs(0,L));
}
int main(){
    int T;sf("%d",&T);
    rep(cas,T){
        init(cas+1);
    }
    return 0;
}


