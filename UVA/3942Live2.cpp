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
const int N=300005;
const int M=20071027;
using namespace std;
typedef pair<int,int>PII;
struct Node{
    int v;
    Node* next[26];
    Node(int v=0){
        this->v=v;
        rep(i,26)next[i]=NULL;
    }
}*root;

    void insert(char* s,int val){
        Node* cur=root;
        int n=strlen(s);
        rep(i,n){
            int v=s[i]-'a';
            if(cur->next[v]==NULL)cur->next[v]=new Node();
            cur=cur->next[v];
        }
        cur->v=val;
        //cout<<(root->next[0])->v<<endl;
    }
char str[N],word[105];
int S;
int d[N];
void init(){
    root=new Node();
    sf("%d",&S);
    rep(i,S){
        sf("%s",word);
        insert(word,i+1);
    }
}
void solve(){
    //cout<<(root->next[0])->v<<endl;
   int n=strlen(str);
   d[n]=1;
   for(int i=n-1;i>=0;i--){
       d[i]=0;
       int k=i,v=str[i]-'a';
       Node* cur=root;
       while(k<n&&cur->next[v]!=NULL){
           if(cur->next[v]->v!=0)d[i]=(d[i]+d[k+1])%M;
           cur=cur->next[v];
           k++;
           v=str[k]-'a';
       }
   }
   pf("%d\n",d[0]);
}
int main(){
    int cas=1;
    while(~sf("%s",str)){
        init();
        pf("Case %d: ",cas++);
        solve();
    }
    return 0;
}


