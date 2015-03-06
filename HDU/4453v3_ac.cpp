//白色上的模板，先静态申请结构体数组，再动态使用，时间应该更快；还有个小技巧，它的空指针用真实的null指针代替，这样即使访问了null的内容也没关系，减少出错的可能性
// UVa11922 Permutation Transformer
// Rujia Liu
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

struct Node {
  Node *ch[2];
  int s;
  int flip;
  int v;
  int add;
  int cmp(int k) const {
    int d = k - ch[0]->s;
    if(d == 1) return -1;
    return d <= 0 ? 0 : 1;
  }
  void maintain() {
    s = ch[0]->s + ch[1]->s + 1;
  }
  void pushdown() {
    if(flip) {
      flip = 0;
      swap(ch[0], ch[1]);
      ch[0]->flip = !ch[0]->flip;
      ch[1]->flip = !ch[1]->flip;
    }
    if(add){
        v+=add;
        ch[0]->add+=add;
        ch[1]->add+=add;
        add=0;
    }
  }
};

Node *null = new Node();

void rotate(Node* &o, int d) {
  Node* k = o->ch[d^1]; o->ch[d^1] = k->ch[d]; k->ch[d] = o;
  o->maintain(); k->maintain(); o = k; 
}

void splay(Node* &o, int k) {
  o->pushdown();
  int d = o->cmp(k);
  if(d == 1) k -= o->ch[0]->s + 1;
  if(d != -1) {
    Node* p = o->ch[d];
    p->pushdown();
    int d2 = p->cmp(k);
    int k2 = (d2 == 0 ? k : k - p->ch[0]->s - 1);
    if(d2 != -1) {
      splay(p->ch[d2], k2);
      if(d == d2) rotate(o, d^1); else rotate(o->ch[d], d);
    }
    rotate(o, d^1);
  }
}

// 合并left和right。假定left的所有元素比right小。注意right可以是null，但left不可以
Node* merge(Node* left, Node* right) {
  splay(left, left->s);
  left->ch[1] = right;
  left->maintain();
  return left;
}

// 把o的前k小结点放在left里，其他的放在right里。1<=k<=o->s。当k=o->s时，right=null
void split(Node* o, int k, Node* &left, Node* &right) {
  splay(o, k);
  left = o;
  right = o->ch[1];
  o->ch[1] = null;
  left->maintain();
}

const int maxn = 200000 + 10;
int a[maxn];
struct Splay {
  int n;
  Node seq[maxn];
  Node *root;
  Node* newNode(int v=0){
      Node* ret=&seq[++n];
      ret->v=v;
      ret->ch[0]=ret->ch[1]=null;
      ret->flip=ret->add=0;
      ret->s=1;
      return ret;
  }
  Node* build(int sz) {
    if(!sz) return null;
    Node* L = build(sz/2);
    Node* o = &seq[++n];
    o->v = a[n]; // 节点编号
    o->ch[0] = L;
    o->ch[1] = build(sz - sz/2 - 1);
    o->flip = o->s = o->add = 0;
    o->maintain();
    return o;
  }

  void init(int sz) {
    n = 0;
    null->s = 0;
    root = build(sz);
  }
}T;
#include<cstring>
#define rep(i,n) for(int i=0;i<n;i++)
#define fab(i,a,b) for(int i=a;i<=b;i++)
#define sf scanf
#define pf printf
vector<int> ans;
void print(Node* o) {
  if(o != null) {
    o->pushdown();
    print(o->ch[0]);
    ans.push_back(o->v);
    print(o->ch[1]);
  }
}

void debug(Node* o) {
  if(o != null) {
    o->pushdown();
    debug(o->ch[0]);
    printf("%d ", o->v-1);
    debug(o->ch[1]);
  }
}
int n,M,k2,k1;
void bug(){
    ans.clear();
    puts("bug");
    print(T.root);
    rep(i,ans.size())pf("%d ",ans[i]);pf("\n");
}
void init(){
   fab(i,1,n)sf("%d",&a[i]);
   T.init(n);
}
void Query(){
    splay(T.root,1);
    T.root->pushdown();
    pf("%d\n",T.root->v);
}
void Add(int x){
    T.root->pushdown();
    if(k2>=T.root->s){
        T.root->add+=x;
    }else{
        splay(T.root,k2+1);
        T.root->ch[0]->add+=x;
        T.root->maintain();
    }
}
void Reverse(){
    T.root->pushdown();
    if(k1>=T.root->s){
        T.root->flip^=1;
    }else{
        splay(T.root,k1+1);
        T.root->ch[0]->flip^=1;
    }
    T.root->maintain();
}
void Insert(int x){
    T.root->pushdown();
    splay(T.root,1);
    splay(T.root->ch[1],1);
    T.root->ch[1]->pushdown();
    T.root->ch[1]->ch[0]=T.newNode(x);
    T.root->ch[1]->maintain();
    T.root->maintain();
}
void Delete(){
    T.root->pushdown();
    splay(T.root,2);
    T.root->ch[0]=null;
    T.root->maintain();
}
void Move(int x){
    if(x==2){
        splay(T.root,2);
        T.root->pushdown();
        Node* first=T.root->ch[0];
        T.root->ch[0]=null;
        T.root->maintain();
        splay(T.root,T.root->s);
        T.root->pushdown();
        T.root->ch[1]=first;
        T.root->maintain();
    }else if(x==1){
        splay(T.root,T.root->s-1);
        T.root->pushdown();
        Node* end=T.root->ch[1];
        T.root->ch[1]=null;
        T.root->maintain();
        splay(T.root,1);
        T.root->pushdown();
        T.root->ch[0]=end;
        T.root->maintain();
    }
}
void solve(){
   char op[100];
   while(M--){
       scanf("%s",op);
       if(!strcmp(op,"query")){
           Query();
       }else if(!strcmp(op,"add")){
           int x;
           sf("%d",&x);
           Add(x);
       }else if(!strcmp(op,"bug")){
           bug();
       }else if(!strcmp(op,"reverse")){
           Reverse();
       }else if(!strcmp(op,"insert")){
           int x;sf("%d",&x);
           Insert(x);
       }else if(!strcmp(op,"delete")){
           Delete();
       }else if(!strcmp(op,"move")){
           int x;sf("%d",&x);
           Move(x);
       }
   }
}
int main(){
    int cas=1;
  while(~scanf("%d%d%d%d",&n,&M,&k1,&k2)&&(n+M+k1+k2)){
      pf("Case #%d:\n",cas++);
      init();
      solve();
  }
  return 0;
}
