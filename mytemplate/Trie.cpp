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
const int maxnode=10000;
const int sigma_size=26;
struct Trie{
    int ch[maxnode][sigma_size];
    int val[maxnode];
    int sz;
    Trie(){sz=1;memset(ch[0],0,sizeof ch[0]);}
    int idx(char x){return x-'a';}
    void insert(char* s,int v){
        int u=0,n=strlen(s);
        rep(i,n){
            int v=idx(s[i]);
            if(!ch[u][v]){
                memset(ch[sz],0,sizeof ch[sz]);
                val[sz]=0;
                ch[u][v]=sz++;
            }
            u=ch[u][v];
        }
        val[u]=v;
    }
    int find(char* s){
        int u=0,n=strlen(s);
        rep(i,n){
            int v=idx(s[i]);
            if(!ch[u][v])return -1;
            u=ch[u][v];
        }
        return val[u];
    }
};
struct Node{
    int v;
    Node* next[26];
    Node(int v=0){
        this->v=v;
        rep(i,26)next[i]=NULL;
    }
    
};
Node* root=new Node();
void insert(char *s,int v){
    int n=strlen(s);
    Node* cur=root;
    rep(i,n){
        int v=s[i]-'a';
        if(cur->next[v]==NULL){
            cur->next[v]=new Node(0);
        }
        cur=cur->next[v];
    }
    cur->v=v;
}
int find(char* s){
    int n=strlen(s);
    Node* cur=root;
    rep(i,n){
        int v=s[i]-'a';
        if(cur->next[v]==NULL)return -1;
        cur=cur->next[v];
    }
    return cur->v;
}
int main(){
    
    return 0;
}


