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
const int N=100005;
using namespace std;
/*
struct Node{
    int v,id;
    Node(int v=0,int id=0):v(v),id(id){}
    bool operator<(const Node& rhs)const{
        if(v!=rhs.v)return v<rhs.v;
        else return id<rhs.id;
    }
}a[N];
int n,m;
void solve(){
    rep(i,n){
        sf("%d",&a[i].v);
        a[i].id=i;
    }
    sort(a,a+n);
    int k,v;
    rep(i,m){
      sf("%d%d",&k,&v);
      int L=lower_bound(a,a+n,Node(v,-1))-a;
      if(L+k-1>=n||a[L+k-1].v!=v)pf("0\n");
      else pf("%d\n",a[L+k-1].id+1);
    }
}*/
int n,m;
map< int ,vector<int> >Map;
void solve(){
    Map.clear();
    int k,v;
    rep(i,n){
        sf("%d",&v);
        if(!Map.count(v))Map[v]=vector<int>();
        Map[v].PB(i+1);
    }
    rep(i,m){
        sf("%d%d",&k,&v);
        if(Map.count(v)&&Map[v].size()>=k)pf("%d\n",Map[v][k-1]);
        else puts("0");
    }
}
int main(){
    while(~sf("%d%d",&n,&m)){
        solve();
    }
    return 0;
}

