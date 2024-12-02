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
#define NL '\n'

const bool CASES = true;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

vi adj[N];
int n, m;
int tin[N], low[N], sz[N], timer;
ll ans;

void dfs(int u, int p) {
    tin[u] = low[u] = ++timer;
    sz[u] = 1;
    for (auto v : adj[u]) {
        if (v == p) continue;
        if (tin[v]) low[u] = min(low[u], tin[v]);
        else {
            dfs(v, u);
            sz[u] += sz[v];
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) {
                ll x = sz[v], y = n - x;
                ans = max(ans, 1ll * x * y);
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    rep (n + 1) adj[i].clear();
    fill_n(tin, N, 0);
    fill_n(low, N, 0);
    fill_n(sz, N, 0);
    timer = 0;
    ans = 0;
    rep (m) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 0);
    cout << 1ll * n * (n - 1) / 2 - ans << NL;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
