#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define pb push_back
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
const bool CASES = true;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

ll a[N], c[N];

void solve() {
    int n, h;
    cin >> h >> n;
    bool out = false;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (out) continue;
        h -= a[i];
        if (h < 0) out = true;
    }
    for (int i = 0; i < n; i++) cin >> c[i];
    if (out) return void(cout << "1\n");
    ll l = 0, r = 1e12;
    while (l < r) {
        ll mid = (l + r - 1) / 2;
        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += a[i] * (mid / c[i]);
        }
        if (cnt >= h) r = mid;
        else l = mid + 1;
    }
    cout << ++r << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
