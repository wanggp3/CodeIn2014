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
const int N=5005;
using namespace std;
struct node{
    int p1[2],p2[2],val;
    bool operator<(const node& other)const {
        return val<other.val;
    }
}a[N],b[N],tmp;
int tot,n;
LL ans;
void init(){
    ans=0;
    tot=-1;
}
void input(){
    sf("%d",&n);
    rep(i,n){
        sf("%d%d%d%d%d",&a[i].p1[0],&a[i].p1[1],&a[i].p2[0],&a[i].p2[1],&a[i].val);
    }
}
bool cover(node lhs,node rhs){
    rep(i,2){
        if(lhs.p2[i]<=rhs.p1[i]||lhs.p1[i]>=rhs.p2[i])return false;
    }
    return true;
}
void cut(node other){
    rep(i,2){
        int k1=max(other.p1[i],tmp.p1[i]);
        int k2=min(other.p2[i],tmp.p2[i]);
        if(k1>other.p1[i]){
            b[++tot]=other;
            b[tot].p2[i]=k1;
        }
        if(k2<other.p2[i]){
            b[++tot]=other;
            b[tot].p1[i]=k2;
        }
        other.p1[i]=k1;
        other.p2[i]=k2;
    }
}
void solve(){
    sort(a,a+n);
    rep(i,n){
        tmp=a[i];
        for(int j=tot;j>=0;j--){
            if(cover(tmp,b[j])){
                cut(b[j]);
                b[j]=b[tot--];
            }
        }
        b[++tot]=tmp;
    }
    rep(i,tot+1){
        ans+=(LL)b[i].val*(b[i].p2[0]-b[i].p1[0])*(b[i].p2[1]-b[i].p1[1]);
    }
    pf("%I64d\n",ans);
}
int main(){
    int T;
    sf("%d",&T);
    rep(cas,T){
        init();
        input();
        pf("Case %d: ",cas+1);
        solve();
    }
    return 0;
}

