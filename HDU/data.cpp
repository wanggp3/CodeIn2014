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
const int N=10;
using namespace std;
typedef pair<int,int>PII;
void get(int n,int m){
   cout<<n<<' '<<m<<endl;
   rep(i,n)cout<<rand()%2<<' ';cout<<endl;
   rep(i,m){
       int u,v;
       int w;
       do{
           u=rand()%n+1;
           v=rand()%n+1;
           w=rand()%n+1;
       }while(u==v);
       cout<<u<<' '<<v<<' '<<w<<endl;
   }
   int Q=rand()%n+1;
   cout<<Q<<endl;
   rep(i,Q){
       int op=rand()%2;
       if(op==0){
           int a=rand()%2,b=rand()%2;
           cout<<"Asksum"<<' '<<a<<' '<<b<<endl;
       }else{
           int x=rand()%n+1;
           cout<<"Change"<<' '<<x<<endl;
       }
   }
}
int main(){
    srand(0);
    freopen("in","w",stdout);
    rep(i,N){
        int n=rand()%5+5,m=rand()%5+5;
        get(n,m);
    }
    return 0;
}


