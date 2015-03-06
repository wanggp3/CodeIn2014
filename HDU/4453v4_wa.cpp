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
const int N=200005;
using namespace std;
typedef pair<int,int>PII;
int a[N];
int n,m,k1,k2;
struct D{
    deque<int>Q[3];
    int add,rev;
    void init(){
        rep(i,3){
            while(!Q[i].empty())Q[i].pop_front();
        }
        add=0;
        rev=0;
        for(int i=0;i<k1;i++)Q[0].PB(a[i]);
        for(int i=k1;i<k2;i++)Q[1].PB(a[i]);
        for(int i=k2;i<n;i++)Q[2].PB(a[i]);
    }
    void Add(int x){
        add+=x;
    }
    void Reverse(){
        rev^=1;
    }
    void Insert(int x){
        Q[2].push_front(Q[1].back()+add);
        Q[1].pop_back();
        if(!rev){
            Q[1].push_front(Q[0].back());
            Q[0].pop_back();
            int tmp=Q[0].front();
            Q[0].pop_front();
            Q[0].push_front(x-add);
            Q[0].push_front(tmp);
        }else{
            Q[1].push_front(Q[0].front());
            Q[0].pop_front();
            int tmp=Q[0].back();
            Q[0].pop_back();
            Q[0].push_back(x-add);
            Q[0].push_back(tmp);
        }
    }
    void Delete(){
        Q[1].push_back(Q[2].front()-add);
        Q[2].pop_front();
        if(!rev){
           Q[0].push_back(Q[1].front());
           Q[1].pop_front();
           Q[0].pop_front();
        }else{
            Q[0].push_front(Q[1].front());
            Q[1].pop_front();
            Q[0].pop_back();
        }
    }
    void Move(int x){
        if(x==2){
            int tmp;
            if(!rev){
                tmp=Q[0].front();
                Q[0].pop_front();
            }else{
                tmp=Q[0].back();
                Q[0].pop_back();
            }
            Delete();
            Q[2].push_back(tmp+add);
        }else if(x==1){
            int tmp=Q[2].back();
            Q[2].pop_back();
            Q[2].push_front(Q[1].back()+add);
            Q[1].pop_back();
            if(!rev){
                Q[1].push_front(Q[0].back());
                Q[0].pop_back();
                Q[0].push_front(tmp-add);
            }else{
                Q[1].push_front(Q[0].front());
                Q[0].pop_front();
                Q[0].push_back(tmp-add);
            }
        }
    }
    void Query(){
        if(!rev){
            pf("%d\n",Q[0].front()+add);
        }else pf("%d\n",Q[0].back()+add);
    }
}solver;
void solve(){
    rep(i,n)sf("%d",&a[i]);
    solver.init();
    while(m--){
        char op[100];
        sf("%s",op);
        if(op[0]=='a'){
            int x;
            sf("%d",&x);
            solver.Add(x);
        }else if(op[0]=='r'){
            solver.Reverse();
        }else if(op[0]=='i'){
            int x;sf("%d",&x);
            solver.Insert(x);
        }else if(op[0]=='d'){
            solver.Delete();
        }else if(op[0]=='m'){
            int x;sf("%d",&x);
            solver.Move(x);
        }else if(op[0]=='q'){
            solver.Query();
        }
    }
}
int main(){
    int cas=1;
    while(~sf("%d%d%d%d",&n,&m,&k1,&k2)&&(n+m+k1+k2)){
        pf("Case #%d:\n",cas++);
        solve();
    }
    return 0;
}


