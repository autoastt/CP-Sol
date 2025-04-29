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

int a[N];

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) cin >> a[i];
    int sum = 0, ans = 0;
    for (int i = 0, j = 0; j < n;) {
        sum += a[j++];
        while (sum > r && i < j) sum -= a[i++];
        if (l <= sum && sum <= r) i = j, sum = 0, ans++;
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
