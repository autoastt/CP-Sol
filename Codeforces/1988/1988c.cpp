#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define pb push_back
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const bool CASES = true;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

void solve() {
    ll n;
    cin >> n;
    vector<ll> ans(1, n);
    for (int i = 0; i < 63; i++) {
        if ((1ll << i) & n) {
            ll j = n ^ (1ll << i);
            if (j) ans.pb(j);
        }
    }
    sort(all(ans));
    cout << sz(ans) << "\n";
    for (auto i : ans) cout << i << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
