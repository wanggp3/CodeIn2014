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
vector<int>v;
LL a[]={0,12,24,36,57,78,99,201,303,405,516,627,738,849,960,1071,1191,1311,1431,1632,1833,2034,2244,2454,2664};
void solve(LL tmp){
    cout<<"tmp"<<tmp<<endl;
    for(int i=24;i>=0;i--){
        if(tmp>=a[i]){
            pf("%d\n",i);
            return;
        }
    }
}
int main(){

    int r,g,b;
    cin>>r>>g>>b;
    v.PB(r);
    v.PB(g);
    v.PB(b);
    sort(v.begin(),v.end());
    rep(i,v.size()){
        cout<<v[i]<<" v";
    }
    LL tmp=v[0]*1LL*100+v[1]*1LL*10+v[2]*1LL;
    solve(tmp);
    return 0;
}


