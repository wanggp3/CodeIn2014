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
#define cls0(x) memset(x,0,sizeof(x))
#define cls1(x) memset(x,-1,sizeof(x))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1
#define LL long long 
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define sf scanf
#define pf printf 
const int N=2005;
using namespace std;
int n,m,k;
map<string,int>mp;
int team[N],hp[N];
int last,now,cnt;
void init(){
    mp.clear();
    cls0(team);
    cls0(hp);
    now=cnt=0;
    last=-1;
}
void input(){
    init();
    char tmp[N];
    string tmp1;
    rep(i,n){
        sf("%s",tmp);
        tmp1=string(tmp);
        mp[tmp1]=i;
        team[i]=1;
        hp[i]=603;
    }
    rep(i,m){
        sf("%s",tmp);
        tmp1=string(tmp);
        mp[tmp1]=i+n;
        team[i+n]=2;
        hp[i+n]=603;
    }
}
void solve(){
   while(k--){
       char op[N],a[N],b[N];
       string tmp1,tmp2;
       int cur;
       sf("%s",op);
       if(op[0]=='K'){
           sf("%s",a);
           sf("%s",b);
           sf("%d",&cur);
           int x=mp[string(a)],y=mp[string(b)];
           rep(i,n+m)hp[i]+=(cur-now);
           now=cur;
           hp[y]=max(hp[y]-300,0);
           if(team[x]==team[y]){
               cnt=0;
               continue;
           }
           hp[x]+=200;
           if(last==-1)hp[x]+=200;
           if(x==last){
               hp[x]+=min(50*max(++cnt-2,0),400);
           }else last=x,cnt=1;
       }else{
           sf("%s",a);
           sf("%d",&cur);
           rep(i,n+m)hp[i]+=(cur-now);
           now=cur;
           pf("%d\n",hp[mp[string(a)]]);
       }
   }
}
int main(){
    while(~sf("%d %d %d",&n,&m,&k)){
        input();
        solve();
    }
    return 0;
}

