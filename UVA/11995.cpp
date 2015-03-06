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
const int N=1005;
using namespace std;
stack<int>S;
queue<int>Q;
priority_queue<int>PQ;
int n;
void init(){
    while(!S.empty())S.pop();
    while(!Q.empty())Q.pop();
    while(!PQ.empty())PQ.pop();
}
void solve(){
    int op,x;
    int okS=1,okQ=1,okPQ=1;
    rep(i,n){
      sf("%d%d",&op,&x);
      if(op==1){
         S.push(x);
         Q.push(x);
         PQ.push(x);
      }else{
         if(!S.empty()){
            int y=S.top();
            S.pop();
            if(y!=x)okS=0;
         }else okS=0;
         if(!Q.empty()){
             int y=Q.front();Q.pop();
             if(y!=x)okQ=0;
         }else okQ=0;
         if(!PQ.empty()){
             int y=PQ.top();PQ.pop();
             if(y!=x)okPQ=0;
         }else okPQ=0;
      }
    }
    if(okS+okQ+okPQ>=2)puts("not sure");
    else if(okS+okQ+okPQ==0)puts("impossible");
    else if(okS)puts("stack");
    else if(okQ)puts("queue");
    else if(okPQ)puts("priority queue");
}
int main(){
    while(~sf("%d",&n)){
        init();
        solve();
    }
    return 0;
}
