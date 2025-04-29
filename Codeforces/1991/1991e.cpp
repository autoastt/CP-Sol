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

void solve() {
    int n, m;
    cin >> n >> m;
    vi adj[n + 1];
    rep (m) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vi vis(n + 1, -1), c[2];
    bool bipartite = true;
    queue<int> q;
    q.push(1);
    vis[1] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        c[vis[u]].pb(u);
        for (auto v : adj[u]) {
            if (vis[v] == -1) {
                vis[v] = vis[u] ^ 1;
                q.push(v);
            }
            else bipartite &= vis[u] ^ vis[v];
        }
    }
    if (bipartite) {
        cout << "Bob" << endl;
        int c0 = 0, c1 = 0;
        rep (n) {
            int a, b;
            cin >> a >> b;
            if (a == 1 || b == 1) {
                if (c0 < sz(c[0])) cout << c[0][c0++] << ' ' << 1 << endl;
                else cout << c[1][c1++] << ' ' << a + b - 1 << endl;
            }
            else if (a == 2 || b == 2) {
                if (c1 < sz(c[1])) cout << c[1][c1++] << ' ' << 2 << endl;
                else cout << c[0][c0++] << ' ' << a + b - 2 << endl;
            }
        }
    }
    else {
        cout << "Alice" << endl;
        rep (n) {
            cout << "1 2" << endl;
            int a, b;
            cin >> a >> b;
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
