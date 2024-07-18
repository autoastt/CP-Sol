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

ll a[N], dp[N];

void solve() {
    int n, x;
    ll ans = 0;
    fill_n(dp, N, 0);
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i-1];
    for (int i = n; i > 0; i--) {
        int j = upper_bound(a + i, a + n + 1, x + a[i-1]) - a;
        if (i == j) dp[i] = dp[i+1];
        else dp[i] = (j-i) + dp[j+1];
        ans += dp[i];
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
