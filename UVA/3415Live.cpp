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
int X,Y,n;
struct Node{
    int h;
    string sex,music,exe;
}node[N];
int g[N][N];
int a[N],b[N];
int match[N];
bool vis[N];
void init(){
    X=Y=0;
}
void input(){
    sf("%d",&n);
    rep(i,n){
        cin>>node[i].h>>node[i].sex>>node[i].music>>node[i].exe;
        if(node[i].sex=="M")a[X++]=i;
        else b[Y++]=i;
    }
}
bool ok(int i,int j){
    if(abs(node[i].h-node[j].h)>40)return true;
    else if(node[i].music!=node[j].music)return true;
    else if(node[i].exe==node[j].exe)return true;
    return false;
}
bool find(int x){
    rep(j,Y){
        if(!ok(a[x],b[j])&&!vis[j]){
            vis[j]=1;
            if(match[j]==-1||find(match[j])){
                match[j]=x;
                return true;
            }
        }
    }
    return false;
}
void solve(){
    memset(match,-1,sizeof match);
    int ans=0;
    rep(i,X){
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


