#include<iostream>
#include<cstring>
#include<vector>
const int N=1005;
const int ML=10005,MD=10005;
using namespace std;
int d[N];
int AL[ML],BL[ML],DL[ML];
int AD[MD],BD[MD],DD[MD];
const int INF=0x3f3f3f3f;

int main(){
    int n,ml,md;
    cin>>n>>ml>>md;
    for(int i=0;i<ml;++i){
        cin>>AL[i]>>BL[i]>>DL[i];
    }
    for(int i =0 ; i<md;++i){
        cin>>AD[i]>>BD[i]>>DD[i];
    }
    fill(d,d+N,INF);
    d[0]=0;
    for(int k=0;k<n;k++){
        for(int i=0;i+1<n;++i){
            if(d[i+1]<INF){
                d[i]=min(d[i],d[i+1]);
            }
        }
        //AL-->BL=DL
        for(int i=0;i<ml;++i){
            if(d[AL[i]-1]<INF){
                d[BL[i]-1]=min(d[BL[i]-1],d[AL[i]-1]+DL[i]);
            }
        }
        //BD-->AD = MD
        for(int i=0;i<ml;++i){
            if(d[BD[i]-1]<INF){
                d[AD[i]-1]=min(d[AD[i]-1],d[BD[i]-1]-DD[i]);
            }
        }
    }

    int res=d[n-1];
    if(d[0] < 0){
        res=-1;
    }else if(res== INF){
        res=-2;
    }
    cout<<res<<endl;
}





