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
const int N=32005;
using namespace std;
bool prime[N];
vector<int>P;
void pre(){
    memset(prime,0,sizeof prime);
    prime[1]=1;
    prime[0]=1;
    for(int i=2;i*i<N;i++){
        if(!prime[i]){
            for(int j=i*i;j<N;j+=i)prime[j]=1;
        }
    }
    rep(i,N)if(!prime[i])P.PB(i);
}
int n;
int a[11];
bool ok(int x){
    if(x==1)return false;
    for(int i=2;i*i<=x;i++){
        if(x%i==0)return false;
    }
    return true;
}
int get(int x){
    int U=sqrt(x+0.5);
    for(int i=0;P[i]<=U;i++){
        if(x%P[i]==0){
            if(ok(x/P[i]))return 1;
        }
    }
    return 0;
}
int main(){
    pre() ;
    sf("%d",&n);
    rep(i,n){
        sf("%d",&a[i]);
    }
    rep(i,n){
        a[i]=get(a[i]);
    }
    rep(i,n){
        if(a[i])puts("Yes");
        else puts("No");
    }
    return 0;
}

