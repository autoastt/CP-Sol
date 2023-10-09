/*
Range Update Queries
Fenwick Tree Practice
2 Sep 2023
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
#define ll long long
ll f[N], arr[N];

void update(int i, ll x, int n){
    for(; i <= n; i += i & -i) f[i] += x;
}

ll query(int i){
    ll ret = 0;
    for(; i > 0; i -= i & -i) ret += f[i];
    return ret;
}

int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    while(q--){
        int k;
        cin >> k;
        if(k == 1){
            ll a, b, u;
            cin >> a >> b >> u;
            update(a, u, n);
            update(b+1, -u, n);
        }
        else{
            int x;
            cin >> x;
            cout << arr[x] + query(x) << "\n";
        }
    }
}