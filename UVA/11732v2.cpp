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
using namespace std;
typedef pair<int,int>PII;
const int maxnode=4000*1006;
const int N=1005;
char str[N];
int n;
struct Trie{
    int head[maxnode],next[maxnode],val[maxnode],ch[maxnode];
    int sz;
    int ed[maxnode];
    LL ans;
    void init(){
        ans=0;
        sz=1;
        head[0]=next[0]=val[0]=ch[0]=ed[0]=0;
    }
    void insert(char* s){
        int n=strlen(s),u=0,p;
        rep(i,n){
             for(p=head[u];p;p=next[p]){
                 if(ch[p]==s[i]){
                     break;
                 }
             }
             if(!p){
                 p=sz++;
                 val[p]=ed[p]=0;
                 ch[p]=s[i];
                 next[p]=head[u];
                 head[u]=p;
                 head[p]=0;
             }
             u=p;
             ans+= 1LL*val[p]*2;
             val[p]++;
        }
        ans+=1LL*ed[u];
        ed[u]++;
    }
}trie;
int main(){
    int cas=1;
    while(~sf("%d",&n)&&n){
        trie.init();
        rep(i,n){
            sf("%s",str);
            trie.insert(str);
        }
        pf("Case %d: %lld\n",cas++,trie.ans+n*(n-1)*1LL/2);
    }
    return 0;
}


