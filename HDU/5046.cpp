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
const int maxn=65;
const int maxm=65;
const int maxnode=4001;
using namespace std;
typedef pair<int,int>PII;
int K;
struct DLX_mult{
    int n,m,size;
    int U[maxnode],D[maxnode],R[maxnode],L[maxnode],row[maxnode],col[maxnode]; 
    int H[maxn],S[maxm];
    int ansd,ans[maxn];
    void init(int n,int m){
        this->n=n;this->m=m;
        ansd=INF;
        fab(i,0,m){
            S[i]=0;
            U[i]=D[i]=i;
            L[i]=i-1;
            R[i]=i+1;
        }
        R[m]=0;L[0]=m;
        size=m;
        fab(i,1,n)H[i]=-1;
    }
    void link(int r,int c){
        ++S[col[++size]=c];
        row[size]=r;
        D[size]=D[c];
        U[D[c]]=size;
        U[size]=c;
        D[c]=size;
        if(H[r]<0)H[r]=L[size]=R[size]=size;
        else{
            R[size]=R[H[r]];
            L[R[H[r]]]=size;
            L[size]=H[r];
            R[H[r]]=size;
        }
    }
    void remove(int c){
        for(int i=D[c];i!=c;i=D[i]){
            L[R[i]]=L[i];
            R[L[i]]=R[i];
        }
    }
    void resume(int c){
        for(int i=U[c];i!=c;i=U[i])L[R[i]]=R[L[i]]=i;
    }
    bool v[maxnode];
    int f(){
        int ret=0;
        for(int c=R[0];c!=0;c=R[c])v[c]=true;
        for(int c=R[0];c!=0;c=R[c]){
            if(v[c]){
                ret++;
                v[c]=false;
                for(int i=D[c];i!=c;i=D[i]){
                   for(int j=R[i];j!=i;j=R[j]){
                       v[col[j]]=false;
                   }
                }
            }
        }
        return ret;
    }
    //求一组满足解
    bool dance(int d){
        if(d+f()>K)return false;
        if(R[0]==0)return d<=K;
        int c=R[0];
        for(int i=R[0];i!=0;i=R[i])if(S[i]<S[c])c=i;
        for(int i=D[c];i!=c;i=D[i]){
            remove(i);
            for(int j=R[i];j!=i;j=R[j])remove(j);
            ans[d]=row[i];
            if(dance(d+1))return true;
            for(int j=L[i];j!=i;j=L[j])resume(j);
            resume(i);
        }
        return false;
    }
    //求最优解
    /*
    void dance(int d){
        if(d+f()>=ansd)return ;
        if(R[0]==0){
            if(ansd>d)ansd=d;
            return;
        }
        int c=R[0];
        for(int i=R[0];i!=0;i=R[i])if(S[i]<S[c])c=i;
        for(int i=D[c];i!=c;i=D[i]){
            remove(i);
            for(int j=R[i];j!=i;j=R[j])remove(j);
            dance(d+1);
            for(int j=L[i];j!=i;j=L[j])resume(j);
            resume(i);
        }
    }*/
}g;
int T,n;
struct City{
    LL x,y;
    City(LL x=0,LL y=0):x(x),y(y){}
    void read(){
        sf("%lld%lld",&x,&y);
    }
}c[maxn];
LL dis(City a,City b){
    LL dx=a.x-b.x;if(dx<0)dx=-dx;
    LL dy=a.y-b.y;if(dy<0)dy=-dy;
    return dx+dy;
}
int main(){
    sf("%d",&T);
    rep(cas,T){
        sf("%d%d",&n,&K);
        fab(i,1,n)c[i].read();
        LL L=0,R=100000000000LL;
        while(L<R){
            LL mid=(L+R)/2;
            g.init(n,n);
            fab(i,1,n){
                fab(j,1,n){
                    if(dis(c[i],c[j])<=mid)g.link(i,j);
                }
            }
            if(g.dance(0))R=mid;
            else L=mid+1;
        }
        pf("Case #%d: %lld\n",cas+1,L);
    }
    return 0;
}


