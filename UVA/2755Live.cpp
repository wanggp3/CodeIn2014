#include<iostream>
#include<stdio.h>
#include<cstring>
#define rep(i,n) for(int i=0;i<n;i++)
#define sf scanf
#define pf printf
using namespace std;
    int MinimumRepresentation(char *s, int l)  
    {  
        int i = 0, j = 1, k = 0, t;  
        while(i < l && j < l && k < l) {  
            t = s[(i + k) >= l ? i + k - l : i + k] - s[(j + k) >= l ? j + k - l : j + k];  
            if(!t) k++;  
            else{  
                if(t > 0) i = i + k + 1;  
                else j = j + k + 1;  
                if(i == j) ++ j;  
                k = 0;  
            }  
        }  
        return (i < j ? i : j);  
    }  
int myf_Minrepresentation(char *s,int n){
    rep(i,n)s[n+i]=s[i];
    int i=0,j=1;
    while(i<n&&j<n){
        int k=0;
        while(k<=n && s[i+k] == s[j+k])++k;
        if(k>n)break;
        if(s[i+k] < s[j+k]) j+=k+1;
        else i+=k+1;
        if(i==j)++j;
    }
    return i<j?i:j;
}
char s[200001];
int n;
void solve(){
   sf("%d",&n);
   sf("%s",s);
  // pf("%d\n",MinimumRepresentation(s,n));
   pf("%d\n",myf_Minrepresentation(s,n));
}
int main(){
    int T;sf("%d",&T);
    while(T--){
        solve();
    }
    return 0;
}
