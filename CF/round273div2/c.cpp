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
const int N=1005;
using namespace std;
typedef pair<int,int>PII;
int a[]={112,113,121,122,123,131,132,133,211,212,213,221,223,231,232,233,311,312,313,321,322,323,331,332};
int getbit(int x){
    int ret=0;
    while(x){
        ret+=(x&1);
        x>>=1;
    }
    return ret;
}
int cnt[4];
vector<int>v;
bool ok(int mask){
    memset(cnt,0,sizeof cnt);
    rep(i,24){
        if((mask>>i)&1){
            int tmp=a[i];
            while(tmp){
                int t=tmp%10;
                cnt[t]++;
                tmp/=10;
            }
        }
    }
    sort(cnt+1,cnt+4);
    return 1;
    for(int i=1;i<=3;i++){
        if(v[i-1]<cnt[i])return 0;
    }
    return 1;
}
set<int>S[28];
int main(){
    int x,y,z;
    sf("%d%d%d",&x,&y,&z);
    v.clear();
    v.PB(x);
    v.PB(y);
    v.PB(z);
    sort(v.begin(),v.end());
    int ans=0;
    rep(mask,1<<24){
       //if(ok(mask)){
          //ans=max(ans,getbit(mask));
               ok(mask);
              int tmp=cnt[1]*100+cnt[2]*10+cnt[3];
              S[getbit(mask)].insert(tmp);
          
       //}
    }
    for(int i=0;i<=27;i++){
        pf("%d : ",i);
    set<int>::iterator it=S[i].begin();
    while(it!=S[i].end()){
        pf("%d ",*it);
        it++;
    }
    pf("\n");
    }
   // pf("%d\n",ans);
    return 0;
}


