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
const int N=3000;
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
    void add(int a,int b){
        G[a].PB(b);
    }
    void clearmark(){
        memset(mark,0,sizeof mark);
    }
    void pop(int i){
        G[i].pop_back();
    }
}g;
int tag[N];
void solve(int n){
    string ans="";
    rep(i,n){
       int flag=0;
       g.clearmark();
       g.add(i<<1,i<<1|1);
       if(g.solve())flag|=1;
       g.pop(i<<1);
       g.clearmark();
       g.add(i<<1|1,i<<1);
       if(g.solve())flag|=2;
       g.pop(i<<1|1);
       if(flag==0){
           puts("impossible");
           return ;
       }else if(flag==1)ans+='y';
       else if(flag==2)ans+='n';
       else ans+='?';
    }
    cout<<ans<<endl;
}
int main(){
    int n,m,cas=1;
    while(~sf("%d%d",&n,&m)&&(n+m)){
        pf("Case %d: ",cas++);
        g.init(n);
        int k;
        while(m--){
           sf("%d",&k);
           rep(i,k){
               int u;
               char ch;
               sf("%d",&u);
               u--;
               while((ch=getchar())==' ')continue;
               tag[i]=2*u+(ch=='y');
           }
           if(k<=2){
              rep(i,k)g.add(tag[i]^1,tag[i]);
           }else{
              rep(i,k){
                  rep(j,k){
                      if(i!=j)g.add(tag[i]^1,tag[j]);
                  }
              }
           }
        }
        solve(n);
    }
    return 0;
}
