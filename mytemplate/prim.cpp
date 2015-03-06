#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
const int INF=100000;
const int N=1000;
using namespace std;
int cost[N][N];
bool used[N];
int mincost[N];
int V;
int prim_V2(){
    for(int i=0;i<V;++i){
        mincost[i]=INF;
        used[i]=false;
    }
    mincost[0]=0;
    int res=0;
    while(true){
        int v=-1;
        for(int i=0;i<V;++i){
            if(!used[i]&&(v==-1||mincost[i]<mincost[v]))v=i;
        }
        if(v==-1)break;
        used[v]=true;
        res+=mincost[v];
        for(int i=0;i<V;++i){
            mincost[i]=min(mincost[i],cost[v][i]);
        }

    }
    return res;
}
int prim_EV(){
    for(int i=0;i<V;++i){
        used[i]=false;
        mincost[i]=INF;
    }
    mincost[0]=0;
    typedef pair<int,int> P;
    priority_queue<P,vector<P>,greater<P> > Q;
    Q.push(P(mincost[0],0));
    int res=0;
    while(!Q.empty()){
        P p=Q.top();Q.pop();
        int v=p.second;
        if(used[v])continue;
        res+=mincost[v];
        used[v]=true;
        for(int i=0;i<V;++i){
            if(!used[i]&&mincost[i]<cost[v][i]){
                mincost[i]=cost[v][i];
                Q.push(P(mincost[i],i));
            }
        }
    }
    return res;
}
int main(){
    cout<<"Hello world!~"<<endl;
    return 0;
}
