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
const int N=11005;
using namespace std;
typedef pair<int,int>PII;
struct Node{
    int now,pre,dig;
    Node(int now=0,int pre=0,int dig=0):now(now),pre(pre),dig(dig){}
}Q[N];
bool vis[N];
int n,m,L,R;
int dig[10];
int a[10];
void print(int id){
    if(Q[id].pre!=-1)print(Q[id].pre);
    pf("%d",Q[id].dig);
}
void init(){
    memset(a,0,sizeof a);
    memset(dig,0,sizeof dig);
    memset(vis,0,sizeof vis);
    L=0,R=0;
}
void bug(){
    puts("bug");
    rep(i,m){
        pf("%d\n",dig[i]);
    }
}
void solve(){
    rep(i,m){
        int x;sf("%d",&x);a[x]=1;
    }
    m=0;
    rep(i,10)if(!a[i])dig[m++]=i;
    if(m==0){
        puts("-1");
        return;
    }
    //bug();
    int ans=-1;
    rep(i,m){
        if(!dig[i])continue;
        Q[R].pre=-1;
        Q[R].now=dig[i]%n;
        vis[Q[R].now]=1;
        Q[R].dig=dig[i];
        if(Q[R].now==0){
            pf("%d\n",dig[i]);
            return;
        }
        R++;
    }
    while(L<R&&ans==-1&&R<N){
        rep(i,m){
            Q[R].now=(Q[L].now*10+dig[i])%n;
            if(vis[Q[R].now])continue;
            vis[Q[R].now]=1;
            Q[R].pre=L;
            Q[R].dig=dig[i];
            if(Q[R].now==0){
                ans=R;
                break;
            }
            R++;
        }
        L++;
    }
    if(ans==-1||R>=N)puts("-1");
    else{
       print(ans);
       puts("");
    }
}
int main(){
    int cas=1;
    while(~sf("%d%d",&n,&m)){
        pf("Case %d: ",cas++);
        init();
        solve();
    }
    return 0;
}


