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
struct Node{
    int id,P,T;
    Node(int id=0,int P=0,int T=0):id(id),P(P),T(T){}
    bool operator<(const Node& rhs)const{
        if(T!=rhs.T)return T>rhs.T;
        else return id>rhs.id;
    }
};
priority_queue<Node>Q;
int k;
void solve(){
    char op[20];
    int a,b;
    while(~sf("%s",op)&&op[0]!='#'){
        sf("%d%d",&a,&b);
        Q.push(Node(a,b,b));
    }
    sf("%d",&k);
    rep(i,k){
        Node x=Q.top();Q.pop();
        pf("%d\n",x.id);
        Q.push(Node(x.id,x.P,x.P+x.T));
    }
}
int main(){
    solve() ;
    return 0;
}

