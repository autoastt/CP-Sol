#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n,k,x;
    cin >> n >> k >> x;
    ll mn = k*(k+1)/2;
    ll mx = n*(n+1)/2 - (n-k)*(n-k+1)/2;
    // cout << mn << " " << mx << '\n';
    if(x <= max(mn, mx) && x >= min(mn, mx)) cout << "yes\n";
    else cout << "no\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}