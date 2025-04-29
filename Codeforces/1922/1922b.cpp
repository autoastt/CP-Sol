#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 3e5+5;
ll a[N];

void solve() {
    int n, mx = 0;
    ll ans = 0;
    cin >> n;
    fill_n(a, N, 0);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a[x]++;
        mx = max(mx, x);
    }
    for(int i = 1; i <= mx; i++) a[i] += a[i-1];
    if(a[0] > 2) ans += a[0] * (a[0]-1) * (a[0]-2) / 6;
    for(int i = 1; i <= mx; i++){
        ll now = a[i] - a[i-1];
        if(now > 1) ans += now * (now-1) / 2 * a[i-1];
        if(now > 2) ans += now * (now-1) * (now-2) / 6;
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