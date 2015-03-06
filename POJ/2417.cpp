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
//const int N=1005;
using namespace std;
const int maxn=65537;
struct hash_map{
   int head[maxn],size;
   int next[maxn];
   LL state[maxn],val[maxn];
   void init(){
       memset(head,-1,sizeof head);
       size = 0;
   }
   void insert(LL st ,LL sv){
       LL h=st%maxn;
       for(LL p=head[h];~p;p=next[p]){
           if(state[p]==st)return;
       }
       state[size]=st;val[size]=sv;
       next[size] = head[h];
       head[h]=size++;
   }
   LL find(LL st){
       LL h=st%maxn;
       for(LL p=head[h];~p;p=next[p])
           if(state[p]==st)return val[p];
       return -1;
   }
}hashmap;

LL mul_mod(LL a,LL b,LL n){
    return a*b%n;
}
LL _pow_mod(LL a,LL p,LL n){
    if(p==0)return 1;
    LL ans=_pow_mod(a,p/2,n);
    ans=ans*ans%n;
    if(p&1)ans=ans*a%n;
    return ans;
}
LL pow_mod(LL x,LL p,LL n){
    LL ret=1;
    while(p){
        if(p&1)ret=ret*x%n;
        x=x*x%n;
        p/=2;
    }
    return ret;
}
void gcd(LL a,LL b,LL &d,LL& x,LL &y){
    if(!b){
        d=a;
        x=1;
        y=0;
    }else{
        gcd(b,a%b,d,y,x);
        y-=x*(a/b);
    }
}
LL _inv(LL a,LL n){
    LL d,x,y;
    gcd(a,n,d,x,y);
    return d==1?(x+n)%n:-1;
}
LL inv(LL a,LL n){
    if(a==1)return 1;
    return((n-n/a)*inv(n%a,n))%n;
}
LL baby(LL a,LL b,LL n){
  LL e=1,m=(LL)(ceil(sqrt(n+0.5)));
  hashmap.init();
  hashmap.insert(1,0);
  for(int i=1;i<m;i++){
      e=e*a%n;
      hashmap.insert(e,i);
  }
  LL v=inv(pow_mod(a,m,n),n);
  for(int i=0;i<m;i++){
      LL t=hashmap.find(b);
      if(t!=-1)return i*m +t;
      b=(b*v)%n;
  }
  return -1;
}
LL log_mod(LL a,LL b,LL n){
    hashmap.init();
    LL m,v,e=1,i;
    m=(LL)sqrt(n+0.5);
    v=inv(pow_mod(a,m,n),n);
    //map<LL,LL>x;
    //x[1]=0;
    hashmap.insert(1,0);
    for(i=1;i<m;i++){
        e=mul_mod(e,a,n);
        if(hashmap.find(e)==-1)hashmap.insert(e,i);//x[e]=i;
    }
    for(i=0;i<m;i++){
        if(hashmap.find(b)!=-1)return i*m+hashmap.find(b);
        b=mul_mod(b,v,n);
    }
    return -1;
}
int main(){
    LL P,B,N;
    while(~sf("%I64d%I64d%I64d",&P,&B,&N)){
         LL ans=log_mod(B,N,P);
         // LL ans=baby(B,N,P);
        if(ans!=-1) printf("%I64d\n",ans);
        else puts("no solution");
    }
    return 0;
}

