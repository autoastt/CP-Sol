#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define GET_MACRO(_1, _2, _3, _4, NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2, rep1, rep0)(__VA_ARGS__)
#define rrep(...) GET_MACRO(__VA_ARGS__, rrep3, rrep2, rrep1, rrep0)(__VA_ARGS__)
#define rep0(a) for (int i = 0; i < a; i++)
#define rep1(i, a) for (int i = 0; i < a; i++)
#define rep2(i, a, b) for (int i = a; i <= b; i++)
#define rep3(i, a, b, c) for (int i = a; i <= b; i += c)
#define rrep0(a) for (int i = a; i > 0; i--)
#define rrep1(i, a) for (int i = a; i > 0; i--)
#define rrep2(i, a, b) for (int i = a; i >= b; i--)
#define rrep3(i, a, b, c) for (int i = a; i >= b; i -= c)

const bool CASES = true;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep (n) cin >> a[i];
    if (n <= k) {
        sort(all(a));
        return void(cout << a[(n - 1) / 2] << "\n");
    }
    int l = 1, r = INF;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        vi b(n), dp(n);
        // if `mid` <= median, greater > lesser
        rep (n) b[i] = (a[i] >= mid ? 1 : -1);
        dp[0] = b[0];
        rep (i, 1, n - 1) {
            if (i % k) {
                dp[i] = dp[i-1] + b[i];
                if (i > k) dp[i] = max(dp[i-k], dp[i]);
            }
            else dp[i] = max(dp[i-k], b[i]);
        }
        if (dp[n-1] > 0) l = mid;
        else r = mid - 1;
    }
    cout << l << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
