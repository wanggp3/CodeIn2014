//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<cmath>
#include<climits>
#include<string>
#include<map>
#include<queue>
#include<vector>
#include<stack>
#include<set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define pb(a) push(a)
#define INF 0x1f1f1f1f
#define lson idx<<1,l,mid
#define rson idx<<1|1,mid+1,r
#define PI  3.1415926535898
template<class T> T min(const T& a,const T& b,const T& c) {
    return min(min(a,b),min(a,c));
}
template<class T> T max(const T& a,const T& b,const T& c) {
    return max(max(a,b),max(a,c));
}
void debug() {
#ifdef ONLINE_JUDGE
#else

    freopen("d:\\in1.txt","r",stdin);
    freopen("d:\\out1.txt","w",stdout);
#endif
}
int getch() {
    int ch;
    while((ch=getchar())!=EOF) {
        if(ch!=' '&&ch!='\n')return ch;
    }
    return EOF;
}

const int maxn=505;

struct Edge
{
    int u,v,dist;
};
struct HeapNode
{
    int d,u;
    bool operator < (const HeapNode &ant) const
    {
        if(d!=ant.d)return d>ant.d;
        else return u>ant.u;
    }
};
struct dijksta
{
    int n;
    vector<int> g[maxn];
    vector<Edge> edge;
    int done[maxn];
    void init(int n)
    {
        this->n=n;
        for(int i=1;i<=n;i++)
            g[i].clear();
        edge.clear();
    }
    void add(int u,int v,int dist)
    {
        Edge e=(Edge){u,v,dist};
        edge.push_back(e);
        g[u].push_back(edge.size()-1);
    }

    void solve(int *d,int *p,int s)
    {
        priority_queue<HeapNode> q;
        memset(done,0,sizeof(done));
        for(int i=1;i<=n;i++)
            d[i]=INF;
        d[s]=0;
        p[s]=-1;
        q.push((HeapNode){0,s});
        while(!q.empty())
        {
            HeapNode x=q.top();q.pop();
            int u=x.u;
            if(done[u])continue;
            done[u]=1;
            for(int i=0;i<g[u].size();i++)
            {
                int v=edge[g[u][i]].v;
                int w=edge[g[u][i]].dist;
                if(w+d[u]<d[v])
                {
                    d[v]=d[u]+w;
                    q.push((HeapNode){d[v],v});
                    p[v]=u;
                }
            }
        }
    }
}solver;


int f[maxn],g[maxn],pf[maxn],pg[maxn];
Edge Ticket[maxn*2];

int check(Edge &e)
{
    return f[e.u]+e.dist+g[e.v];
}
int main()
{
    int n,s,e;
    while(scanf("%d%d%d",&n,&s,&e)!=EOF)
    {
        solver.init(n);
        int m;
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            solver.add(u,v,w);
            solver.add(v,u,w);
        }
        solver.solve(f,pf,s);
        solver.solve(g,pg,e);
        int k;
        scanf("%d",&k);
        for(int i=0;i<k;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            Ticket[i*2]=(Edge){u,v,w};
            Ticket[i*2+1]=(Edge){v,u,w};
        }

        int mint=f[e],minid=-1;
        for(int i=0;i<2*k;i++)
        {
            int x=check(Ticket[i]);
            if(x<mint){mint=x;minid=i;}
        }

        if(minid<0)
        {
            for(int u=s;u!=-1;u=pg[u])
            {
                if(u!=s)printf(" ");
                printf("%d",u);
            }
            printf("\n");
            printf("Ticket Not Used\n%d\n",mint);
        }else
        {
            stack<int> s;
            Edge &e=Ticket[minid];
            for(int u=e.u;u!=-1;u=pf[u])
                s.push(u);
            while(!s.empty())
            {
                int u=s.top();s.pop();
                printf("%d",u);
                if(u!=e.u)printf(" ");
            }
            for(int u=e.v;u!=-1;u=pg[u])
                printf(" %d",u);
            printf("\n");
            printf("%d\n%d\n",e.u,mint);
        }
    }
    return 0;
}

