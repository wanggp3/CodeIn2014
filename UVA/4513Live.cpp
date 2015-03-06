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
#define LL unsigned long long
const int N=41005;
using namespace std;
typedef pair<int,int>PII;
const int X=113;
int n,m,pos;
char str[N];
LL xp[N],H[N],Hash[N];
void pre(){
    H[n]=0;
    fba(i,n-1,0)H[i]=H[i+1]*X+(str[i]-'a');
    xp[0]=1;
    fab(i,1,n)xp[i]=xp[i-1]*X;
}
void init(){
   sf("%s",str);
   n=strlen(str);
}
int P[N];
bool cmp(const int& i,const int &j){
    return Hash[i]<Hash[j]||Hash[i]==Hash[j]&&i<j;
}
bool ok(int k){
   pos=-1;
   int cnt=0;
   rep(i,n-k+1){
       P[i]=i;
       Hash[i]=H[i]-H[i+k]*xp[k];
   }
   sort(P,P+n-k+1,cmp);
   rep(i,n-k+1){
       if(i==0||Hash[P[i]]!=Hash[P[i-1]])cnt=0;
       if(++cnt>=m)pos=max(pos,P[i]);
   }
   return pos>=0;
}
void solve(){
    if(!ok(1))pf("none\n");
    else{
        int L=1,R=n+1;
        while(L+1<R){
            int M=L+(R-L)/2;
            if(ok(M))L=M;
            else R=M;
        }
        ok(L);
        pf("%d %d\n",L,pos);
    }
}
int main(){
    while(~sf("%d",&m)&&m){
        init();
        pre();
        solve();
    }
    return 0;
}


