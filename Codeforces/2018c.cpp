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
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

vi adj[N];
pii node[N];
int cnt0[N], cnt1[N], mxd;

pii dfs(int u, int p, int d) {
    node[u] = {d, 1};
    mxd = max(mxd, d);
    cnt1[d]++;
    for (auto v : adj[u]) if (v != p) {
        pii vv = dfs(v, u, d + 1);
        node[u].first = max(node[u].first, vv.first);
        node[u].second += vv.second;
    }
    cnt0[node[u].first]++;
    return node[u];
}

void solve() {
    int n;
    cin >> n;
    rep (n + 1) adj[i].clear(), cnt0[i] = cnt1[i] = 0;
    mxd = 0;
    rep (n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 0, 0);
    rep (i, 1, mxd) cnt0[i] += cnt0[i - 1];
    rrep (i, mxd) cnt1[i] += cnt1[i + 1];
    int ans = INF;
    rep (mxd + 1) {
        ans = min(ans, (i ? cnt0[i - 1] : 0) + cnt1[i + 1]);
    }
    cout << ans << NL;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
