#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define mp make_pair
#define pb push_back
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
const bool CASES = true;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

int k[N], h[N];

void solve() {
    int n;
    cin >> n;
    ll ans = 0, last_pos = 0, last_h = 0;
    for (int i = 1; i <= n; i++) cin >> k[i];
    vector<pll> v;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        v.pb({k[i] - h[i], k[i]});
    }
    sort(all(v));
    for (auto [st, ed] : v) {
        if (ed <= last_pos) continue;
        else if (st < last_pos) {
            ll x = ed - last_pos + last_h;
            ans += x * (x + 1) / 2 - last_h * (last_h + 1) / 2;
            last_h = x;
            last_pos = ed;
        }
        else {
            ans += (ed - st) * (ed - st + 1) / 2;
            last_h = ed - st;
            last_pos = ed;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
