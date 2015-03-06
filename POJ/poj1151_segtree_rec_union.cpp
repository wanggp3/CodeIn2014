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
#define rson m+1,r,rt<<1|1
#define LL long long 
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define sf scanf
#define pf printf 
#define bug puts("bug")
const int N=1005;
using namespace std;
int n;
double x1,x2,yy1,y2;
int cover[N<<2];
double len[N<<2];
int cnt;
vector<double>Y;
double ans=0;
const double eps =1e-9;
struct Line{
    double x,y_down,y_up;
    int flag;
    Line(double x=0,double y_down=0,double y_up=0,int flag=0)
    :x(x),y_down(y_down),y_up(y_up),flag(flag)
    {      
    }
    bool operator<(const Line &rhs)const{
        if(fabs(x-rhs.x)>eps)return x<rhs.x;
        else if(fabs(y_down-rhs.y_down)>eps)return y_down<rhs.y_down;
        else if(fabs(y_up-rhs.y_up)>eps)return y_up<rhs.y_up;
        else return flag<rhs.flag;
    }
}line[N<<2];
void init(){
    memset(cover,0,sizeof cover);
    memset(len,0,sizeof len);
    ans=0;
    Y.clear();
    cnt=0;
}
void input(){
    rep(i,n){
        sf("%lf%lf%lf%lf",&x1,&yy1,&x2,&y2);
        line[cnt].x=x1;
        line[cnt].y_down=yy1;
        line[cnt].y_up=y2;
        line[cnt].flag=1;
        cnt++;
        Y.PB(yy1);

        line[cnt].x=x2;
        line[cnt].y_down=yy1;
        line[cnt].y_up=y2;
        line[cnt].flag=-1;
        cnt++;
        Y.PB(y2);
    }
}
void build(int l,int r,int rt){
    cover[rt]=len[rt]=0;
    if(l+1==r)return ;
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid,r,rt<<1|1);
}
void push_up(int rt,int l,int r){
    if(cover[rt]){
        len[rt]=Y[r-1]-Y[l-1];
    }else if(l+1==r)len[rt]=0;
    else len[rt]=len[rt<<1]+len[rt<<1|1];
}
void update(int L,int R,int flag,int l,int r,int rt){
  // pf("%d %d %d %d\n",L,R,l,r);
   if(L<=l&&r<=R){
       cover[rt]+=flag;
       push_up(rt,l,r);
       return;
   }
   int mid=(l+r)>>1;
   if(L<mid)update(L,R,flag,l,mid,rt<<1);
   if(R>mid)update(L,R,flag,mid,r,rt<<1|1);
   push_up(rt,l,r);
}
void solve(){
    sort(Y.begin(),Y.end());
    Y.erase(unique(Y.begin(),Y.end()),Y.end());
    
    sort(line,line+cnt);
    ans=0;
    int m=Y.size();
    build(1,m,1);
    rep(i,cnt-1){
        int L=lower_bound(Y.begin(),Y.end(),line[i].y_down)-Y.begin()+1;
        int R=lower_bound(Y.begin(),Y.end(),line[i].y_up)-Y.begin()+1;
       // pf("update %d %d\n",L,R);
        update(L,R,line[i].flag,1,m,1);
        ans+=len[1]*(line[i+1].x-line[i].x);
    }
    pf("Total explored area: %.2lf\n",ans);
}
int main(){    
    int cas=0;
    while(sf("%d",&n)&&n){
        init();
        input();
        pf("Test case #%d\n",++cas);
        solve();
    }
    return 0;
}

