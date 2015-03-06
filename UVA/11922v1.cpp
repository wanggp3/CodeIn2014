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
    Node* ch[2];
    int s,v,flip;
    Node(){
        ch[0]=ch[1]=NULL;
        v=flip=0;s=1;
    }
    Node(int v){
        this->v=v;
        s=1;
        flip=0;
        ch[0]=ch[1]=NULL;
    }
    void maintain(){//节点维护的信息
        s=1;
        if(ch[0]!=NULL)s+=ch[0]->s;
        if(ch[1]!=NULL)s+=ch[1]->s;
    }
    int cmp(int k)const{
        int d= (ch[0]==NULL?0:ch[0]->s);
        if(d+1==k)return -1;
        else return k <= d ? 0:1;
    }
    void pushdown(){//节点信息下传
        if(flip){
            flip=0;
            swap(ch[0],ch[1]);
            if(ch[0]!=NULL)ch[0]->flip^=1;
            if(ch[1]!=NULL)ch[1]->flip^=1;
        }
    }
};
void rotate(Node* &o,int d){//d=0 左旋   1 右旋
    Node* k=o->ch[d^1]; o->ch[d^1]=k->ch[d];k->ch[d]=o;
    o->maintain();k->maintain();o=k;
}
void splay(Node* &o,int k){//把序列的第k（1<=k<= o->s)个节点伸展为根节点
    o->pushdown();
    int d = o->cmp(k);
    int l=(o->ch[0]==NULL? 0:o->ch[0]->s);
    if(d!=-1){
        if(d==0)splay(o->ch[0],k);
        else splay(o->ch[1],k-l-1);
        rotate(o,d^1);
    }
}
Node *Left,*Right,*Root,*Mid,*Temp;
Node* build(int l,int r){
    if(l==r)return new Node(l);
    else{
        int m=(l+r)>>1;
        Node* t=new Node(m);
        if(l<m)t->ch[0] = build(l,m-1);//记得判断空指针
        t->ch[1]=build(m+1,r);//he he 
        t->maintain();
        return t;
    }
}
void removetree(Node* &o){
    if(o->ch[0]!=NULL)removetree(o->ch[0]);
    if(o->ch[1]!=NULL)removetree(o->ch[1]);
    delete o;
}
void print(Node* o){
    if(o==NULL)return;
    o->pushdown();
    if(o->ch[0]!=NULL)print(o->ch[0]);
    pf("%d\n",o->v);
    if(o->ch[1]!=NULL)print(o->ch[1]);
}
//here left must not be null 
Node* merge(Node* left,Node* right){
    if(left==NULL)return right;
    else if(right==NULL)return left;
    splay(left,left->s);
    left->ch[1]=right;//
    left->maintain();
    return left;
}
//把o节点子树的前k个放在left，剩下的放在right子树
void split(Node* o,int k,Node* &left,Node* &right){
    if(k==0){//特判
        left=NULL;
        right=o;
        return ;
    }
    splay(o,k);
    left=o;
    right=o->ch[1];
    o->ch[1]=NULL;
    left->maintain();
}
int n,m;
int main(){
    while(~sf("%d%d",&n,&m)){
        if(Root!=NULL){
           removetree(Root);
        }
        Root=build(1,n);
        while(m--){
            int a,b;
            sf("%d%d",&a,&b);
            split(Root,a-1,Left,Temp);
            split(Temp,b-a+1,Mid,Right);
            Mid->flip^=1;
            Root = merge( merge(Left,Right),Mid);
        }
        print(Root);
    }
    return 0;
}


