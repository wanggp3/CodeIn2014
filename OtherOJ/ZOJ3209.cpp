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
const int maxn= 510;// row size
const int maxm= 910;//column size
const int maxnode=450010;//一般取maxn*maxm+maxm
using namespace std;
typedef pair<int,int>PII;
struct DLX_exact{
    int n,m,size;
    int U[maxnode],D[maxnode],R[maxnode],L[maxnode],row[maxnode],col[maxnode];
    int H[maxn];//行头节点
    int S[maxm];//每列有多少节点
    int ansd,ans[maxn];//答案数组 选了ansd行，放在ans[0~ansd-1]
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
        size=m;//column's head rang in [1,m]
        fab(i,1,n)H[i]=-1;//row head initial to -1
    }
    //add (r,c)
    void link(int r,int c){// index rang in [1,n/m]
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
    //
    void remove(int c){
        L[R[c]]=L[c];
        R[L[c]]=R[c];
        for(int i=D[c];i!=c;i=D[i]){
            for(int j=R[i];j!=i;j=R[j]){
                U[D[j]]=U[j];
                D[U[j]]=D[j];
                --S[col[j]];
            }
        }
    }
    void resume(int c){
        for(int i=U[c];i!=c;i=U[i]){
            for(int j=L[i];j!=i;j=L[j]){
                ++S[col[U[D[j]]=D[U[j]]=j]];
            }
        }
        L[R[c]]=R[L[c]]=c;
    }
    //求最小精确覆盖(一组最小解）
    void dance(int d){
        if(ansd<=d)return;
        if(R[0]==0){
            if(d<ansd)ansd=d;
            return;
        }
        int c=R[0];
        for(int i=R[0];i!=0;i=R[i])if(S[i]<S[c])c=i;
        remove(c);
        for(int i=D[c];i!=c;i=D[i]){
            ans[d]=row[i];
            for(int j=R[i];j!=i;j=R[j])remove(col[j]);
            dance(d+1);
            for(int j=L[i];j!=i;j=L[j])resume(col[j]);
        }
        resume(c);
    }
    
    //求一组解
   /* 
    bool dance(int d){
        if(R[0]==0){
            ansd=d;
            return true;
        }
        int c=R[0];
        for(int i=R[0];i!=0;i=R[i])if(S[i]<S[c])c=i;
        remove(c);
        for(int i=D[c];i!=c;i=D[i]){
            ans[d]=row[i];
            for(int j=R[i];j!=i;j=R[j])remove(col[j]);
            if(dance(d+1))return true;
            for(int j=L[i];j!=i;j=L[j])resume(col[j]);
        }
        resume(c);
        return false;
    }*/
}solver;
int n,m,p;
int main(){
    int T;
    sf("%d",&T);
    while(T--){
        sf("%d%d%d",&n,&m,&p);
        solver.init(p,n*m);
        int x[2];
        int y[2];
        fab(t,1,p){
            sf("%d%d%d%d",&x[0],&y[0],&x[1],&y[1]);
            for(int i=x[0];i<x[1];i++){
                for(int j=y[0];j<y[1];j++){
                    solver.link(t,i*m+j+1);
                }
            }
        }
        solver.dance(0);
        if(solver.ansd==INF)puts("-1");
        else pf("%d\n",solver.ansd);
    }
    return 0;
}



