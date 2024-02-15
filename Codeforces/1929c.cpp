#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll k, x, a, loss = 0, y;
    cin >> k >> x >> a;
    for(int i = 0; i <= x; i++){
        y = loss / (k-1) + 1;
        loss += y;
        if(loss > a) return void(cout << "NO\n");
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
