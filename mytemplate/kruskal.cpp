#include<iostream>
#include<cstring>
#include<algorithm>
const int N=1000;
using namespace std;
struct edge{int u,v,cost;};
bool cmp(const edge & lhs,const edge & rhs){return lhs.cost < rhs.cost; }
const int V=1000,E=1000;
edge es[E];
int father[V];
int find(int c){
    return father[c]==c ? c : father[c]=find(father[c]);
}
int kruskal(){
    for(int i=0;i<V;++i)father[i]=i;
    sort(es,es+E,cmp);
    int res=0;
    for(int i=0;i<E;++i){
        int v=find(es[i].v);
        int u=find(es[i].u);
        if(u!=v){
            father[v]=u;
            res+=es[i].cost;
        }
    }
    return res;
}
int main(){
    cout<<"Hello world!~"<<endl;
    return 0;
}
