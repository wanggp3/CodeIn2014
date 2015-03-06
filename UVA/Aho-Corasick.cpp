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
const int maxnode=10000;
const int sg=26;
char tmp[N][N];
struct Ac{
   int ch[maxnode][sg];
   int val[maxnode],f[N],last[N];
   int sz;
   Ac(){
       sz=1;
       memset(f,0,sizeof f);
       memset(last,0,sizeof last);
       memset(ch[0],0,sizeof ch[0]);
   }
   void init(){
       sz=1;
       memset(f,0,sizeof f);
       memset(last,0,sizeof last);
       memset(ch[0],0,sizeof ch[0]);
   }
   int idx(char x){
       return x-'a';
   }
   void insert(char* s,int v){
       int u=0,n=strlen(s);
       rep(i,n){
           int c=idx(s[i]);
           if(!ch[u][c]){
               memset(ch[sz],0,sizeof ch[sz]);
               val[sz]=0;
               ch[u][c]=sz++;
           }
           u=ch[u][c];
       }
       val[u]=v;
   }
   void print(int i,int j){
      if(j){
          pf(" %d %d %s %d\n",val[j],int(i-strlen(tmp[val[j]])+1),tmp[val[j]],i);

          print(i,last[j]);
      }
   }
   void getFail(){
      queue<int>Q;
      f[0]=0;
      rep(c,sg){
          int u=ch[0][c];
          if(u){
              f[u]=0;
              Q.push(u);
              last[u]=0;
          }
      }
      while(!Q.empty()){
          int r=Q.front();Q.pop();
          rep(c,sg){
              int u=ch[r][c];
              //if(!u)continue; //verson 1
              if(!u){ch[r][c]=ch[f[r]][c];continue;}//version 2
              Q.push(u);
              int v=f[r];
              while(v&&!ch[v][c])v=f[v];
              f[u]=ch[v][c];
              last[u]=val[f[u]]?f[u]:last[f[u]];
          }
      }
   }
   void find(char* T){
       getFail();
       int n=strlen(T);
       int j=0;
       rep(i,n){
           int c=idx(T[i]);
           //while(j&&!ch[j][c])j=f[j]; verson 1
           j=ch[j][c];
           if(val[j])print(i,j);
           else if(last[j])print(i,last[j]);
       }
   }
}ac;
int main(){
    ac.init() ;
    int n;
    sf("%d",&n);
    rep(i,n){
        sf("%s",tmp[i+1]);
        ac.insert(tmp[i+1],i+1);
    }
    sf("%s",tmp[n+1]);
    ac.find(tmp[n+1]);
    return 0;
}


