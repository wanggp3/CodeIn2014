#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define N 102020
#define pb push_back
#define pil pair<int,long long>
#define mp make_pair
typedef vector<int>::iterator IT;
typedef vector<pil>::iterator PIT;

struct Edge
{
    int v,next;
    long long val;
}e[N*2];

struct Input
{
    int a,b;
    long long c;
    bool operator < (const Input &it) const
    {
        return a==it.a?(b<it.b):(a<it.a);
    }
}input[N];

vector<pil> entry[N];
int last[N],len,deg[N],col[N];
long long ans[3],tot[N][2];

void addedge(int u,int v,long long val)
{
    e[++len].v=v;
    e[len].val=val;
    e[len].next=last[u];
    last[u]=len;
}

void read(int &x)
{
    char ch;
    do ch=getchar(); while (ch>'9'||ch<'0');
    for (x=0;'0'<=ch&&ch<='9';ch=getchar()) x=x*10+ch-'0';
}
void read2(long long &x)
{
    char ch;
    do ch=getchar(); while (ch>'9'||ch<'0');
    for (x=0;'0'<=ch&&ch<='9';ch=getchar()) x=x*10+ch-'0';
}

int main()
{
    freopen("in","r",stdin);
    freopen("herac","w",stdout);
    int n,m,a,b,q,cas=0,ave;
    char buffer[111];
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        ave=sqrt(1.*m);
        for (int i=1;i<=n;i++) read(col[i]),deg[i]=0;
        fill(entry+1,entry+n+1,vector<pil>());
        memset(last,0,sizeof(last[0])*(n+1));
        len=0;
        ans[0]=ans[1]=ans[2]=0;
        for (int i=1;i<=m;i++)
        {
            read(input[i].a);read(input[i].b);read2(input[i].c);
        }
        sort(input+1,input+m+1);
        int now=1;
        for (int i=2;i<=m;i++)
        {
            for (;i<=m&&input[now].a==input[i].a&&input[now].b==input[i].b;i++) input[now].c+=input[i].c;
            if (i<=m) input[++now]=input[i];
        }
        m=now;
        for (int i=1;i<=m;i++)
        {
            ans[col[input[i].a]+col[input[i].b]]+=input[i].c;
            deg[input[i].a]++;deg[input[i].b]++;
            addedge(input[i].a,input[i].b,input[i].c);
            addedge(input[i].b,input[i].a,input[i].c);
        }
        for (int i=1;i<=n;i++)
        {
            tot[i][0]=tot[i][1]=0;
            for (int j=last[i];j;j=e[j].next)
            {
                int v=e[j].v;
                if (deg[i]>ave) tot[i][col[v]]+=e[j].val;
                if (deg[v]>ave) entry[i].pb(mp(v,e[j].val));
            }
        }
        printf("Case %d:\n",++cas);
        scanf("%d",&q);
        while (q--)
        {
            scanf("%s",buffer);
            if (buffer[0]=='A')
            {
                read(a);read(b);
                printf("%lld\n",ans[a+b]);
            }
            else
            {
                read(a);
                if (deg[a]<=ave)
                    for (int i=last[a];i;i=e[i].next)
                    {
                        int v=e[i].v;
                        ans[col[a]+col[v]]-=e[i].val;
                        ans[(col[a]^1)+col[v]]+=e[i].val;
                    }
                else
                {
                    ans[col[a]]-=tot[a][0];
                    ans[col[a]+1]-=tot[a][1];
                    ans[col[a]^1]+=tot[a][0];
                    ans[(col[a]^1)+1]+=tot[a][1];
                }
                for (PIT i=entry[a].begin();i!=entry[a].end();i++)
                {
                    tot[i->first][col[a]]-=i->second;
                    tot[i->first][col[a]^1]+=i->second;
                }
                col[a]^=1;
            }
        }
    }
    return 0;
}

