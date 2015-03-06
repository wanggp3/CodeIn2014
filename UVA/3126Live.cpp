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
struct Node{
    string t;
    int x[2],y[2];
}node[N];
int n,match[N];
bool g[N][N],vis[N];
void init(){
   memset(g,0,sizeof g);
}
void input(){
    sf("%d",&n);
    rep(i,n){
        cin>>node[i].t>>node[i].x[0]>>node[i].y[0]>>node[i].x[1]>>node[i].y[1];
    }
}
int gettime(string s){
  int a=(s[0]-'0')*10+(s[1]-'0');
  a=a*60;
  a+=(s[3]-'0')*10+(s[4]-'0');
  return a;
}
bool ok(int i,int j){
    int a=abs(node[i].x[0]-node[i].x[1])+abs(node[i].y[0]-node[i].y[1]);
    a+=abs(node[i].x[1]-node[j].x[0])+abs(node[i].y[1]-node[j].y[0]);
    //int b=abs(node[j].x[0]-node[j].y[0])+abs(node[j].x[1]-node[j].y[1]);
    //if(node[i].t>=node[j].t)return false;
    int t1=gettime(node[i].t),t2=gettime(node[j].t);
    //pf("i = %d j = %d end %d %d\n",i,j,t1+a,t2);
    if(t1+a<t2)return true;
    else return false;
}
bool find(int x){
    rep(y,n){
        if(g[x][y]&&!vis[y]){
            vis[y]=1;
            if(match[y]==-1||find(match[y])){
                match[y]=x;
                return true;
            }
        }
    }
    return false;
}
void bug(){
    puts("time");
    rep(i,n){
      pf("%d\n",gettime(node[i].t));
    }
    rep(i,n){
        rep(j,n)pf("%d ",g[i][j]);pf("\n");
    }
}
void solve(){
    rep(i,n){
        rep(j,n){
            if(i!=j){
                if(ok(i,j))g[i][j]=1;
                else g[i][j]=0;
            }
        }
    }
//    bug();
    memset(match,-1,sizeof match);
    int ans=0;
    rep(i,n){
        memset(vis,0,sizeof vis);
        if(find(i))ans++;
    }
    pf("%d\n",n-ans);
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


