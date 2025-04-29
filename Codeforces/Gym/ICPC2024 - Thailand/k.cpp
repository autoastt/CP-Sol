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
#define rrep0(a) for (int i = (a) - 1; i >= 0; i--)
#define rrep1(i, a) for (int i = (a) - 1; i >= 0; i--)
#define rrep2(i, a, b) for (int i = a; i >= b; i--)
#define rrep3(i, a, b, c) for (int i = a; i >= b; i -= c)
#define NL '\n'

const bool CASES = false;
const int N = 2e4 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

ll t[N], c[N];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vll dp(1 << k, LLINF);
    dp[0] = 0;
    rep (n) {
        int x;
        cin >> x >> c[i];
        rep (j, x) {
            int y;
            cin >> y;
            t[i] |= 1 << --y;
        }
        rep (j, 1 << k)
            dp[j | t[i]] = min(dp[j | t[i]], dp[j] + c[i]);
    }
    rep (1 << k) {
        for (int s = i; s; s = (s - 1) & i) dp[s] = min(dp[s], dp[i]);
    }
    // rrep (1 << k) {
    //     rep (j, k) {
    //         if (i >> j & 1)
    //             dp[i ^ (1 << j)] = min(dp[i], dp[i ^ (1 << j)]);
    //     }
    // }
    rep (m) {
        int x, q = 0;
        cin >> x;
        rep (x) {
            int y;
            cin >> y;
            q |= 1 << --y;
        }
        cout << (dp[q] == LLINF ? -1 : dp[q]) << NL;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
