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
const int N=75;
using namespace std;
typedef pair<int,int>PII;
struct twosat{
    int n;
    vector<int>G[N];
    bool mark[N];
    int S[N],c;
    bool dfs(int x){
        if(mark[x^1])return false;
        if(mark[x])return true;
        mark[x]=true;
        S[c++]=x;
        rep(i,G[x].size())if(!dfs(G[x][i]))return false;
        return true;
    }
    void init(int n){
        this->n = n;
        rep(i,n<<1)G[i].clear();
        memset(mark,0,sizeof mark);
    }
    void addedge(int x,int xval,int y,int yval){
        x=x*2+xval;
        y=y*2+yval;
        G[x^1].PB(y);
        G[y^1].PB(x);
    }
    bool solve(){
        rep(i,n){
            if(!mark[i<<1]&&!mark[i<<1|1]){
                c=0;
                if(!dfs(i<<1)){
                    while(c>0)mark[S[--c]]=false;
                    if(!dfs(i<<1|1))return false;
                }
            }
        }
        return true;
    }
}g;
int main(){
    int n,m,x,y,u,v;
    char a,b;
    while(~sf("%d%d",&n,&m)&&(n+m)){
        g.init(n);
        g.mark[1]=1;
        rep(i,m){
            sf("%d%c %d%c",&x,&a,&y,&b);
            u=(a=='h'?0:1);
            v=(b=='h'?0:1);
            g.addedge(x,u,y,v);
        }
        if(!g.solve())puts("bad luck");
        else{
            for(int i=2;i<2*n;i+=2){
               if(i!=2)pf(" ");
               if(g.mark[i])pf("%dh",i/2);
               else pf("%dw",i/2);
            }
            puts("");
        }
    }
    return 0;
}


