#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define zero(x) (fabs(x)<eps)
#define pi acos(-1.0)
#define f1 first
#define f2 second
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define initial 1,n,1

using namespace std;
typedef long long LL;
typedef pair <int, int> PII;
template<typename X> inline bool minimize(X&p,X q){if(p<=q)return 0;p=q;return 1;}
template<typename X> inline bool maximize(X&p,X q){if(p>=q)return 0;p=q;return 1;}
const int N=105,M=2005;
const LL INF=(1LL)<<50;
struct heapnode{
    int u;
    LL d;
    heapnode(LL a,int b):d(a),u(b){}
    bool operator<(const heapnode &oth)const
        {return d>oth.d;}
};
struct edge{
    int u,v;
    LL w;
    edge(int x,int y,LL z):u(x),v(y),w(z){}
};
int n,m,ttt;
LL L;
LL ans[N];
struct Dijkstra{
    int n,m;
    vector<edge> ed;
    vector<int > g[N];
    priority_queue<heapnode> q;
    bool done[N];
    LL d[N];
    int p[N];
    vector<int> mark[M];
    void init(int nn)
    {
        n=nn;
        for (int i=0;i<n;i++) g[i].clear();
        for (int i=0;i<M;i++) mark[i].clear();
        ed.clear();
        ;
    }
    void add(int x,int y,LL z)
    {
        ed.pb(edge(x,y,z));
        m=ed.size();
        g[x].pb(m-1);
    }
    LL dijkstra(int s,int tag)
    {
        while (!q.empty()) q.pop();
        for (int i=0;i<n;i++) d[i]=INF; d[s]=0;
        q.push(heapnode(0,s));
        memset(done,0,sizeof(done));
        if (tag==ttt)memset(p,255,sizeof(p));
        while (!q.empty())
            {
                heapnode x=q.top(); q.pop();
                int u=x.u;
                if (done[u]) continue;
                done[u]=true;
                for (int i=0;i<g[u].size();i++)if ((g[u][i]!=tag)&&(g[u][i]!=(tag^1)))
                    {
                        edge& e=ed[g[u][i]];
                        if (d[e.v]>d[u]+e.w)
                            {
                                d[e.v]=d[u]+e.w;
                                if (tag==ttt)p[e.v]=g[u][i];
                                q.push(heapnode(d[e.v],e.v));
                            }
                    }
            }

        if (tag==ttt)for (int j=0;j<n;j++)  if (j!=s&&p[j]!=-1)mark[p[j]].pb(s);

        LL tmp=0;
        for (int j=0;j<n;j++)tmp+=((d[j]==INF)?L:d[j]);
        return tmp;
    }
    LL solve()
    {   LL tmp,anss=0;
        int sz=ed.size();
        for(int i=0;i<sz;i++)
        {
            if (i%2==0)tmp=0;
            for(int j=0;j<mark[i].size();j++){
                tmp -= ans[mark[i][j]];
                tmp += dijkstra(mark[i][j],i);
            }
            if (i%2==1)anss = max(anss,tmp);
        }
        return anss;
    }
}it;
void doit()
{   it.init(n);
    LL z;
    for (int i=1,x,y;i<=m;i++)
        {
            scanf("%d%d%lld",&x,&y,&z);
            if (x==y) continue;
            x--; y--;
            it.add(x,y,z);
            it.add(y,x,z);
        }
    ttt=m*2+10;
    LL ans1=0,ans2;
    for (int i=0;i<n;i++)
        {
            ans[i]=it.dijkstra(i,ttt);
            ans1+=ans[i];
        }
    ans2=it.solve();
    printf("%lld %lld\n",ans1,ans2+ans1);

}
int main()
{
    while (scanf("%d%d%lld",&n,&m,&L)!=EOF) doit();
}

