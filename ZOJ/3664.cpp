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
#define sf scanf
#define pf printf
#define LL long long
const int N=2005;
using namespace std;
typedef pair<int,int>PII;
struct Node{
    int lson,rson,fa,dep;
    int xl,yl,xr,yr;
    void init(int dep,int fa){
        this->dep=dep;this->fa=fa;
        lson=rson=0;
    }
    void setv(int xl,int yl,int xr,int yr){
        this->xl=xl; this->xr=xr;
        this->yl=yl; this->yr=yr;
    }
}a[N];
int sz[N];
int root,tot;
int find(int root,int x,int y){
    int u=root,v;
    while(true){
        v=a[u].lson;
        if(v==0)return u;
        if(a[v].xl<=x&&x<=a[v].xr&&a[v].yl<=y<=a[v].yr)u=v;
        else u=a[u].rson;
    }
}
int getsize(int o){
    sz[o]=0;
    if(a[o].lson==0){
        return sz[o]=1;
    }else{
        sz[o]+=getsize(a[o].lson);
        sz[o]+=getsize(a[o].rson);
        return sz[o];
    }
}
int main(){
    int xl,xr,yl,yr;
    int n,q;
    while(~sf("%d%d%d%d",&xl,&yl,&xr,&yr)){
       root=0;
       tot=1;
       a[root].init(root,-1);
       a[root].setv(xl,yl,xr,yr);
       sf("%d%d",&n,&q);
       fab(i,1,n){
           sf("%d%d%d%d",&xl,&yl,&xr,&yr);
           if(xl>xr)swap(xl,xr);
           if(yl>yr)swap(yl,yr);
           int id=find(root,(xl+xr)/2,(yl+yr)/2);
           int dep=a[id].dep;
           
           a[id].lson=tot;
           a[tot].init(dep+1,id);
           a[tot].setv(a[id].xl,a[id].yl,xr,yr);
           tot++;
           a[id].rson=tot;
           a[tot].init(dep+1,id);
           a[tot].setv(xl,yl,a[id].xr,a[id].yr);
           tot++;
       }
       getsize(root);
       while(q--){
            sf("%d%d%d%d",&xl,&yl,&xr,&yr);
            int u=find(root,xl,yl);
            int v=find(root,xr,yr);
                while(u!=v){
                    if(a[u].dep<a[v].dep)v=a[v].fa;
                    else if(a[u].dep>a[v].dep)u=a[u].fa;
                    else{
                        u=a[u].fa;
                        v=a[v].fa;
                    }
                }
            pf("%d\n",n+2-sz[u]);
       }
    }
    return 0;
}


