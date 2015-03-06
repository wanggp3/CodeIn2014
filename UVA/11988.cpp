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
char str[N];
struct Node{
    char c;
    Node *next;
    Node(char c,Node* next=NULL):c(c),next(next){
    }
}*head,*tail;
void print(Node *p){
    while(p!=NULL){
        pf("%c",p->c);
        p=p->next;
    }
    pf("\n");
}
void solve(){
    int n=strlen(str);
    head=tail=new Node('$');
    Node* t=tail;
    rep(i,n){
        char c=str[i];
        if(c=='['){
            t=head;
        }else if(c==']'){
            t=tail;
        }else{
            //if(t==tail){
              //  t->next=new Node(c);
               // t=t->next;
                //tail=t;
           // }else{
                t->next=new Node(c,t->next);
                t=t->next;
                if(tail->next!=NULL)tail=tail->next;
            //}
        }
       // pf("%d : ",i);print(head);
    }
    Node *r=head->next;
    while(r!=NULL){
        pf("%c",r->c);
        r=r->next;
    }
    pf("\n");
    /*while(r!=NULL){
        Node *k=r;
        r=r->next;
        delete k;
    }*/
}
int main(){
    while(~sf("%s",str)){
        solve(); 
    }
    return 0;
}


