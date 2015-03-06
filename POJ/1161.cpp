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
const int N=305;
using namespace std;
vector<int>G[N];
int d[N][N],a[N],b[N];
int mp[N][N];
int n,m,L;
int v[N];
void init(){
    rep(i,N)G[i].clear();
    rep(i,N)rep(j,N)d[i][j]=(i==j?0:INF);
    memset(mp,0,sizeof mp);
    memset(v,0,sizeof v);
    memset(b,0,sizeof b);
    memset(a,0,sizeof a);
}
void solve(){
    sf("%d",&L);
    fab(i,1,L){
        sf("%d",&a[i]);
        v[a[i]]=i;
    }
    int I;
    fab(i,1,m){
        sf("%d",&I);
        rep(j,I){
            sf("%d",&b[j]);
            if(v[b[j]])G[a[v[b[j]]]].PB(i);
        }
        rep(j,I){
            int c=mp[b[j]][b[(j+1)%I]];
            if(c)d[i][c]=d[c][i]=1;
            else mp[b[j]][b[(j+1)%I]]=mp[b[(j+1)%I]][b[j]]=i;
        }
    }
    fab(k,1,m){
        fab(i,1,m){
            fab(j,1,m){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    int ans=INF;
    fab(i,1,m){
        int tmp1=0;
        fab(j,1,L){
            int tmp2=INF;
            rep(k,G[a[j]].size()){
                int to=G[a[j]][k];
                if(d[to][i]<tmp2)tmp2=d[to][i];
            }
            tmp1+=tmp2;
        }
        ans=min(ans,tmp1);
    }
    pf("%d\n",ans);
}
int main(){
    while(~sf("%d%d",&m,&n)){
        init();
        solve();
    }
    return 0;
}

