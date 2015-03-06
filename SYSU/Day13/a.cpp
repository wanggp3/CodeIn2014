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
#define rson m+1,r,rt<<1
#define LL long long 
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define sf scanf
#define pf printf 
const int N=15;
using namespace std;
int n;
void printtab(int num){
    rep(i,num)putchar("\t");
}
void solve(int tab,int pos,string s){
    printtab(tab);
    if(pos==n){
        printf("printf(\"");
        rep(i,n-1){
            printf("%c<",s[i]);
        }
        puts("%c\\n\");",s[n-1]);
        return;
    }
    string st;
    for(int i=pos-1;i>=0;i--){
        printf("if (%c<%c)\n",s[i],'a'+pos);
        st="";
        rep(j,i+1)st+=s[j];
        st+='a'+pos;
        fab(j,i+1,pos-1)st+=s[j];
        solve(tab+pos-i,pos+1,st);
    }
}
int main(){
    while(sf("%d",&n)&&n){
        puts("#include<stdio.h>\n");
        puts("int ");
        rep(i,n){
          if(i)puts(",");
          putchar('a'+i);
        }
        puts(";\nbool ok;\nint main()\n{");
        printf("\tprintf(\"Please enter %d different integers:\\n\");\n",n);
        puts("\tdo\n\t{");
        printf("\t\tscanf(\"");
        rep(i,n){
            printf("%%d");
        }
        printf("\"");
        rep(i,n){
            printf(",&%c",'a'+i);
        }
        puts(");");
        printf("\t\tok=1;\n\t\tif(");
        rep(i,n-1){
            fab(j,i+1,n-1){
                printf("%c==%c",'a'+i,'a'+j);
                if(!(i==n-2&&j==n-1))printf(" || ");
            }
        }
        puts(")\n\t\t\tok=0;\n\t}while(ok);");
        solve(1,1,"a");
        puts("\treturn 0;\n}\n");
    }
    return 0;
}

