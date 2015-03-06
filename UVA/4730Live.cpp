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
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define sf scanf
#define pf printf
#define LL long long
const int N=100015;
using namespace std;
typedef pair<int,int>PII;
int n,m;
int fa[N],num[N],miny[N],maxy[N],tag1[N<<2],tag2[N<<2];
vector<int>mp;
int ans1,ans2;
struct Point{
    int x,y;
    Point(int x=0,int y=0):x(x),y(y){}
}P[N];
void init(){
    rep(i,N)fa[i]=i,num[i]=1;
    rep(i,N<<2)tag1[i]=tag2[i]=0;
    mp.clear();
}
struct Cmd{
    int op,a,b;
    Cmd(int op=0,int a=0,int b=0):op(op),a(a),b(b){}
}cmd[N*2];
void input(){
    sf("%d",&n);
    rep(i,n){
        sf("%d%d",&P[i].x,&P[i].y);
        P[i].x*=2;
        P[i].y*=2;
        mp.PB(P[i].y);
    }
    sf("%d",&m);
    char op[10];
    int a,b;
    rep(i,m){
        sf("%s",op);
        if(op[0]=='r'){
            sf("%d%d",&a,&b);
            cmd[i]=Cmd(0,a,b);
        }else{
            double x;
            sf("%lf",&x);
            cmd[i]=Cmd(1,int(2*x+0.01),0);
            mp.PB(int(2*x+0.01));
        }
    }
}
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void push_down(int rt){
    if(tag1[rt]){
        tag1[rt<<1]+=tag1[rt];
        tag1[rt<<1|1]+=tag1[rt];
        tag1[rt]=0;
    }
    if(tag2[rt]){
        tag2[rt<<1]+=tag2[rt];
        tag2[rt<<1|1]+=tag2[rt];
        tag2[rt]=0;
    }
}
void update(int L,int R,int v,int l,int r,int rt){
    if(L<=l&&r<=R){
        tag1[rt]+=v;
        if(v>=0)tag2[rt]++;
        else tag2[rt]--;
        return;
    }
    int mid=(l+r)>>1;
    push_down(rt);
    if(L<=mid)update(L,R,v,lson);
    if(R>mid)update(L,R,v,rson);
}
void qurry(int p,int l,int r,int rt){
    if(l==r){
        ans1=tag1[rt];
        ans2=tag2[rt];
        return;
    }
    push_down(rt);
    int mid=(l+r)>>1;
    if(p<=mid)qurry(p,lson);
    else if(p>mid)qurry(p,rson);
}
void links(int a,int b){
   int Fa=find(a),Fb=find(b);
   if(Fa!=Fb){
      fa[Fa]=Fb;
      update(miny[Fb],maxy[Fb],-num[Fb],1,n,1);
      update(miny[Fa],maxy[Fa],-num[Fa],1,n,1);
      num[Fb]+=num[Fa];
      num[Fa]=0;
      miny[Fb]=min(miny[Fa],miny[Fb]);
      maxy[Fb]=max(maxy[Fa],maxy[Fb]);
      update(miny[Fb],maxy[Fb],num[Fb],1,n,1);
   }
   //pf("links %d %d\n",Fa,Fb);
}
void Qurry(int p){
    p=lower_bound(mp.begin(),mp.end(),p)-mp.begin()+1;
    ans1=ans2=0;
    qurry(p,1,n,1);
    //pf("qurry %d \n",p);
}
void bug(){
    pf(" mp : ");
    rep(i,mp.size())pf("%d ",mp[i]);
    pf("mp end\n");
}
void print(int l,int r,int rt){
    if(l==r)pf("%d : tag1 %d tag2 %d\n",l,tag1[rt],tag2[rt]);
    else{
        int mid=(l+r)>>1;
        print(lson);
        print(rson);
    }
}
void bugtree(){
    pf(" tree\n");
    print(1,n,1);
    pf(" end tree\n");
}
void solve(){
    sort(mp.begin(),mp.end());
    mp.erase(unique(mp.begin(),mp.end()),mp.end());
    //bug();
    rep(i,n){
        miny[i]=maxy[i]=lower_bound(mp.begin(),mp.end(),P[i].y)-mp.begin()+1;
        update(miny[i],maxy[i],1,1,mp.size(),1);
    }
    n=mp.size();
    rep(i,m){
        //bugtree();
        int op,a,b;
        op=cmd[i].op;
        a=cmd[i].a;
        b=cmd[i].b;
        if(op==0){
            links(a,b);
        }else if(op==1){
            Qurry(a);
            pf("%d %d\n",ans2,ans1);
        }
        //pf("ok ---\n");
        //bugtree();
    }
}
int main(){
    int T;sf("%d",&T);
    while(T--){
        init();
        input();
        solve();
    }
    return 0;
}


