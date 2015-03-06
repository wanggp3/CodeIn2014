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
const int N=1000005;
using namespace std;
typedef pair<int,int>PII;
const int maxnode=15000;
const int sg=26;
int n;
map<string,int>Map;

struct Ac{
   int ch[maxnode][sg];
   int val[maxnode],f[maxnode],last[maxnode],cnt[maxnode];
   int sz;

   Ac(){
       sz=1;
       memset(cnt,0,sizeof cnt);
       memset(f,0,sizeof f);
       memset(last,0,sizeof last);
       memset(ch[0],0,sizeof ch[0]);
   }
   void init(){
       sz=1;
       memset(cnt,0,sizeof cnt);
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
   void print(int j){
      if(j){
          //pf("%d: %d\n",j,val[j]);
          cnt[val[j]]++;
          print(last[j]);
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
              if(!u)continue; //verson 1
              //if(!u){ch[r][c]=ch[f[r]][c];continue;}//version 2
              Q.push(u);
              int v=f[r];
              while(v&&!ch[v][c])v=f[v];
              f[u]=ch[v][c];
              last[u]=val[f[u]]?f[u]:last[f[u]];
          }
      }
   }
   void find(char* T){
       int n=strlen(T);
       int j=0;
       rep(i,n){
           int c=idx(T[i]);
           while(j&&!ch[j][c])j=f[j];// verson 1
           j=ch[j][c];
           if(val[j])print(j);
           else if(last[j])print(last[j]);
       }
   }
}ac;
char str[155][75];
char T[N];
int main(){
    while(~sf("%d",&n)&&n){
        Map.clear();
        ac.init();
        fab(i,1,n){
            sf("%s",str[i]);
            //if(!Map.count(str[i]))ac.insert(str[i],i),Map[str[i]]=i;
            ac.insert(str[i],i);
            Map[str[i]]=i;
        }
        sf("%s",T);
        ac.getFail();
        ac.find(T);
        int maxv=-1;
        fab(i,1,n)maxv=max(maxv,ac.cnt[i]);
        pf("%d\n",maxv);
        fab(i,1,n){
            if(ac.cnt[Map[str[i]]]==maxv)pf("%s\n",str[i]);
        }
    }
    return 0;
}


