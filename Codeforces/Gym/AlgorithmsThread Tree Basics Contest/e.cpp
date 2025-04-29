#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
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

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 mt64(chrono::steady_clock::now().time_since_epoch().count());

const bool CASES = false;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

template <class T>
struct Fenwick {
    int n;
    vector<T> fw;
    vector<T> arr;

    Fenwick(int n) : n(n), fw(n + 1), arr(n + 1) {}

    void set(int i, T x) {
        add(i, x - arr[i]);
    }

    void add(int i, T x) {
        arr[i] += x;
        for (; i <= n; i += i & -i) fw[i] += x;
    }

    T sum(int i) {
        T ret = 0;
        for (; i > 0; i -= i & -i) ret += fw[i];
        return ret;
    }

    T sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

void solve() {
    int n, q;
    cin >> n;
    vi adj[n + 1], tin(n + 1), tout(n + 1), node(n + 1);
    rep (n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int t = 0;
    function<void(int, int)> dfs = [&](int u, int p) {
        tin[u] = ++t;
        for (auto v : adj[u]) if (v != p) dfs(v, u);
        tout[u] = t;
    };
    cin >> q;
    dfs(1, 0);
    Fenwick<double> fw(t);
    cout << fixed << setprecision(10);
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            fw.set(tin[x], 1.0 * log10(y));
        }
        else {
            double k = fw.sum(tin[x], tout[x]) - fw.sum(tin[y], tout[y]);
            if (k >= 9) cout << 1000000000 << NL;
            else cout << pow(10, k) << NL;
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
