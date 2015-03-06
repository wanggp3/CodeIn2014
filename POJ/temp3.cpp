#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int a[5]={1,2,3,4,6};
    cout<<lower_bound(a,a+5,4)-a<<endl;
    return 0;

}
