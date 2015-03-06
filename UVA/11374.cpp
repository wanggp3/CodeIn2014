#include<iostream>
#include<cstring>
#include<stdio.h>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<iomanip>
#include<cmath>
#include<list>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)
#define fab(i,a,b) for(int i=(a);i<=(b);i++)
#define fba(i,b,a) for(int i=(b);i>=(a);i--)
#define cls(x) memset(x,0,sizeof(x))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define LL long long 
#define INF 1e9
#define MP make_pair
const int N=100105;
using namespace std;
struct Edge{
    int u,v,w;
    Edge(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
};
struct Node{
    int d,u;
    Node(int d=0,int u=0):d(d),u(u){}
    bool operator<(const Node& rhs)const{
        return d>rhs.d;
    }
};
struct Dijkstra{
    int n,m;
    vector<Edge>edges;
    vector<int>G[N];
    bool done[N];
    int d[N],p[N];
    void init(int n){
        this->n=n;
        for(int i=0;i<n;i++)G[i].clear();
        edges.clear();
    }
    void addEdge(int u,int v,int w){
        edges.push_back(Edge(u,v,w));
        m=edges.size();
        G[u].push_back(m-1);
    }
    void dij(int s){
        priority_queue<Node>Q;
        for(int i=0;i<n;i++)d[i]=INF;
        d[s]=0;
        memset(done,0,sizeof done);
        Q.push(Node(0,s));
        while(!Q.empty()){
            Node x=Q.top();Q.pop();
            int u=x.u;
            if(done[u])continue;
            done[u]=1;
            for(int i=0;i<G[u].size();i++){
                Edge& e=edges[G[u][i]];
                if(d[e.v]>d[u]+e.w){
                    d[e.v]=d[u]+e.w;
                    p[e.v]=G[u][i];
                    Q.push(Node(d[e.v],e.v));
                }
            }
        }
    }
}solver;
int n,s,e,m,k;
int d1[N],d2[N],p1[N],p2[N];
void printA(int x){
    if(x==s){
        printf("%d",x+1);
    }else{
        int t=p1[x];
        Edge& e=solver.edges[t];
        printA(e.u);
        printf(" %d",x+1);
    }
}
void printB(int x){
    if(x==e){
        printf(" %d",x+1);
    }else{
        printf(" %d",x+1);
        int t=p2[t];
        Edge& e=solver.edges[t];
        printB(e.u);
    }
}
int main(){
    int cnt=0;
    while(~scanf("%d%d%d",&n,&s,&e)){
        if(cnt++)printf("\n");
        s--;e--;
        solver.init(n);
        scanf("%d",&m);
        int u,v,w;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);
            u--;v--;
            solver.addEdge(u,v,w);
            solver.addEdge(v,u,w);
        }
        solver.dij(s);
        for(int i=0;i<n;i++){
            d1[i]=solver.d[i];
            p1[i]=solver.p[i];
        }
        solver.dij(e);
        for(int i=0;i<n;i++){
            d2[i]=solver.d[i];
            p2[i]=solver.p[i];
        }
        scanf("%d",&k);
        int ans=d1[e];
        int tmpu=-1,tmpv=-1;
        for(int i=0;i<k;i++){
            scanf("%d%d%d",&u,&v,&w);
            u--;v--;
            if(ans>d1[u]+d2[v]+w){
                ans=d1[u]+d2[v]+w;
                tmpu=u;
                tmpv=v;
            }
            swap(u,v);
            if(ans>d1[u]+d2[v]+w){
                ans=d1[u]+d2[v]+w;
                tmpu=u;
                tmpv=v;
            }
        }
        if(tmpu==-1){
            printA(e);
            printf("\n");
            printf("Ticket Not Used\n");
            printf("%d\n",ans);
        }else{
            printA(tmpu);
            printB(tmpv);
            printf("\n");
            printf("%d\n",tmpu+1);
            printf("%d\n",ans);
        }
    }
    return 0;
}

