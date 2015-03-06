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
const int N=1005;
using namespace std;
priority_queue<int>Q;
set<int>S;
int main(){
    rep(i,10){
        Q.push(i+1);
        S.insert(i+1);
    }
    while(!Q.empty()){
        int u=Q.top();Q.pop();
        pf("%d :",u);
        S.erase(S.find(u));
        set<int>::iterator it=S.begin();
        while(it!=S.end()){
            pf(" %d",*it);
            it++;
        }
        pf("\n");
    }
    return 0;
}

