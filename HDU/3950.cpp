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
#define lowbit(x) x&-x
const int N=51005;
using namespace std;
typedef pair<int,int>PII;
int n,Q;
int C[N];
set<int>S[N];
int ed[N],st[N<<2],len[N<<2];
int stlen,edlen;
void build(int l,int r,int rt){
    st[rt]=INF;
    if(l==r)S[l].clear();
    else{
        int m=(l+r)>>1;
        build(lson);
        build(rson);
    }
}

void add(int x,int d){
    while(x<=n){
        C[x]+=d;
        x+=lowbit(x);
    }
}
int sum(int x){
    int ret=0;
    while(x){
        ret+=C[x];
        x-=lowbit(x);
    }
    return ret;
}

  int Kth(int k){//  nlogn
     int ind=0;
     for(int i=20;i>=0;i--){
        ind^=(1<<i);
        if(ind<n&&k>C[ind])k-=C[ind];
        else ind^=(1<<i);
     }
     return ind+1;
  }

/*int Kth(int k){//nlogn^2
    int L=0,R=n;
    while(L+1<R){
       int M=L+(R-L)/2;
       if(sum(M)>=k)R=M;
       else L=M;
    }
    return R;
}*/
void init(){
   sf("%d%d",&n,&Q);
   memset(C,0,sizeof C);
   build(1,n,1);
   stlen=edlen=n;
}
void push_up(int rt){
    if(st[rt<<1]<st[rt<<1|1]){
        st[rt]=st[rt<<1];
        len[rt]=len[rt<<1];
    }else{
        st[rt]=st[rt<<1|1];
        len[rt]=len[rt<<1|1];
    }
}
void update(int v,int p,bool add,int l,int r,int rt){
    if(l==r){
       if(add)S[l].insert(v);
       else S[l].erase(v);
       if(S[l].size()==0)st[rt]=INF;
       else{
           st[rt]=*(S[l].begin());
           len[rt]=l;
       }
    }else{
        int m=(l+r)>>1;
        if(p<=m)update(v,p,add,lson);
        else update(v,p,add,rson);
        push_up(rt);
    }
}
PII qurry(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R) return MP(st[rt],len[rt]);
    else{
        int m=(l+r)>>1;
        PII ret1=MP(INF,0),ret2=MP(INF,0);
        if(L<=m)ret1=qurry(L,R,lson);
        if(R>m)ret2=qurry(L,R,rson);
        if(ret1.first<ret2.first)return ret1;
        else return ret2;
    }
}
//guarteen can get
int getst(int st,int len,int m,int a,int b){
    int ed=st+len-1;
    return max(ed-m-b+1,st);
}
void solve(){
    while(Q--){
        char op[10];
        sf("%s",op);
        if(op[0]=='A'){
            int m,a,b;
            sf("%d%d%d",&m,&a,&b);
            if(stlen>=m){
               if(stlen==n){
                   ed[1]=m;
                   add(1,1);
                   stlen=0;
                   edlen-=m;
                   pf("%d\n",1);
               }else{
                   int id=getst(1,stlen,m,a,b);   
                   ed[id]=id+m-1;
                   add(id,1);
                   pf("%d\n",id);
                   if(ed[id]+1<=stlen)update(ed[id]+1,stlen-ed[id],1,1,n,1);
                   stlen=id-1;
               }
            }else{
               PII ret=qurry(m,m+a+b,1,n,1);
               if(ret.first!=INF){
                    update(ret.first,ret.second,0,1,n,1);
                    int id=getst(ret.first,ret.second,m,a,b);
                    ed[id]=id+m-1;
                    add(id,1);
                    pf("%d\n",id);
                    int len=id-1-ret.first+1;
                    int p=ret.first;
                    if(ret.first<=id-1)update(p,len,1,1,n,1);
                    p=ed[id]+1;
                    len=ret.first+ret.second-1;
                    if(p<=len)update(p,len-p+1,1,1,n,1);

               }else{
                  if(edlen<m)pf("-1\n");
                  else{
                      int id=n-edlen+1;
                      ed[id]=id+m-1;
                      edlen=n-ed[id];
                      add(id,1);
                      pf("%d\n",id);
                  }
               }
            }
        }else{
            int k;
            sf("%d",&k);
            int sumn=sum(n);
            if(k>sumn||k<=0)continue;
            int id=Kth(k);
            int id1=1;
            if(k>1)id1=ed[Kth(k-1)]+1;
            int len1=id-id1;
            if(len1>0&&id1!=1)update(id1,len1,0,1,n,1);

            int id2=n;
            int len2=0;
            if(k<sumn){
                id2=Kth(k+1)-1;
                len2=id2-ed[id];
            }
            if(len2>0&&id2!=n)update(ed[id]+1,len2,0,1,n,1);

            if(id1!=1&&id2!=n)update(id1,id2-id1+1,1,1,n,1);
            if(id1==1)stlen=id2;
            if(id2==n)edlen=n-id1+1;
            add(id,-1);
        }
    }
}
int main(){
    int T;sf("%d",&T);
    rep(cas,T){
        init();
        pf("Case #%d:\n",cas+1);
        solve();
    }
    return 0;
}


