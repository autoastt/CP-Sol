#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define pb push_back
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const bool CASES = true;
const int N = 3e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

ll a[N], dp[N][20];
vector<int> adj[N];

void dfs(int u, int p) {
    for (int i = 1; i < 20; i++) dp[u][i] = i * a[u];
    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        for (int i = 1; i < 20; i++) {
            ll mn = LLINF;
            for (int j = 1; j < 20; j++) {
                if (i == j) continue;
                mn = min(mn, dp[v][j]);
            }
            dp[u][i] += mn;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    ll ans;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        adj[i].clear();
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 0);
    ans = *min_element(dp[1] + 1, dp[1] + 20);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
