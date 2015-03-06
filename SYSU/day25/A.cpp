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
const int N=25;
using namespace std;
int red;
int n;
map<LL,int>mp;
int x1[N],x2[N],yl[N],y2[N],type[N];
int G[6][6];
queue<LL>Q;
LL S;
void init(){
    mp.clear();
    while(!Q.empty())Q.pop();
    S=0;
    rep(j,n){
        int i;
        sf("%d",&i);
        sf("%d%d%d%d",&yl[i],&x1[i],&y2[i],&x2[i]);
        if(x1[i]==x2[i]){
            type[i]=y2[i]-yl[i]-1;
            S|=((LL)yl[i]<<(3*i));
        }else{
            type[i]=x2[i]-x1[i]+1;
            S|=((LL)x1[i]<<(i*3));
        }
    }
    sf("%d",&red) ;
}
bool ok(){
    LL o;
    rep(i,n){
        if(i==red){
            int d=i*3;
            LL mask=7LL<<d;
            int l=(S&mask)>>d;
            //o=l+type[i]+2;
            o=((S>>(i*3))&7LL)+2+type[i];
            break;
        }
    }
   // pf("ooo %lld\n",o);
    fab(j,o,5)if(G[x1[red]][j]!=-1)return 0;
    return 1;
}
void getgrap(){
    rep(i,n){
        LL o=(S>>(i*3))&7LL;
        if(type[i]<2){
           rep(j,2+type[i])G[x1[i]][o+j]=i;
        }else{
           rep(j,type[i])G[o+j][yl[i]]=i;
        }
    }
}
void print(){
    rep(i,6){
        rep(j,6)pf("%2d ",G[i][j]);puts("");
    }
    puts("");
}
void go(int v){
   fba(dir,1,-1){
       if(dir==0)continue;
       rep(i,n){
          int o=(S>>(i*3))&7LL;
          fab(j,1,6){
              if(type[i]<2){
                 int oo=o+dir*(type[i]+1);
                 oo=oo+dir*j;
                 if(dir==1){
                      if(oo>=6||oo<0||G[x1[i]][oo]!=-1)break;

                 }else {
                      if(o>=6||o<0||G[x1[i]][o]!=-1)break;
                 }
                 LL nxt=(S&~(7LL<<(i*3)))|((LL)(o+j*dir)<<(3*i));
                 if(mp.find(nxt)==mp.end()){
                     mp[nxt]=v;
                     Q.push(nxt);
                 }
              }else{
                 int oo=o+dir*(type[i]-1);
                 oo=oo+dir*j;
                 if(dir==1){
                    if(oo>=6||oo<0||G[yl[i]][oo]!=-1)break;
                 }else{
                    if(o>=6||o<0||G[yl[i]][o]!=-1)break;
                 }
                 LL nxt=(S&~(7LL<<(i*3)))|((LL)(o+j*dir)<<(3*i));
                 if(mp.find(nxt)==mp.end()){
                     mp[nxt]=v;
                     Q.push(nxt);
                 }
              }
          }
       }
   }
}
int solve(){
    Q.push(S);
    mp[S]=0;
    while(!Q.empty()){
        S=Q.front();Q.pop();
        int ret=mp[S]+1;
        memset(G,-1,sizeof G);
        getgrap();
        print();
        //int TT;sf("%d",&TT);
        if(ok())return ret;
        go(ret);
    }
    puts("shb");
    return -1;
}
int main(){
    while(sf("%d",&n)!=EOF){
        init();
        pf("%d\n",solve());
    }
    return 0;
}

