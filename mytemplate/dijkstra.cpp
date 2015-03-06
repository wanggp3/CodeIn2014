#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
const int N=1000;
const int INF=1000000;
using namespace std;

struct edge{ int to,cost;};
typedef pair<int,int>P;
int V;
vector<edge>G[N];
int d[N];

void dijkstra(int s){
    priority_queue< P,vector<P>,greater<P> > Q;
    fill(d,d+V,INF);
    d[s]=0;
    Q.push(P(0,s));
    while(!Q.empty()){
        P p=Q.top();Q.pop();
        int v=p.second;
        if(d[v]<p.first)continue;
        for(int i=0;i<G[v].size();i++){
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                Q.push(P(d[e.to],e.to));
            }
        }
    }
}
int main(){
    cout<<"Hello world!~"<<endl;
    return 0;

}
