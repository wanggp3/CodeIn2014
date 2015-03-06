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
const int N=1005010;
using namespace std;
typedef pair<int,int>PII;
int f[N];
int next[N];
char s[N];
void getFail(char* P){
    int m=strlen(P);
    f[0]=f[1]=0;
    fab(i,1,m-1){
        int j=f[i];
        while(j&&P[i]!=P[j])j=f[j];
        f[i+1]= P[i]==P[j]?j+1:0;
    }
}
void getNext(char* P){
    int m=strlen(P);
    next[0]=-1;
    int k=-1,j=0;
    while(j<m){
        if(k==-1||P[j]==P[k])next[++j]=++k;
        else k=next[k];
    }
}
int main(){
    while(~sf("%s",s)&&s[0]!='.'){
        getFail(s);
        int n=strlen(s);
        if(n%(n-next[n])==0)pf("%d\n",n/(n-next[n]));
        else pf("1\n");
    }
    return 0;
}


