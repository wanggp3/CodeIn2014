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
const int N=755;
using namespace std;
int k;
struct Node{
    int sum,id;
    Node(int sum=0,int id=0):sum(sum),id(id){}
    bool operator<(const Node& rhs)const{
        return sum>rhs.sum;
    }
};
priority_queue<Node>Q;
void Merge(int *A,int * B,int *C,int n){
    while(!Q.empty())Q.pop();
    rep(i,n){
        Q.push(Node(A[i]+B[0],0));
    }
    rep(i,n){
        Node x=Q.top();Q.pop();
        C[i]=x.sum;
        int id=x.id;
        if(id+1<n)Q.push(Node(x.sum-B[id]+B[id+1],id+1));
    }
}
int A[N][N];
int ans[N];
void work(int L,int R,int* out){
    if(L==R){
        rep(i,k)out[i]=A[L][i];
        return;
    }
    if(L+1==R){
        Merge(A[L],A[R],out,k);
        return;
    }
    int mid=(L+R)>>1;
    int out1[N],out2[N];
    work(L,mid,out1);
    work(mid+1,R,out2);
    Merge(out1,out2,out,k);
}
void solve(){
    //rep(i,k)sf("%d",&A[0][i]);
    rep(t,k){
       rep(i,k){
         sf("%d",&A[t][i]);
       }
       sort(A[t],A[t]+k);
      // Merge(A[0],A[1],A[0],k);
    }
    work(0,k-1,ans);
    rep(i,k){
        if(i==k-1)pf("%d\n",ans[i]);
        else pf("%d ",ans[i]);
    }
}
int main(){
    while(~sf("%d",&k)){
        solve();
    }
    return 0;
}

