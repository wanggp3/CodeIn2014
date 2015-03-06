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
const int N=300005;
using namespace std;
typedef pair<int,int>PII;
const int maxnode=400005;
const int sgsz=26;
const int MOD=20071027;
struct Trie{
   int ch[maxnode][sgsz];
   int val[maxnode];
   int sz;
   Trie(){
     sz=1;
     memset(ch[0],0,sizeof ch[0]);
   }
   void init(){
       sz=1;
       memset(ch[0],0,sizeof ch[0]);
   }
   void insert(char* s,int va){
       int u=0,n=strlen(s);
       rep(i,n){
           int v=s[i]-'a';
           if(!ch[u][v]){
               memset(ch[sz],0,sizeof ch[sz]);
               val[sz]=0;
               ch[u][v]=sz++;
           }
           u=ch[u][v];
       }
       val[u]=va;
   }
   void print(){
       rep(i,sz+1)pf("%d ",val[i]);pf("\n");
   }
}tree;
char str[N],word[105];
int d[N];
int n,S;
int cas=1;
void init(){
    tree.init();
    sf("%d",&S);
    rep(i,S){
        sf("%s",word);
        tree.insert(word,i+1);
    }
    //tree.print();
}
void solve(){
    int n=strlen(str);
    d[n]=1;
    for(int i=n-1;i>=0;i--){
        d[i]=0;
        int u=0,v=str[i]-'a',k=i;
        while(k<n&&tree.ch[u][v]){
            u=tree.ch[u][v];
            k++;
            v=str[k]-'a';
            if(tree.val[u])d[i]=(d[i]+d[k])%MOD;
        }
    }
    pf("Case %d: %d\n",cas++,d[0]);
}
int main(){
    while(~sf("%s",str)){
        init();
        solve();
    }
    return 0;
}


