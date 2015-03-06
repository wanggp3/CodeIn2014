#include<iostream>
#include<cstring>
#include<vector>
#include<map>
const int N=10000;
using namespace std;

bool is_prime(int n){
    for(int i=2;i*i<n;i++){
        if(n%i==0)return false;
    }
    return n!=1;
}
vector<int> divisor(int n){
    vector<int>res;
    for(int i=1;i*i<=n;i++){
        if(n%i==0)res.push_back ( i );
        if(i!=n/i)res.push_back ( n/i );

    }
    return res;
}
map<int,int> prime_factor(int n){
    map<int,int> res;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            ++res[i];
            n/=i;
        }
    }
    if(n!=1)res[n]=1;
    return res;
}
int sieve(int n){
    int count=0;
    bool isprime[N];
    int prime[N];
    for(int i=0;i<N;i++)isprime[i]=true;
    memset(prime,0,sizeof(prime));
    isprime[0]=isprime[1]=false;
    for(int i=2;i<=n;i++){
        if(isprime[i]){
            prime[count++]=i;
            for(int j=2*i;j<=n;j+=i)isprime[j]=0;
        }
    }
    return count;
}
int main(){
    cout<<"hello word"<<endl;
    return 0;
}
