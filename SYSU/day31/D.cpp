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
const int N=505;
using namespace std;
typedef pair<int,int>PII;
int n,m;
vector<int>G[N];
char g[N][N];
int ind[N];
vector<int>ans;
bool vis[N];
void init(){    
    memset(ind,0,sizeof ind);
    memset(vis,0,sizeof vis);
    ans.clear();
    rep(i,N)G[i].clear();
    rep(i,n){
        sf("%s",g[i]);
        rep(j,n){
            if(g[i][j]=='1')G[i+1].PB(j+1),ind[j+1]++;
        }
    }
}
int d[N][N];
void bfs(int s){
    memset(d[s],INF,sizeof d[s]);
    d[s][s]=0;
    queue<int>Q;
    Q.push(s);
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        rep(i,G[u].size()){
            int v=G[u][i];
            if(d[s][v]>d[s][u]+1){
                d[s][v]=d[s][u]+1;
                Q.push(v);
            }
        }
    }
}
bool ok(){
    fab(i,1,n)bfs(i);
    rep(i,ans.size()){
        for(int j=i+1;j<ans.size();j++){
            if(d[ans[j]][ans[i]]>2)return 0;
        }
    }
    return 1;
}
void solve(){
    fab(i,1,n){
        int inm=-1,inid=-1;
        fab(j,1,n){
            if(!vis[j]&&ind[j]>inm)inid=j,inm=ind[j];
        }
        if(inid==-1)break;
        ans.PB(inid);
        vis[inid]=1;
        rep(j,G[inid].size()){
            int v=G[inid][j];
            ind[v]--;
        }
    }
    if(ans.size()<n){
        pf("%d\n",-1);
    }else{
       for(int i=ans.size()-1;i>=0;i--){
           if(i==0)pf("%d\n",ans[0]);
           else pf("%d ",ans[i]);
       }
    }
    /*fab(i,1,n){
        fab(j,1,n)pf("%d ",d[i][j]);pf("\n");
    }*/
}
int main(){
    while(~sf("%d",&n)&&n){
        init();
        solve();
    }
    return 0;
}


