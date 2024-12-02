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
const int N = 1e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

ll fw[N];

void update(int i, int x) {
    for (; i < N; i += i & -i) fw[i] += x;
}

ll sum(int i) {
    ll ret = 0;
    for (; i > 0; i -= i & -i) ret += fw[i];
    return ret;
}

vi adj[N];
vector<pii> e;
int in[N], out[N], timer, par[25][N], dis[N];

void dfs(int u, int p) {
    in[u] = ++timer;
    par[0][u] = p;
    dis[u] = dis[p] + 1;
    for (auto v : adj[u]) if (v != p) dfs(v, u);
    out[u] = timer;
}

void solve() {
    int n;
    cin >> n;
    rep (i, 1, n-1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        e.pb({u, v});
    }
    dfs(1, 0);
    rep (i, 1, 20) {
        rep (j, 1, n) {
            par[i][j] = par[i-1][par[i-1][j]];
        }
    }
    auto jump = [&](int x, int k) {
        rep (20) if (k & (1 << i)) x = par[i][x];
        return x;
    };
    auto lca = [&](int u, int v) {
        if (dis[u] < dis[v]) swap(u, v);
        u = jump(u, dis[u] - dis[v]);
        if (u == v) return u;
        rrep (20) if (par[i][u] != par[i][v]) u = par[i][u], v = par[i][v];
        return par[0][u];
    };
    rep (i, 1, n) update(in[i], 1), update(out[i] + 1, -1);
    int m;
    cin >> m;
    while (m--) {
        int t;
        cin >> t;
        if (t != 3) {
            int x; cin >> x;
            auto [u, v] = e[--x];
            if (dis[u] < dis[v]) swap(u, v);
            update(in[u], t & 1 ? 1 : -1);
            update(out[u] + 1, t & 1 ? -1 : 1);
        }
        else {
            int u, v;
            cin >> u >> v;
            int x = lca(u, v);
            int d = sum(in[u]) + sum(in[v]) - 2 * sum(in[x]);
            if (d == dis[u] + dis[v] - 2 * dis[x]) cout << d << "\n";
            else cout << "-1\n";
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
