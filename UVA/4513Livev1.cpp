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
typedef unsigned long long LL;
const int N=41005;
using namespace std;
int rank[N],n,m,pos;
unsigned long long hash[N],xp[N],H[N];
const int x=113;
bool cmp(const int & i,const int &j){
    return hash[i]<hash[j]||(hash[i]==hash[j]&&i<j);
}
int ok(int L){
    int c=0;
    pos=-1;
    rep(i,n-L+1){
        rank[i]=i;
        hash[i]=H[i]-H[i+L]*xp[L];
    }
    sort(rank,rank+n-L+1,cmp);
    rep(i,n-L+1){
        if(i==0||hash[rank[i]]!=hash[rank[i-1]])c=0;
        if(++c>=m)pos=max(pos,rank[i]);
    }
    return pos>=0;
}

int main(){
    char s[N];
    while(~sf("%d",&m)&&m){
        sf("%s",s);
        n=strlen(s);
        H[n]=0;
        fba(i,n-1,0)H[i]=H[i+1]*x+(s[i]-'a');
        xp[0]=1;
        fab(i,1,n)xp[i]=xp[i-1]*x;
        if(!ok(1))puts("none");
        else{
            int L=1,R=n+1;
            while(R-L>1){
                int M=L+(R-L)/2;
                if(ok(M))L=M;
                else R=M;
            }
            ok(L);
            pf("%d %d\n",L,pos);
        }
    }
    return 0;
}


