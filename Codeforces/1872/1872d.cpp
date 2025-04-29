#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n,x,y;
    cin >> n >> x >> y;
    ll a = n/x, b = n/y, c = n/(x*y/gcd(x,y));
    a -= c; b -= c;
    // cout << a << " " << b << "\n";
    ll ans = n*(n+1)/2 - (n-a+1)*(n-a)/2 - b*(b+1)/2;
    cout << ans << "\n";    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}