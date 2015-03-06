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
char D[2];
char s[N];
map<char,char>mpL,mpR;
void init(){
   string s1="qwertyuiop";
   string s2="asdfghjkl;";
   string s3="zxcvbnm,./";
   rep(i,s1.size()){
       if(i+1<s1.size())mpL[s1[i]]=s1[i+1];
       if(i-1>=0)mpR[s1[i]]=s1[i-1];
   }
   rep(i,s2.size()){
       if(i+1<s2.size())mpL[s2[i]]=s2[i+1];
       if(i-1>=0)mpR[s2[i]]=s2[i-1];
   }
   rep(i,s3.size()){
       if(i+1<s3.size())mpL[s3[i]]=s3[i+1];
       if(i-1>=0)mpR[s3[i]]=s3[i-1];
   }
}
void solve1(){
    rep(i,strlen(s))pf("%c",mpL[s[i]]);
    puts("");
}
void solve2(){
    rep(i,strlen(s))pf("%c",mpR[s[i]]);
    puts("");
}
int main(){
    init();
    sf("%s",D);
    sf("%s",s);
    if(D[0]=='L')solve1();
    else solve2();
    return 0;
}

