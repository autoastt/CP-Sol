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

vi adj[2][N];

void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<pii> e;
    rep (i, 1, n) adj[0][i].clear(), adj[1][i].clear();
    rep (m1) {
        int u, v;
        cin >> u >> v;
        e.pb({u, v});
    }
    rep (m2) {
        int u, v;
        cin >> u >> v;
        adj[1][u].pb(v);
        adj[1][v].pb(u);
    }
    vector<vi> cmp(2, vi(n + 1));
    function<void(int, int, int)> dfs = [&](int u, int k, int x) {
        cmp[k][u] = x;
        for (auto v : adj[k][u]) if (!cmp[k][v]) dfs(v, k, x);
    };
    int now = 0, ans = 0;
    rep (i, 1, n) if (!cmp[1][i]) dfs(i, 1, ++now);
    for (auto [u, v] : e) {
        if (cmp[1][u] != cmp[1][v]) ans++;
        else {
            adj[0][u].pb(v);
            adj[0][v].pb(u);
        }
    }
    ans -= now;
    now = 0;
    rep (i, 1, n) if (!cmp[0][i]) dfs(i, 0, ++now);
    cout << ans + now << NL;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
