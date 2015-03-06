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
const int N=10005;
using namespace std;
int father[N],trans[N],sum[N];
int n,q;
void init(){
    rep(i,N){
        father[i]=i;
        trans[i]=0;
        sum[i]=1;
    }
}
int find(int x){
   if(x==father[x])return x;
   else{
       int tmp=father[x];
       father[x]=find(tmp);
       trans[x]+=trans[tmp];
       return father[x];
   }
}
void Union(int a,int b){
   int fa=find(a),fb=find(b);
   if(fa!=fb){
       sum[fb]+=sum[fa];
       sum[fa]=0;
       trans[fa]++;
       father[fa]=fb;
   }
}
int main(){
    int T;
    sf("%d",&T);
    rep(cas,T){
        init();
        sf("%d %d",&n,&q);
        pf("Case %d:\n",cas+1);
        while(q--){
           char op[2];
           int a,b;
           sf("%s",op);
           if(op[0]=='T'){
               sf("%d %d",&a,&b);
               Union(a,b);
           }else {
               sf("%d",&a);
               int fa=find(a);
               pf("%d %d %d\n",fa,sum[fa],trans[a]);
           }
        }
    }
    return 0;
}


