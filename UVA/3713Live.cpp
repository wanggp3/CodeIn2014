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
const int N=200005;
using namespace std;
int n,m;
int sui[N];
int sum=0;
struct Twosat{
    int n;
    vector<int>G[N*2];
    bool mark[N*2],S[N*2];
    int c;
    bool dfs(int x){
        if(mark[x^1])return false;
        if(mark[x])return true;
        mark[x]=true;
        S[c++]=x;
        rep(i,G[x].size()){
            if(!dfs(G[x][i]))return false;
        }
        return true;
    }
    void init(int n){
        this->n=n;
        rep(i,n*2){
            G[i].clear();
        }
        memset(mark,0,sizeof mark);
    }
    void add(int x,int vx,int y,int vy){
        x=x<<1+vx;
        y=y<<1+vy;
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
}two;
bool young( int x){
    return x*n<sum;
}
void init(){
    sum=0;
    rep(i,n){
        sf("%d",&sui[i]);
        sum+=sui[i];
    }
    int u,v;
    two.init(n);
    rep(i,m){
        sf("%d %d",&u,&v);
        u--;v--;
        if(u==v)continue;
        if(young(sui[u])==young(sui[v])){
            two.add(u,1,v,1);
            two.add(u,0,v,0);
        }else{
            two.add(u,1,v,1);
        }
    }
}
void solve(){
    if(two.solve()){
       rep(i,n){
           if(two.mark[2*i])puts("C");
           else if(young(sui[i]))puts("B");
           else puts("A");
       }
    }else puts("No solution.");
}
int main(){
    while(~sf("%d%d",&n,&m)&&n){
        init();
        solve();
    }
    return 0;
}

