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
const int maxnode=10010;
const int sg=26;
int num[N][N];
void match(int i,int j);
struct Ac{
   int ch[maxnode][sg];
   int val[maxnode],f[maxnode],last[maxnode];
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
          //pf(" %d %d %s %d\n",val[j],int(i-strlen(tmp[val[j]])+1),tmp[val[j]],i);
          //pf("find %d\n",val[j]);
          match(i,val[j]);
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
           if(val[j])print(i,j);
           else if(last[j])print(i,last[j]);
       }
   }
}ac;
char text[N][N],p[N][N];
map<string,int>Map;
int len[N];
int n,m,x,y,tr;
vector<int>V[N];
bool same(char * a,char * b){
    int n=strlen(a);
    rep(i,n)if(a[i]!=b[i])return 0;
    return 1;
}
void match(int i,int j){
    int r=Map[p[j-1]];
    int c=i-len[r]+1;
    rep(i,V[r].size()){
        /*if(strcmp(p[i],p[r])==0){
           if(tr>=i) num[tr-i][c]++;
        }*/
        /*if(p[i]==p[r]){
            if(tr>=i)num[tr-i][c]++;
        }*/
        /*if(Map[p[i]]==r){
            if(tr>=i)num[tr-i][c]++;
        }*/
        int id=V[r][i];
        if(tr>=id)num[tr-id][c]++;
    }
}
int main(){
    int T;sf("%d",&T);
    while(T--){
        Map.clear();
        rep(i,N)V[i].clear();
        sf("%d%d",&n,&m);
        rep(i,n)sf("%s",text[i]);
        ac.init();
        sf("%d%d",&x,&y);
        rep(i,x){
            sf("%s",p[i]);
            len[i]=strlen(p[i]);
            if(!Map.count(p[i])){
                Map[p[i]]=i;
                V[i].PB(i);
                ac.insert(p[i],i+1);
            }else {
                V[Map[p[i]]].PB(i);
            }
        }
        ac.getFail();
        memset(num,0,sizeof num);
        for(tr=0;tr<n;tr++){
            ac.find(text[tr]);
        }
        int ans=0;
        rep(i,n-x+1)
            rep(j,m-y+1)
              if(num[i][j]==x)ans++;
        pf("%d\n",ans);
    }
    return 0;
}


