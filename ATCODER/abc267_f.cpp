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

const bool CASES = false;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

vi adj[N];
int p[25][N], dis[N], l, r, mx;

void dfs(int u, int pre, bool save = true) {
    dis[u] = dis[pre] + 1;
    p[0][u] = pre;
    if (mx < dis[u]) mx = dis[u], l = u;
    for (auto v : adj[u]) {
        if (v == pre) continue;
        dfs(v, u);
    }
}

void solve() {
    int n;
    cin >> n;
    rep (n-1) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1, 0);
    r = l;
    mx = 0;
    fill_n(dis, N, 0);
    dfs(r, 0, false);
    rep (i, 1, 20) {
        rep (j, 1, n) {
            p[i][j] = p[i-1][p[i-1][j]];
        }
    }
    auto jump = [&](int x, int k) {
        rep (i, 0, 20) {
            if (k & (1 << i)) x = p[i][x];
        }
        return x;
    };
    auto lca = [&](int u, int v) {
        if (dis[u] < dis[v]) swap(u, v);
        u = jump(u, dis[u] - dis[v]);
        if (u == v) return u;
        rrep (i, 20, 0) {
            int ux = jump(u, i), vx = jump(v, i);
            if (ux == vx) continue;
            u = ux, v = vx;
        }
        return p[0][u];
    };
    int q;
    cin >> q;
    while (q--) {
        int u, k;
        cin >> u >> k;
        bool found = false;
        for (int i : {l, r}) {
            int x = lca(u, i);
            if (dis[u] - dis[x] >= k) {
                cout << jump(u, k) << "\n";
                found = true;
            }
            else if (dis[u] + dis[i] - 2 * dis[x] >= k) {
                cout << jump(i, dis[u] + dis[i] - 2 * dis[x] - k) << "\n";
                found = true;
            }
            if (found) break;
        }
        if (!found) cout << "-1\n";
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
