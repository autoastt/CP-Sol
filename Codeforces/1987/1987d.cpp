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
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

void solve() {
    int n, ans = 0, mx = 0;
    cin >> n;
    map<int, int> cnt;
    vi c;
    rep (n) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (auto [i, x] : cnt) c.pb(x);
    // dp[k] = min number of k types of cakes Bob eats
    vi dp(sz(c) + 1, INF);
    dp[0] = 0;
    rep (i, 1, sz(c)) {
        vi ndp = dp;
        // from c[0] to c[i-1], update dp[j] if Bob can eat c[i-1]
        rep (j, 1, sz(c)) {
            if (dp[j-1] + c[i-1] <= i - j)
                ndp[j] = min(ndp[j], dp[j-1] + c[i-1]);
        }
        dp = ndp;
    }
    rep (i, 0, sz(c)) if (dp[i] != INF) ans = max(ans, i);
    cout << sz(c) - ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
