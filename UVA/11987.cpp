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
const int N=200015;
using namespace std;
typedef pair<int,int>PII;
int n,m,fa[N],num[N],sum[N];
void init(){
    fab(i,1,n){
        fa[i]=i+n;
        fa[i+n]=i+n;
        num[i+n]=num[i]=1;
        sum[i+n]=sum[i]=i;
    }
}
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void solve(){
    while(m--){
        int op;sf("%d",&op);
        int p,q;
        if(op==1){
            sf("%d%d",&p,&q);
            int x=find(p);
            int y=find(q);
            if(x==y)continue;
            fa[x]=y;
            sum[y]+=sum[x];
            num[y]+=num[x];
        }else if(op==2){
            sf("%d%d",&p,&q);
            int x=find(p);
            int y=find(q);
            if(x==y)continue;
            fa[p]=y;
            sum[y]+=p;
            sum[x]-=p;
            num[y]++;
            num[x]--;
        }else if(op==3){
            sf("%d",&p);
            int x=find(p);
            pf("%d %d\n",num[x],sum[x]);
        }
    }
}
int main(){
    while(~sf("%d%d",&n,&m)){
        init();
        solve();
    }
    return 0;
}


