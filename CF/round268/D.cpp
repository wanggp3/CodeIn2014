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
const int N=100005;
using namespace std;
int n;
int a,b;
vector<int>X;
struct node{
    int v,id;
    int vis;
    node(int v=0,int id=0,bool vis=0):v(v),id(id),vis(vis){
    }
    bool operator<(const node& rhs)const{
        return v<rhs.v;
    }
}nod[N];
bool cmp(node x,node y){
    return x.id<y.id;
}
int main(){
    int tp=1e9;
    tp+=tp;
    cout<<tp<<endl;
    sf("%d%d%d",&n,&a,&b);
    int x;
    rep(i,n){
        sf("%d",&nod[i].v);
        nod[i].id=i;
        nod[i].vis=-1;
        X.PB(nod[i].v);
    }
    sort(nod,nod+n);
    sort(X.begin(),X.end());
    bool ok=1;
    if(a==b)ok=0;
    rep(i,n){
        //pf("vis %d\n",nod[i].vis);
        if(nod[i].vis==-1){
        
            int id1=lower_bound(X.begin(),X.end(),a-X[i])-X.begin();
            int id2=lower_bound(X.begin(),X.end(),b-X[i])-X.begin();
           // pf("id %d %d\n",id1,id2);
            if(id1<n&&X[id1]+X[i]==a&&nod[id1].vis==-1){
                nod[id1].vis=nod[i].vis=1;
               // pf("%d %d\n",i,id1);
                continue;
            }
            if(id2<n&&X[id2]+X[i]==b&&nod[id2].vis==-1){
                nod[id2].vis=nod[i].vis=2;
                continue;
            }
            ok=0;
            break;
        }else if(nod[i].vis==1){
          int id=lower_bound(X.begin(),X.end(),b-nod[i].v)-X.begin();
          if(id<n&&nod[id].v+nod[i].v==b&&nod[id].vis==2){
              ok=0;
              break;
          }
        }else if(nod[i].vis==2){
            int id=lower_bound(X.begin(),X.end(),a-nod[i].v)-X.begin();
            if(id<n&&nod[id].v+nod[i].v==a&&nod[id].vis==1){
                ok=0;
                break;
            }
        }
    }
    if(ok){
        puts("YES");
        sort(nod,nod+n,cmp);
        rep(i,n){
            if(i==n-1)pf("%d\n",nod[i].vis-1);
            else pf("%d ",nod[i].vis-1);
        }
    }else puts("NO");
    return 0;
}

