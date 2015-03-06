#include<iostream>
#include <complex>
#include<cstring>
#include<set>
#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<algorithm>
#include<stdio.h>
#include<iomanip>

#define rep(i,n) for(int i=0;i<(n);++i)
#define PB push_back
#define MP make_pair

const int L = 100000 * 2;

using namespace std;

typedef long long LL;
typedef pair<int,int>PII;

typedef complex<double> Comp;
typedef Comp cp;

const double PI = acos(-1);
const Comp I(0, 1);

const int N = 1<<18;
Comp tmp[N];
Comp a[N] = { }, b[N] = { };
int n,m,d;
LL ans;
LL c[N];
int v[N];

void fft(Comp *a,int n,int f=1){
    double arg = PI;
    for(int k = n >> 1; k; k >>= 1, arg *= 0.5) {
        cp wm(cos(arg), f * sin(arg)), w(1, 0);
        for (int i = 0; i < n; i += k, w *= wm) {
            int p = i << 1;
            if (p >= n) p -= n;
            for (int j = 0; j < k; ++j) tmp[i + j] = a[p + j] + w * a[p + k + j];
        }
        rep(i,n) a[i] = tmp[i];
    }
}

int calc(int n){
    fft(a,n,1);
    fft(b,n,1);
    rep(i,n) a[i] = a[i]*b[i];
    fft(a,n,-1);
    rep(i,n) a[i] /= n;
}

char s[L], t[L];
int k;

int val[L];

int main(){
    while(~scanf("%s%s%d", s, t, &k)){
        memset(val, 0, sizeof val);
        n = strlen(s);
        m = strlen(t);
        int ma = max(n, m);
        if (n < m){
            for(int i = 0; i < ma; i++) swap(s[i], t[i]);
            swap(n, m);
        }
        int top = 1;
        while(top < ma * 2) top *= 2;
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < top; j++) a[j] = b[j] = Comp(0, 0);
            for(int j = 0; j < n; j++){
                if (s[j] != 'a' + i) a[n - 1 - j] = Comp(1, 0);
            }
            for(int j = 0; j < m; j++){
                if (t[j] == 'a' + i) b[j] = Comp(1, 0);
            }
            calc(top);
            for(int j = 0; j < n - m + 1; j++) val[j] += (int)(a[j + m - 1].real() + 0.4);
        }
        int ans = 0;
        for(int i = 0; i < n - m + 1; i++){
            if (val[i] <= k) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
