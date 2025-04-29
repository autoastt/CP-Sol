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

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    while (k > 0 && x > 1) {
        if (k >= y - (x % y)) {
            k -= (y - (x % y));
            x += (y - (x % y));
            while (x % y == 0) x /= y;
        }
        else {
            x += k;
            k = 0;
        }
    }
    if (k) x = (x + k) % (y - 1);
    if (!x) x = y - 1;
    cout << x << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
