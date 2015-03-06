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
int n,m;
int w[N];
vector<int>vec;
vector<int>::iterator it;
int ans;
void init(){
    ans=0;
    rep(i,n)sf("%d",&w[i+1]);
    vec.clear();
    rep(j,m){
        int x;sf("%d",&x);
        it=find(vec.begin(),vec.end(),x);
        if(it==vec.end()){
            rep(i,vec.size())ans+=w[vec[i]];
            vec.PB(x);
        }else{
            for(int i=vec.size()-1;i;i--){
                if(vec[i]==x){
                    break;
                }else ans+=w[vec[i]];
            }
            vec.erase(it);
            vec.PB(x);
        }
    }
    pf("%d\n",ans);
}
int main(){
    while(~sf("%d%d",&n,&m)){
        init();
    }
    return 0;
}


