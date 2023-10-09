#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n, mna = 1e9, mnb = 1e9, sa = 0, sb = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        ll x; cin >> x; sa += x; mna = min(mna, x);
    }
    for(int i = 0; i < n; i++){
        ll x; cin >> x; sb += x; mnb = min(mnb, x);
    }
    cout << min(sa + n*mnb, sb + n*mna) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}