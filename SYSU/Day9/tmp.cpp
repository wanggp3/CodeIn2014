#nclude <iostream>
#include <algorithm>

using namespace std;

const int N = 1111;
f\\
struct Node{
    string s;
};

int n;
Node v[N];

bool cmp(Node a, Node b){
    return a.s.length() <= b.s.length();
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> v[i].s;
    }
    sort(v, v + n, cmp);
    for(int i = 0; i < n; i++){
        cout << v[i].s << endl;
    }
    return 0;
}
