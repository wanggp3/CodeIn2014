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
#define lowbit(x) x&-x
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define sf scanf
#define pf printf
#define LL long long
const int N=100005;
const int UP=2000005;
const int ADD = 1000002;
using namespace std;
typedef pair<int,int>PII;
int n;
struct Node{
    int x,y,z;
    Node(int x=0,int y=0,int z=0):x(x),y(y),z(z){}
    bool operator<(const Node& rhs)const{
        if(x!=rhs.x)return x<rhs.x;
        else if(y!=rhs.y)return y>rhs.y;
        else return z<rhs.z;
    }
}P[N];
struct Node1{
    int id,flag;
    Node1(int id=0,int flag=0):id(id),flag(flag){}
    bool operator<(const Node1 &rhs)const{
        if(P[id].x!=P[rhs.id].x)return P[id].x>P[rhs.id].x;
        else if(P[id].y!=P[rhs.id].y)return P[id].y<P[rhs.id].y;
        else return flag>rhs.flag;
    }
};
vector<int>G[N],ans1,ans2;
vector<Node1>tmp;
int d[N],C[UP],maxv[UP<<2];
void init(){
    memset(maxv,0,sizeof maxv);
    tmp.clear();
    memset(C,0,sizeof C);
    ans1.clear();
    ans2.clear();
    rep(i,N)G[i].clear();
}
void input(){
    rep(i,n){
       sf("%d%d",&P[i].x,&P[i].y);
       P[i].x+=ADD;
       P[i].y+=ADD;
       P[i].z=i;
    }
}
void insert(int x,int v){
    while(x<UP){
        C[x]=max(C[x],v);
        x+=lowbit(x);
    }
}
int find(int x){
    int ret=0;
    while(x){
        ret=max(ret,C[x]);
        x-=lowbit(x);
    }
    return ret;
}
void push_up(int rt){
    maxv[rt]=max(maxv[rt<<1],maxv[rt<<1|1]);
}
void update(int p,int v,int l,int r,int rt){
    if(l==r){
        maxv[rt]=max(maxv[rt],v);
        return;
    }
    int mid=(l+r)>>1;
    if(p<=mid)update(p,v,lson);
    else if(p>mid)update(p,v,rson);
    push_up(rt);
}
int query(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R){
        return maxv[rt];
    }
    int mid=(l+r)>>1;
    int ret=0;
    if(L<=mid)ret=max(ret,query(L,R,lson));
    if(R>mid)ret=max(ret,query(L,R,rson));
    return ret;
}
void bug(int mm){
    fab(i,1,mm){
        pf("i = %d: ",i);
        rep(j,G[i].size())pf("%d ",P[G[i][j]].z);pf("\n");
    }
}
void bug1(int id){
    puts("bug1");
    pf("id = %d\n",id);
    rep(i,tmp.size()){
        pf("%d  %d \n",P[tmp[i].id].z,tmp[i].flag);
    }
}
void solve(){
    sort(P,P+n);
    int mm=0;
    rep(i,n){
        d[i]=find(P[i].y-1)+1;
        G[d[i]].PB(i);
        mm=max(mm,d[i]);
        insert(P[i].y,d[i]);
    }
    //rep(i,n)pf(" di = %d\n",d[i]);
    //bug(mm);
    if(G[mm].size()==1)ans1.PB(P[G[mm][0]].z);
    else rep(i,G[mm].size())ans2.PB(P[G[mm][i]].z);
    for(int i=mm-1;i;i--){
        tmp.clear();
        rep(j,G[i].size()){
            tmp.PB(Node1(G[i][j],0));
        }
        rep(j,G[i+1].size()){
            tmp.PB(Node1(G[i+1][j],1));
        }
        sort(tmp.begin(),tmp.end());
      //  bug1(i);
        G[i].clear();
        rep(j,tmp.size()){
            int id=tmp[j].id,flag=tmp[j].flag;
            if(flag){
                update(P[id].y,mm-i,1,UP-1,1);
            }else{
                int mv=query(P[id].y+1,UP-1,1,UP-1,1);
        //        pf("query maxv= %d will be equal %d\n",mv,mm-i);
                if(mv==mm-i){
          //          pf("ans push id = %d\n",P[id].z);
                    G[i].PB(id);
                }
            }
        }
        if(G[i].size()==1)ans1.PB(P[G[i][0]].z);
        else rep(j,G[i].size())ans2.PB(P[G[i][j]].z);
    }
    rep(i,ans1.size())ans2.PB(ans1[i]);
    sort(ans2.begin(),ans2.end());
    ans2.erase(unique(ans2.begin(),ans2.end()),ans2.end());
    pf("%d ",int(ans2.size()));
    rep(i,ans2.size()){
        if(i==ans2.size()-1)pf("%d\n",ans2[i]+1);
        else pf("%d ",ans2[i]+1);
    }
    sort(ans1.begin(),ans1.end());
    ans1.erase(unique(ans1.begin(),ans1.end()),ans1.end());
    pf("%d ",int(ans1.size()));
    rep(i,ans1.size()){
        if(i==ans1.size()-1)pf("%d\n",ans1[i]+1);
        else pf("%d ",ans1[i]+1);
    }
}
int main(){
    while(~sf("%d",&n)){
        init();
        input();
        solve();
    }
    return 0;
}


