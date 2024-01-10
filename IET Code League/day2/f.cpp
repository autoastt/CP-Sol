#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;

void solve() {
    ll n;
    cin >> n;
    if(n >= 40){
        cout << "000000000";
    }
    else{
        ll x = 1, m = 1e9;
        for(int i = 2; i <= n; i++){
            x *= i;
            x %= m;
        }
        // cout << x << "\n";
        string s = to_string(x);
        // if(s.size() < 9){
            for(int i = 1; i <= 9-s.size(); i++) cout << "0";
            for(auto i : s) cout << i;
        // }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}