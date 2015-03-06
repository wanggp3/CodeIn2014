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
int a,b;
int cnt=0;
bool flag=1;
map<pair<int,int>,int>Map;
void work(int a,int b){
   // cout<<a<< ' ' << b<<endl;
    if(a>b)swap(a,b);
   if(a==b)return;
   else if((a+b)%2==1||Map.count(MP(a,b))){
       flag=0;
       return ;
   }
   else{
      // int g=__gcd(a,b);
       cnt++;
      // a/=g;
       //b/=g;
       if(a>b)swap(a,b);
       Map[MP(a,b)]=1;
       b-=a;
       a+=a;
       work(a,b);
   }
}
int main(){
    cin>>a>>b;
    if(a==0||b==0){
        cout<<0<<endl;
        return 0;
    }
    if(a>b)swap(a,b);
    work(a,b);
    if(flag)cout<<cnt+1<<endl;
    else cout<<-1<<endl;
    return 0;
}


