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
#define rrep0(a) for (int i = a - 1; i >= 0; i--)
#define rrep1(i, a) for (int i = a - 1; i >= 0; i--)
#define rrep2(i, a, b) for (int i = a; i >= b; i--)
#define rrep3(i, a, b, c) for (int i = a; i >= b; i -= c)

const bool CASES = false;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

// dis(u, v) = dis[u] + dis[v] - 2 * dis[lca(u, v)]
// need to find a way to detect edges on paths and also update
// update dis by ETT and BIT

struct Fenwick {
    int n;
    vector<ll> bit;

    Fenwick(int n) : n(n) {
        bit.assign(n * 2, 0);
    }

    void update(int i, ll x) {
        for (; i <= n; i += i & -i) bit[i] += x;
    }

    ll query(int i) {
        ll ret = 0;
        for (; i > 0; i -= i & -i) ret += bit[i];
        return ret;
    }
};

vector<pll> adj[N];
vector<pair<pll, ll>> e;
ll in[N], out[N], timer, par[25][N], dis[N];

void dfs(int u, int p) {
    in[u] = ++timer;
    par[0][u] = p;
    rep (i, 1, 20) par[i][u] = par[i-1][par[i-1][u]];
    dis[u] = dis[p] + 1;
    for (auto [v, w] : adj[u]) if (v != p) dfs(v, u);
    out[u] = timer;
}

int jump(int x, int k) {
    rep (20) if (k >> i & 1) x = par[i][x];
    return x;
}

int lca(int u, int v) {
    if (dis[u] < dis[v]) swap(u, v);
    u = jump(u, dis[u] - dis[v]);
    if (u == v) return u;
    rrep (20) if (par[i][u] != par[i][v]) u = par[i][u], v = par[i][v];
    return par[0][u];
}

void solve() {
    int n;
    cin >> n;
    rep (i, 1, n-1) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
        e.pb({{u, v}, w});
    }
    dfs(1, 0);
    Fenwick fw(n);
    for (auto [p, w] : e) {
        auto [u, v] = p;
        if (dis[u] < dis[v]) swap(u, v);
        fw.update(in[u], w);
        fw.update(out[u] + 1, -w);
    }
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, ww;
            cin >> i >> ww;
            i--;
            auto [p, w] = e[i];
            auto [u, v] = p;
            if (dis[u] < dis[v]) swap(u, v);
            fw.update(in[u], ww - w);
            fw.update(out[u] + 1, -(ww - w));
            e[i].second = ww;
        }
        else {
            int u, v;
            cin >> u >> v;
            cout << fw.query(in[u]) + fw.query(in[v]) - 2 * fw.query(in[lca(u, v)]) << "\n";
        }
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
