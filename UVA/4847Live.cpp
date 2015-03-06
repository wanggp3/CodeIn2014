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
int n;
LL C[22][22];
LL mod=9999991;
void init(){
    for(int i=0;i<=20;i++){
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++){
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
        }
    }
}
struct Node{
    int v,size;
    Node *left,*right;
    Node(int v=0){
        this->v=v;
        left=right=NULL;
        size=1;
    }
    void maintain(){
        size=1;
        if(left!=NULL)size+=left->size;
        if(right!=NULL)size+=right->size;
    }
}*root;
void insert(Node* &o,int v){
    if(o==NULL){
        o=new Node(v);
        return;
    }
    if(v<o->v)insert(o->left,v);
    else insert(o->right,v);
    o->maintain();
}
void input(){
    root=NULL;
    sf("%d",&n);
    rep(i,n){
        int x;sf("%d",&x);
        insert(root,x);
    }
}
void print(Node *o){
    if(o==NULL)return;
    print(o->left);
    pf("%d size =%d\n",o->v,o->size);
    print(o->right);
}
LL dfs(Node* o){
    if(o==NULL)return 1;
    if(o->size==1)return 1;
    LL ret=1;
    int size=o->size;
    if(o->left!=NULL){
        int lsize=o->left->size;
        ret=ret*C[size-1][lsize]%mod*dfs(o->left)%mod;
    }
    if(o->right!=NULL){
        ret=ret*dfs(o->right)%mod;
    }
    return ret%mod;
}
void solve(){
    LL ans=dfs(root);
    pf("%lld\n",ans);
}
int main(){
    init();
    int T;sf("%d",&T);
    while(T--){
        input();
        solve();
    }
    return 0;
}


