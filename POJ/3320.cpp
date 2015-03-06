#include<iostream>
#include<cstring>
#include<set>
#include<stdio.h>
#include<map>
const int N=1000090;
using namespace std;
map<int,int>count;
set<int>set1;
int a[N];
int P,s,t,num,res;
int main(){
    cin>>P;
    for(int i=0;i<P;i++){
        //cin>>a[i];
        scanf("%d",&a[i]);
        set1.insert(a[i]);
    }
    s=0,t=0,num=0,res=P;
    int n=set1.size();
    for(;;){
        while(t<P&&num<n){
            if(count[a[t++]]++==0)num++;
        }
        if(num<n)break;
        res=min(res,t-s);
        if(--count[a[s++]]==0)num--;
    }
    cout<<res<<endl;
    return 0;

}
