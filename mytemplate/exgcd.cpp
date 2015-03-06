#include<iostream>
using namespace std;

int exgcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int res=exgcd(b,a%b,x,y);
    int temp=x;
    x=y;
    y=temp - a/b*y;
    return res;
}
int linear_equation(int a,int b,int c,int &x,int &y){
    int d=exgcd(a,b,x,y);
    if(c%d)return false;
    int k=c/d;
    x*=k;y*=k;
    return true;
}
int main(){
    cout<<"Hello word!~"<<endl;
    return 0;
}
