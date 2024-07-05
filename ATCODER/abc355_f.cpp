#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define pb push_back
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
const bool CASES = false;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

int p[15][N], sz[15][N];

int find_p(int i, int u) {
    return p[i][u] = p[i][u] == u ? u : find_p(i, p[i][u]);
}

bool unite(int i, int u, int v) {
    u = find_p(i, u);
    v = find_p(i, v);
    if(u == v) return false;
    if(sz[i][u] < sz[i][v]) swap(u, v);
    p[i][v] = u;
    sz[i][u] += sz[i][v];
    return true;
}

struct A {
    int u, v, w;
    bool operator <(const A &o)const {
        return w < o.w;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    int mst = 0;
    vector<A> v;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 10; j++) {
            p[j][i] = i;
            sz[j][i] = 1;
        }
    }
    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.pb({a, b, c});
        mst += c;
    }
    sort(all(v));
    for(auto [u, v, w] : v) {
        while (w <= 10 && unite(w, u, v)) w++;
    }
    while (q--) {
        int u, v, w;
        cin >> u >> v >> w;
        while (w <= 10 && unite(w, u, v)) {
            mst--;
            w++;
        }
        cout << mst << "\n";
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
