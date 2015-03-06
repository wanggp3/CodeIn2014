#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iomanip>
const int N=22;
using namespace std;
int w,h;
int map[N][N];
int go[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int dfs(int x,int y,int step){
    //if(map[x][y]==3)return 0;
    cout<<"the position is : "<<x<<' '<<y<<' '<<step<<endl;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++)cout<<map[i][j]<<' ';
        cout<<endl;
    }
    if(step>10)return step;
    int res=11;
    for(int i=0;i<4;i++){
        for(int k=1;k<21;k++){
            int nx=x+go[i][0]*k ;
            int ny=y+go[i][1]*k;
            if(nx>=1&&nx<=h&&ny>=1&&ny<=w){
                if(map[nx][ny]==3)return step+1;
                else if(map[nx][ny]==1){
                    if(k==1)break;
                    map[nx][ny]=0;
                    //res=min(res,dfs(nx-go[i][0],ny-go[i][1],step+1));
                    int nnx=nx+go[i][0]*(k-1),nny=ny+go[i][1]*(k-1);
                    int tp=dfs(nnx,nny,step+1);
                    
                    if(res>tp)res=tp;
                    map[nx][ny]=1;
                }
            }else break;
        }
    }
    return res;
}
int main(){
    while(cin>>w>>h){
        if(w==0&&h==0)break;
        int x,y;
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                cin>>map[i][j];
                if(map[i][j]==2){
                    x=i,y=j;
                    map[i][j]=0;
                }
            }
        }
        int res=dfs(x,y,0);
        if(res>10)res=-1;
        cout<<res<<endl;
    }

    return 0;
}
