#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
const int N=100005;
using namespace std;
int a[N],sum[N];
int n,s;
int main(){
    int tests;
    cin>>tests;
    while(tests--){
        memset(sum,0,sizeof(sum));
        cin>>n>>s;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum[i+1]=sum[i]+a[i];
        }
        if(sum[n]<s){
            cout<<0<<endl;
            continue;
        }
        int res=n;
        for(int i=0;sum[n]-sum[i]>=s;i++){
            int t=lower_bound(sum+i,sum+n,sum[i]+s)-sum;
            res=min(res,t-i);
        }
        cout<<res<<endl;
    }
}
