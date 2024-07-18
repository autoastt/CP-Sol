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
const int N = 2e3 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

int a[N], p[N], sz[N];

int fp(int x) {return p[x] = p[x] == x ? x : fp(p[x]);}

bool unite(int u, int v) {
    u = fp(u), v = fp(v);
    if (u == v) return false;
    if (sz[u] > sz[v]) swap(u, v);
    sz[v] += sz[u];
    p[u] = v;
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v[n];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = i;
        sz[i] = 1;
    }
    vector<pii> ans;
    for (int i = n-1; i > 0; i--) {
        vector<int> md[i];
        bool united = false;
        for (int j = 1; j <= n; j++) md[a[j] % i].pb(j);
        for (int j = i-1; j >= 0; j--) {
            for (int k = 1; k < md[j].size(); k++) {
                if (unite(md[j][k], md[j][k-1])) {
                    ans.pb({md[j][k], md[j][k-1]});
                    united = true;
                    break;
                }
            }
            if (united) break;
        }
    }
    reverse(all(ans));
    cout << "YES\n";
    for (auto [u, v] : ans) cout << u << " " << v << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
