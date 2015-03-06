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
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define sf scanf
#define pf printf 
const int N=1005;
using namespace std;
const double PI = acos(-1.0);
struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
};
typedef Point Vector;
Vector Rotate(Vector A,double rad){
    return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));
}
Vector operator-(Vector A,Vector B){
    return Vector(A.x-B.x,A.y-B.y);
}
Vector operator+(Vector A,Vector B){
    return Vector(A.x+B.x,A.y+B.y);
}
int n;
double x[5],y[5],a[5],b[5];
Vector V[5],R[5];
double Dot(Vector A,Vector B){
    return A.x*B.x+A.y*B.y;
}
double Len(Vector A){
    return Dot(A,A);
}
double len[5];
set<double>S;
const double eps = 1e-6;
bool ok(){

   S.clear();
   fab(i,1,4)R[i]=R[i]+Vector(a[i],b[i]);
   S.insert(Len(R[1]-R[2]));
   S.insert(Len(R[1]-R[3]));
   S.insert(Len(R[1]-R[4]));
   S.insert(Len(R[2]-R[3]));
   S.insert(Len(R[4]-R[3]));
   S.insert(Len(R[2]-R[4]));
   vector<double>tmp;
   //pf("size %d\n",(int)S.size());
   set<double>::iterator it=S.begin();
   while(it!=S.end()){
      // pf("%lf\n",*it);
       tmp.PB(*it);
       it++;
   }
   sort(tmp.begin(),tmp.end());
   double len1=tmp[0];
   double len2=tmp[tmp.size()-1];
   rep(i,tmp.size()){
       if(fabs(tmp[i]-len1)>eps&&fabs(tmp[i]-len2)>eps)return 0;
   }
   int cnt=1;
   for(int i=1;i<tmp.size();i++){
       if(tmp[i]-tmp[i-1]<=eps)continue;
       cnt++;
   }
   if(cnt<=1)return 0;
   /*if(len1>eps){
       rep(i,tmp.size())pf("%lf ",tmp[i]);pf("\n");
   }*/
   if(fabs(len2-len1*2)<=eps)return 1;
   else return 0;
   /*if(S.size()!=2)return 0;
   else{
       double len1=*S.begin();
       double len2=*S.rbegin();
       pf("lf %lf\n",len1,len2);
       if(len1<len2)swap(len1,len2);
       if(fabs(len1-2*len2)<1e-8)return 1;
       else return 0;
   } */
}
void solve(){
    S.clear();
    int ans=INF;
    fab(i,1,4)sf("%lf%lf%lf%lf",&x[i],&y[i],&a[i],&b[i]);
    fab(k,1,4){
       V[k]=Vector(x[k]-a[k],y[k]-b[k]);
      // pf("V %lf %lf\n",V[k].x,V[k].y);
    }

    fab(i,0,3){
        fab(j,0,3){
           fab(ii,0,3){
               fab(jj,0,3){
                 R[1]=Rotate(V[1],i*PI/2.0);
                 R[2]=Rotate(V[2],j*PI/2.0);
                 R[3]=Rotate(V[3],ii*PI/2.0);
                 R[4]=Rotate(V[4],jj*PI/2.0);
                 /*if(i==1){
                     fab(k,1,4){
                         pf("%lf %lf\n",R[k].x,R[k].y);
                     }
                     int x;cin>>x;
                 }*/
                 if(ok()){
                     if(i+j+jj+ii<ans){
                         ans=i+j+ii+jj;
                         /*pf("update %d\n",ans);
                         fab(k,1,4){
                             pf("%lf %lf\n",R[k].x,R[k].y);
                         }*/
                     }
                 }
               }
           }
        }
    }
    if(ans==INF)puts("-1");
    else pf("%d\n",ans);
}
int main(){
    //pf("%lf\n",PI);
    sf("%d",&n);
    rep(i,n){
        solve();
    }
    return 0;
}

