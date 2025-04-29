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
const int N = 4e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

int w[N], tin[N], tout[N], node[N], tt;
vi adj[N];

void dfs(int u, int p) {
    tin[u] = ++tt;
    node[tin[u]] = u;
    for (auto v : adj[u]) if (v != p) dfs(v, u);
    tout[u] = tt;
}

void solve() {
    int n;
    cin >> n;
    vector<pii> x;
    rep (i, 1, n) {
        cin >> w[i];
        adj[i].clear();
        x.pb({w[i], i});
    }
    rep (n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    tt = 0;
    dfs(1, 0);
    vi l(tt + 5), r(tt + 5);
    rep (i, 1, tt) l[i] = max(l[i - 1], w[node[i]]);
    rrep (i, tt, 1) r[i] = max(r[i + 1], w[node[i]]);
    sort(rall(x));
    for (auto [k, u] : x) {
        if (max(l[tin[u]], r[tout[u] + 1]) > k) return void(cout << u << NL);
    }
    cout << 0 << NL;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
