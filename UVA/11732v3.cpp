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
const int maxnode=4000*1005;
char str[N];
struct Node{
    int v,ed,ch;
    Node *next,*brother;
    void init(int v=0,int ed=0,int ch=0){
        this->ed=ed;
        this->v=v;
        this->ch=ch;
        //next=new Node();
        //brother=new Node();
        next=NULL;
        brother=NULL;
    }
};
LL ans=0;
Node *ROOT;
void insert(char* s){
    int n=strlen(s);
    Node* cur=ROOT;
    puts("insert begin");
    rep(i,n){
        /*f(cur==NULL){
            puts("cur null");
            return;
        }else{
            puts("cur not null");
            return;
        }*/
        while(cur->brother!=NULL){
            if(cur->brother->ch==s[i])break;
            else cur=cur->brother;
        }
        puts("find ok");
       // return ;
        if(cur==NULL){
            puts("find null");
            cur=new Node();
            cur->ch=s[i];
            cur->v=0;
            cur->ed=0;
            cur->next=new Node();
        }else {
            puts("find not null");
        }
        //return ;
        ans+=(cur->v)*2LL;
        cur=cur->next;
        puts("next ok");
    }
    ans+=1LL*(cur->ed);
    puts("ans++ ok");
    cur->ed++;
    puts("ed++ ok");
}
int main(){
    int cas=1;
    int n;
    while(~sf("%d",&n)&&n){
        ROOT=new Node();
        ans=0;
        puts("root new ok");
        rep(i,n){
            sf("%s",str);
            insert(str);
        }
        pf("Case %d: %lld\n",cas++,ans+1LL*n*(n-1)/2);
    }
    return 0;
}


