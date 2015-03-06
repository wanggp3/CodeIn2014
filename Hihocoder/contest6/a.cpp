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
string tmp="marshtomp";
bool same(string s){
    if(s.size()!=tmp.size())return 0;
    int n=tmp.size();
    rep(i,n){
        if(tolower(s[i])!=tmp[i])return 0;
    }
    return 1;
}
void solve(string s){
    //cout<<"so ==="<<s<<endl;
    string ret="";
    int n=s.size();
    int m=tmp.size();
    for(int i=0;i<n;i++){
        if(same(s.substr(i,m))){
            for(int j=i;j<i+m;j++)s[j]=tmp[j-i];
            i=i+m-1;
            ret+="fjxmlhx";
        }else ret+=s[i];
    }
    cout<<ret<<endl;
}
int main(){
    string s;
    while(getline(cin,s)){
        solve(s);
    }
    return 0;
}


