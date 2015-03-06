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
const int N=100015;
using namespace std;
int n,q;
int d[N][42],num[N],Left[N],Right[N];
int Count[N];
int arr[N];
void init(){
    int cnt=0;
   rep(i,n){
       sf("%d",&arr[i]);
       if(i==0){
           num[i]=Left[i]=0;
           //val[0]=arr[i];
           Count[0]=1;
       }else{
           if(arr[i]==arr[i-1]){
               Left[i]=Left[i-1];
               Count[cnt]++;
               num[i]=cnt;
           }else{
               num[i]=++cnt;
             //  val[cnt]=arr[i];
               Count[cnt]=1;
               Left[i]=i;
           }
       }
   }
   fba(i,n-1,0){
       if(i==n-1)Right[i]=n-1;
       else{
           if(arr[i]==arr[i+1])Right[i]=Right[i+1];
           else Right[i]=i;
       }
   }
   cnt++;
   for(int i=0;i<cnt;i++){
       d[i][0]=Count[i];
   }
   for(int j=1;(1<<j)<=cnt;j++){
       for(int i=0;i+(1<<j)-1<cnt;i++)
           d[i][j]=max(d[i][j-1],d[i+(1<<(j-1))][j-1]);
   }
}
int work(int L,int R){
    if(L>R)return 0;
    if(L==R)return Count[L];
    int k=0;
    while((1<<(1+k))<=R-L+1)k++;
    return max(d[L][k],d[R-(1<<k)+1][k]);
}
void solve(){
    int L,R;
   while(q--){
       sf("%d%d",&L,&R);
       L--,R--;
       if(num[L]==num[R]){
           pf("%d\n",R-L+1);
       }else{
           int ret=work(num[L]+1,num[R]-1);
           ret=max(ret,Right[L]-L+1);
           ret=max(ret,R-Left[R]+1);
           pf("%d\n",ret);
       }
   }
}
int main(){
    while(~sf("%d%d",&n,&q)&&n){
        init();
        solve();
    }
    return 0;
}

