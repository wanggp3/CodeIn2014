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
struct Node{
    int r,v,s;//r priority; v value; s size of subtree
    Node* ch[2];// left&right subtree
    Node(int v=0):v(v){
        ch[0]=ch[1]=NULL;
        r=rand();
        s=1;
    }
    int cmp(int x)const{
        if(x==v)return -1;
        else return x<v?0:1;
    }
    void maintain(){
        s=1;
        if(ch[0]!=NULL)s+=ch[0]->s;
        if(ch[1]!=NULL)s+=ch[1]->s;
    }
};
//调用的时候 Node * root=NULL;
bool find(Node* o,int x){
    while(o!=NULL){
       int d=o->cmp(x); 
       if(d==-1)return true;
       o=o->ch[d];
    }
    return false;
}
void rotate(Node* &o, int d){
    Node* k = o->ch[d^1];
    o->ch[d^1] = k->ch[d];
    k->ch[d] = o;
    o->maintain();
    k->maintain();
    o = k;
}
//若不予许出现相同节点，那么调用前先调用find，判断是否存在相同节点，remove类似
void insert(Node* &o,int x){
    if(o==NULL)o=new Node(x);
    else{
        int d=( x < o->v ? 0 : 1 );// 这里相同节点的处理是放在右边
        insert(o->ch[d],x);
        if(o->ch[d]->r > o->r)rotate(o,d^1);
    }
    o->maintain();
}
void remove(Node* &o,int x){
    int d=o->cmp(x);
    if(d==-1){
       Node* u=o;
       if(o->ch[0]!=NULL&&o->ch[1]!=NULL){
          int d2(o->ch[0]->r > o->ch[1]->r ? 1:0 );
          rotate(o,d2);
          remove(o->ch[d2],x);
       }else{
           if(o->ch[0]==NULL)o=o->ch[1];
           else o=o->ch[0];
           delete u;
       }
    }else{
        remove(o->ch[d],x);
    }
    if(o!=NULL)o->maintain();
}
int Kth(Node* o,int k){
    if(o==NULL||k<=0||k>o->s)return -1;//不存在
    int s=(o->ch[1]==NULL?0:o->ch[1]->s);
    if(k==s+1)return o->v;
    else if(k<=s)return Kth(o->ch[1],k);
    else return Kth(o->ch[0],k-s-1);
}
void print(Node* o){
    if(o==NULL)return;
    else{
        print(o->ch[0]);
        pf("%d ",o->v);
        print(o->ch[1]);
    }
}
void demo(){
    Node* root=NULL;
    rep(i,6){
        int x=rand()%10;
        cout<<"insert"<<x<<endl;
        insert(root,x);
    }
    cout<<"size"<<root->s<<endl;
    rep(i,6){
        int x=rand()%10;
        bool f=find(root,x);
        if(f)cout<<"find"<<x<<endl;
        else cout<<"cannot find"<<x<<endl;
    }
    print(root);puts("");
}
int main(){
    demo(); 
    return 0;
}


