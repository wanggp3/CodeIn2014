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
const int maxnode = 50000*200+10;
int ch[maxnode][2];
int val[maxnode];
int sz;
void init_trie(){
    sz=1;
    memset(ch[0],0,sizeof ch);
}
int insert(char* s){
    int m=strlen(s);
    int ret=0,u=0;
    rep(i,m){
        int c=s[i]-'0';
        if(!ch[u][c]){
            memset(ch[sz],0,sizeof ch[sz]);
            val[sz]=0;
            ch[u][c]=sz++;
        }
        u=ch[u][c];
        val[u]++;
        ret=max(ret,(i+1)*val[u]);
    }
    return ret;
}
char str[210];
int n;
void input(){
   sf("%d",&n);
   int ans=0;
   rep(i,n){
     sf("%s",str);
     ans=max(ans,insert(str));
   }
   pf("%d\n",ans);
}
int main(){
    int T;sf("%d",&T);
    while(T--){
        init_trie();
        input();
    }
    return 0;
}


