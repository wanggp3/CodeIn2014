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
const int N=15;
using namespace std;
typedef pair<int,int>PII;
int key[1<<N],vis_ans[1<<N],vis[N][N],gate[N];
int lock[N][N];
int sx,sy;
char s[N][N];
bool win[1<<N];
queue<PII>Q;
int n,cnt;
int dx[]={-1,0,0,1};
int dy[]={0,1,-1,0};
bool bound(int i,int j){
    if(i>=0&&i<n&&j>=0&&j<n)return true;
    else return false;
}
void init(){
    cls0(lock);
    rep(i,N){
        vis_ans[i]=0;
        win[i]=0;
        key[i]=0;
        gate[i]=0;
    }
}
void bfs(int x){
    while(!Q.empty())Q.pop();
    cls0(vis);
    for(int i=0;i<cnt;i++){
        if((x>>i)&1)gate[x]++;
    }
    vis[sx][sy]=1;
    Q.push(MP(sx,sy));
    while(!Q.empty()){
        PII u=Q.front();Q.pop();
        rep(i,4){
            int nx=u.first+dx[i],ny=u.second+dy[i];
            if(bound(nx,ny)&&!vis[nx][ny]){
                vis[nx][ny]=1;
                if(s[nx][ny]=='L'&&((x>>lock[nx][ny])&1)||s[nx][ny]=='E'||s[nx][ny]=='S'||s[nx][ny]=='K'||s[nx][ny]=='.'){
                    if(s[nx][ny]=='E')win[x]=1;
                    if(s[nx][ny]=='K')key[x]++;
                    Q.push(MP(nx,ny));
                }
            }
        }
    }
}
queue<int>q;
bool BFS(){
    while(!q.empty())q.pop();
    vis_ans[0]=1;
    q.push(0);
    while(!q.empty()){
        int u=q.front();q.pop();
        if(win[u])return true;
        if(key[u]>gate[u]){
            rep(i,cnt){
                if(((u>>i)&1 )==0){
                    int v=u|(1<<i);
                    if(!vis_ans[v]){
                      vis_ans[v]=1;
                      q.push(v);
                    }
                }
            }
        }
    }
    return false;
}
int main(){
    int T;
    sf("%d",&T);
    rep(cas,T){
        init();
        sf("%d",&n);
        rep(i,n)sf("%s",s[i]);
        cnt=0;
        rep(i,n){
            rep(j,n){
                if(s[i][j]=='S'){
                    sx=i;sy=j;
                }
                if(s[i][j]=='L')lock[i][j]=cnt++;
            }
        }
        for(int i=0;i<(1<<cnt);i++){
            bfs(i);
        }
        pf("Case %d: %s\n",cas+1,BFS()?"Yes":"No");
    }
    return 0;
}

