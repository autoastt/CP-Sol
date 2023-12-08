/*
Range Xor Queries
Fenwick Tree Practice
2 Sep 2023
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;
ll f[N];

void build(int n){
    for(int i = 1; i <= n; i++){
        int j = i + (i & -i);
        if(j <= n) f[j] ^= f[i];
    }
}

void update(int i, ll x, int n){
    for(; i <= n; i += i & -i) f[i] ^= x;
}

ll query(int i){
    ll ret = 0;
    for(; i > 0; i -= i & -i) ret ^= f[i];
    return ret;
}


int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> f[i];
    }
    build(n);
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << (query(b) ^ query(a-1)) << "\n";
    }
}