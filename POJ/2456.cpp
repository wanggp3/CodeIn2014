#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
const int N=100005;
using namespace std;
int n,m;
int x[N];
bool ok(int d){
    int last=0;
    for(int i=1;i<m;i++){
        int cur=last+1;
        while(cur<n&&x[cur]-x[last]<d)cur++;
        if(cur>=n)return false;
        last=cur;
    }
    return true;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    sort(x,x+n);
    int l=0,r=x[n-1]+1;
    while(r-l>1){
        int mid=(r+l)/2;
        if(ok(mid))l=mid;
        else r=mid;
    }
    cout<<l<<endl;
    return 0;
}
