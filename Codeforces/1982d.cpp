#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define pb push_back
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
const bool CASES = true;
const int N = 505;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

ll a[N][N], b[N][N], c[N][N][2];

void solve() {
    ll n, m, k, d = 0, dd = 0;
    cin >> n >> m >> k;
    string s[n];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> s[i-1];
        for (int j = 1; j <= m; j++) {
            b[i][j] = s[i-1][j-1] - '0';
            d += a[i][j] * (b[i][j] ? 1 : -1);
            c[i][j][0] = c[i-1][j][0] + c[i][j-1][0] - c[i-1][j-1][0] + (b[i][j] ? 0 : 1);
            c[i][j][1] = c[i-1][j][1] + c[i][j-1][1] - c[i-1][j-1][1] + (b[i][j] ? 1 : 0);
        }
    }
    d = abs(d);
    if (!d) return void(cout << "YES\n");
    for (int i = k; i <= n; i++) {
        for (int j = k; j <= m; j++) {
            ll zero = c[i][j][0] - c[i-k][j][0] - c[i][j-k][0] + c[i-k][j-k][0];
            ll one = c[i][j][1] - c[i-k][j][1] - c[i][j-k][1] + c[i-k][j-k][1];
            ll now = abs(one - zero);
            dd = gcd(dd, now);
        }
    }
    if (!dd) return void(cout << "NO\n");
    cout << (d % dd ? "NO\n" : "YES\n");
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
