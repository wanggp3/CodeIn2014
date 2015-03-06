#include<iostream>
#include<cstring>
#include<stdio.h>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<iomanip>
#include<cmath>
#include<list>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)
#define fab(i,a,b) for(int i=(a);i<=(b);i++)
#define fba(i,b,a) for(int i=(b);i>=(a);i--)
#define cls0(x) memset(x,0,sizeof(x))
#define cls1(x) memset(x,-1,sizeof(x))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define LL long long 
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define sf scanf
#define pf printf 
const int N=135;
using namespace std;
char str[N];
int dp[N][N],f[N][N];
void print(int i,int j){
    if(i>j)return;
    if(f[i][j]==-1){
        if(i==j){
            if(str[i]=='('||str[i]==')')printf("()");
            else if(str[i]=='['||str[i]==']')printf("[]");
        }else{
            putchar(str[i]);
            print(i+1,j-1);
            putchar(str[j]);
        }
    }else{
        int mid=f[i][j];
        print(i,mid);
        print(mid+1,j);
    }
}
int main(){
    sf("%s",str);
    int len=strlen(str);
    memset(dp,0,sizeof dp);
    memset(f,-1,sizeof f);
    for(int k=0;k<len;k++) {
        for(int i=0;i+k<len;i++){
            int j=i+k;
            if(i==j){
                dp[i][j]=1;
            }else{
                int tmp=INF;
                if(str[i]=='('&&str[j]==')'){
                    tmp=min(tmp,dp[i+1][j-1]);
                }else if(str[i]=='['&&str[j]==']'){
                    tmp=min(tmp,dp[i+1][j-1]);
                }
                for(int g=i;g<j;g++){
                    if(tmp>dp[i][g]+dp[g+1][j]){
                        tmp=dp[i][g]+dp[g+1][j];
                        f[i][j]=g;
                    }
                }
                dp[i][j]=tmp;
            }
        }
    }
    print(0,len-1);
    puts("");
    return 0;
}

