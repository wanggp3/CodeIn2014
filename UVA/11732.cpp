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
const int maxnode=4100005;
struct Trie{
    int sz;
    int ch[maxnode][70];
    int cnt[maxnode];
    LL ans;
    Trie(){
        sz=1;
        memset(ch[0],0,sizeof ch[0]);
        memset(cnt,0,sizeof cnt);
        ans=0;
    }
    void init(){
        sz=1;
        memset(ch[0],0,sizeof ch[0]);
        memset(cnt,0,sizeof cnt);
        ans=0;
    }
    void insert(char* s){
       int n=strlen(s),u=0;
       rep(i,n){
           //int v=s[i]-'a';
           int v;
           if(s[i]>='a'&&s[i]<='z')v=s[i]-'a';
           else if(s[i]>='A'&&s[i]<='Z')v=s[i]-'A'+26;
           else v=s[i]-'0'+52;
           if(!ch[u][v]){
               memset(ch[sz],0,sizeof ch[sz]);
               cnt[sz]=0;
               ch[u][v]=sz++;
           }
           u=ch[u][v];
           ans+=cnt[u];
           cnt[u]++;
       }
    }
}trie;
int cas=1;
char in[N];
int n;
void init(){
    trie.init();
    rep(i,n){
        sf("%s",in);
        trie.insert(in);
    }
    pf("Case %d: %lld\n",cas++,trie.ans+n*(n-1)/2);
}
int main(){
    while(~sf("%d",&n)&&n){
        init();
        //solve();
    }
    return 0;
}


