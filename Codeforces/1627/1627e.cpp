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

const bool CASES = true;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

struct A {
    ll b, c, d, h;
};
vector<A> l[N];
ll x[N];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    rep (i, 1, n) cin >> x[i], l[i].clear();
    map<ll, ll> dp[n + 1];
    rep (k) {
        int a, b, c, d, h;
        cin >> a >> b >> c >> d >> h;
        l[a].pb({b, c, d, h});
        dp[a][b] = dp[c][d] = LLINF;
    }
    dp[1][1] = 0;
    dp[n][m] = LLINF;
    rep (i, 1, n) {
        ll pj, py;
        if (dp[i].empty()) continue;
        pj = dp[i].begin()->first;
        py = dp[i].begin()->second;
        for (auto it = ++dp[i].begin(); it != dp[i].end(); it++) {
            auto [j, y] = *it;
            dp[i][j] = min(dp[i][j], py + x[i] * (j - pj));
            pj = j;
            py = dp[i][j];
        }
        pj = dp[i].rbegin()->first;
        py = dp[i].rbegin()->second;
        for (auto it = ++dp[i].rbegin(); it != dp[i].rend(); it++) {
            auto [j, y] = *it;
            dp[i][j] = min(dp[i][j], py + x[i] * (pj - j));
            pj = j;
            py = dp[i][j];
        }
        for (auto [b, c, d, h] : l[i]) {
            if (dp[i][b] != LLINF) dp[c][d] = min(dp[c][d], dp[i][b] - h);
        }
    }
    if (dp[n][m] == LLINF) cout << "NO ESCAPE\n";
    else cout << dp[n][m] << NL;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
