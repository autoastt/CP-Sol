#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;

ll a[N];

void solve() {
    int n;
    ll ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    for (int i = 1; i < n; i++) {
        ans += a[i] - a[i-1];
    }
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
