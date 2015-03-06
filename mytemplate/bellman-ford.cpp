#include<iostream>
#include<cstring>
const int N=1000;
using namespace std;

struct edge{ int from,to,cost;};
edge es[N];
int d[N];
int V,E;
bool bellman_ford(int s){
    for(int i=0;i<V;i++)d[i]=10000;
    d[s]=0;
    for(int i=0;i<=V;i++){
        bool isupdate=false;
      for(int j=0;j<E;j++){
          edge e=es[j];
          if(d[e.from]!=10000&&d[e.to]>d[e.from]+e.cost){
              d[e.to]=d[e.from]+e.cost;
              if(i==V)return false;
          }
      }
      if(!isupdate)break;
    }
    return true;
}
int main(void){
    cout<<"Hello world!~"<<endl;
    return 0;
}
