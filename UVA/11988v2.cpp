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
const int N=100005;
using namespace std;
typedef pair<int,int>PII;
char str[N];
void solve(){
    int n=strlen(str);
    list<char>List;
    list<char>::iterator it=List.begin();
    rep(i,n){
       char c=str[i];
       if(c=='[')it=List.begin();
       else if(c==']')it=List.end();
       else {
           List.insert(it,c);
       }
    }
    for(it=List.begin();it!=List.end();it++)putchar(*it);puts("");
}
int main(){
    while(~sf("%s",str)){
        solve();
    }
    return 0;
}


