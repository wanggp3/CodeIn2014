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
#define cls0(x) memset(x,0,sizeof(x))
#define cls1(x) memset(x,-1,sizeof(x))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1
#define LL long long 
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define sf scanf
#define pf printf 
const int N=405;
using namespace std;
LL g[N][N];
int dx[]={-1,0,0,1};
int dy[]={0,1,-1,0};
bool vis[N][N];
LL ans;
int n,m;
bool bound(int x,int y){
    return x&&x<=n&&y&&y<=m;
}
struct Node{
   int x,y;
   LL h;
   Node(int x=0,int y=0,LL h=0):x(x),y(y),h(h){
   }
   bool operator<(const Node& rhs)const{
       return h>rhs.h;
   }
};
priority_queue<Node>PQ;
void solve(){
   cls0(vis);
   for(int i=1;i<=n;i++){
       PQ.push(Node(i,1,g[i][1]));
       PQ.push(Node(i,m,g[i][m]));
       vis[i][1]=vis[i][m]=1;
   }
   for(int i=2;i<m;i++){
       PQ.push(Node(1,i,g[1][i]));
       PQ.push(Node(n,i,g[n][i]));
       vis[1][i]=vis[n][i]=1;
   }
   while(!PQ.empty()){
       Node cur=PQ.top();PQ.pop();
       rep(i,4){
           int x=cur.x+dx[i];
           int y=cur.y+dy[i];
           if(bound(x,y)&&vis[x][y]==0){
               if(g[x][y]<cur.h){
                   ans+=cur.h-g[x][y];
                   PQ.push(Node(x,y,cur.h));
               }else{
                   PQ.push(Node(x,y,g[x][y]));
               }
               vis[x][y]=1;
           }
       }
   }
   pf("%lld\n",ans);
}
int main(){
    while(~sf("%d%d",&m,&n)){
        rep(i,n)rep(j,m)sf("%lld",&g[i+1][j+1]);
        ans=0;
        solve();
    }
    return 0;
}

