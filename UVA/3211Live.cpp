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
const int N=2005;
using namespace std;
int n;
int L,R;
int T[N][2];
struct Twosat{
    int n;
    vector<int>G[N*2];
    bool mark[N*2];
    int S[N*2],c;
    bool dfs(int x){
        if(mark[x^1])return false;
        if(mark[x])return true;
        mark[x]=1;
        S[c++]=x;
        rep(i,G[x].size()){
            if(!dfs(G[x][i]))return false;
        }
        return true;
    }
    void init(int n){
        this->n=n;
        rep(i,n*2)G[i].clear();
        memset(mark,0,sizeof mark);
    }
    void addedge(int x,int vx,int y,int vy){
        x=x*2+vx;
        y=y*2+vy;
        G[x^1].PB(y);
        G[y^1].PB(x);
    }
    bool solve(){
        for(int i=0;i<2*n;i+=2){
            if(!mark[i]&&!mark[i+1]){
                c=0;
                if(!dfs(i)){
                    while(c>0)mark[S[--c]]=false;
                    if(!dfs(i+1))return false;
                }
            }
        }
        return true;
    }
}solver;
void init(){
    L=0,R=0;
    rep(i,n){
        rep(j,2){
            sf("%d",&T[i][j]);
            R=max(R,T[i][j]);
        }
    }
}
bool ok(int M){
  solver.init(n);
  rep(i,n){
      rep(a,2){
          for(int j=i+1;j<n;j++){
              rep(b,2){
                  if(abs(T[i][a]-T[j][b])<M)solver.addedge(i,a^1,j,b^1);
              }
          }
      }
  }
  return solver.solve();
}
void solve(){
    R++;
    while(L+1<R){
       // pf("%d %d\n",L,R);
        int M=(L+R)>>1;
        if(ok(M))L=M;
        else R=M;
    }
    pf("%d\n",L);
}
int main(){
    while(~sf("%d",&n)&&n){
        init();
        solve();
    }
    return 0;
}

