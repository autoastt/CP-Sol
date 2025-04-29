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
const int N = 300;
const int K = 20;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

void add(ll &x, ll y) {
    x = (x + y) % M;
}

ll dp[1 << K][2][2];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    rep (i, n) {
         cin >> a[i];
    }
    if (m < n) {
        vector<string> b(m, string("", n));
        rep (i, m) {
            rep (j, n) {
                b[i][j] = a[j][i];
            }
        }
        swap(a, b);
        swap(n, m);
    }
    vector<vector<vll>> dp(1 << n, vector<vll>(2, vll(2)));
    dp[0][0][0] = 1;
    rep (j, m) {
        rep (i, n) {
            vector<vector<vll>> ndp(1 << n, vector<vll>(2, vll(2)));
            rep (mask, 1 << n) {
                rep (c, 2) {
                    rep (t, 2) {
                        if (a[i][j] == 'x') {
                            if (mask >> i & 1) add(ndp[mask ^ (1 << i)][c][0], dp[mask][c][t]);
                            else add(ndp[mask][c][0], dp[mask][c][t]);
                            continue;
                        }
                        add(ndp[mask | (1 << i)][c][1], dp[mask][c][t]);
                        bool protect = (mask >> i & 1) || t;
                        if (c && !protect) continue;
                        add(ndp[mask][c || !protect][t], dp[mask][c][t]);
                    }
                }
            }
            if (i == n - 1) {
                rep (mask, 1 << n) {
                    rep (c, 2) {
                        add(ndp[mask][c][0], ndp[mask][c][1]);
                        ndp[mask][c][1] = 0;
                    }
                }
            }
            swap(ndp, dp);
        }
    }
    ll ans = 0;
    rep (mask, 1 << n) {
        rep (c, 2) {
            add(ans, dp[mask][c][0]);
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
