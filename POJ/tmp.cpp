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
void Failkmp(char * T,char* P){
    int n=strlen(T);
    int m=strlen(P);
    getFail(P);
    int j=0;
    rep(i,n){
       while(j&&P[j]!=T[i])j=f[j];
       if(P[j]==T[i])j++;
       if(j==m)printf("%d\n",i-m+1);
    }
}
void Nextkmp(char* T,char* P){
    int n=strlen(T);
    int m=strlen(P);
    getNext(P);
    int j=0;
    rep(i,n){
        while(j&&P[j]!=T[i])j=next[j];
        if(P[j]==T[i])j++;
        if(j==m)pf("%d\n",i-m+1);
    }
}
int main(){
    char T[N],P[N];
    sf("%s %s",T,P);
    Failkmp(T,P);
    cout<<"--"<<endl;
    Nextkmp(T,P);
    return 0;
}


