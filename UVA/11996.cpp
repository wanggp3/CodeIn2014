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
const int N=411005;
using namespace std;
typedef pair<int,int>PII;
typedef unsigned long long uLL;
const int X=7;
uLL xp[N];
char str[N];
struct Node{
    Node* ch[2],*pre;
    int val,sz;
    bool rev;
    uLL h1,h2;
    Node(int v=0):val(v){
        sz=0;
        rev=0;
        h1=h2=0;
    }
    void revIt(){
        rev^=1;
        swap(h1,h2);
    }
    void push_up(){
        sz=ch[0]->sz+ch[1]->sz+1;
        h1=ch[0]->h1+val*xp[ch[0]->sz]+ch[1]->h1*xp[ch[0]->sz+1];
        h2=ch[1]->h2+val*xp[ch[1]->sz]+ch[0]->h2*xp[ch[1]->sz+1];
    }
    void push_down(){
        if(rev){
            rev=0;
            if(ch[0]!=null)ch[0]->revIt();
            if(ch[1]!=null)ch[1]->revIt();
        }
    }
}*null;
struct Splay{
   Node pool[N],*cur;
   Node* root;
   Splay(){
       cur=pool;
       root=null;
   }
   void clear(){
       cur=pool;
       root=null;
   }
   void newNode(int v,Node* f){
       cur->ch[0]=cur->ch[1]=null;
       cur->sz=1;
       cur->val=v;
       cur->h1=cur->h2=0;
       cur->rev=0;
       cur->pre=f;
       return cur++;
   }

}splay;
int n,m;
int main(){
    xp[0]=1;
    fab(i,1,N-1)xp[i]=xp[i-1]*X;
    int len=0;
    while(~sf("%d%d",&n,&m)){
        len=n;
        int op,x,y;
        sf("%s",str);
        splay.init(n);
        while(m--){
            sf("%d%d",&op,&x);
            if(op==1){
                sf("%d",&y);
                splay.insert(x,y);
                len++;
            }else if(op==2){
                splay.del(x);
                len--;
            }else if(op==3){
                sf("%d",&y);
                splay.reverse(x,y);
            }else if(op==4){
                sf("%d",&y);
                pf("%d\n",splay.lcp(x,y));
            }
        }
    }
    return 0;
}


