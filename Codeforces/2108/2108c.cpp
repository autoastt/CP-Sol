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

const bool CASES = true;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

void solve() {
    int n;
    cin >> n;
    vi a(n + 1), vis(n), b;
    vector<pii> v;
    set<int> s;
    map<int, int> mp;
    rep (n) cin >> a[i], s.insert(a[i]);
    int cnt = 1;
    for (auto i : s) mp[i] = cnt++;
    b.pb(a[0]);
    v.pb({a[0], 0});
    rep (i, 1, n - 1) if (a[i] != a[i - 1]) b.pb(a[i]), v.pb({a[i], sz(b) - 1});
    sort(rall(v));
    int ans = 0;
    rep (sz(v)) {
        auto [x, j] = v[i];
        if (vis[j]) continue;
        if (!((j > 0 && vis[j - 1] && b[j - 1] >= b[j]) || (j < sz(b) - 1 && vis[j + 1] && b[j + 1] >= b[j]))) ans++;
        vis[j] = true;
        int k = j - 1;
        while (k >= 0 && (mp[b[k]] == mp[b[k + 1]] - 1 || b[k] == b[k + 1])) vis[k--] = true;
        k = j + 1;
        while (k < sz(b) && (mp[b[k]] == mp[b[k - 1]] - 1 || b[k] == b[k - 1])) vis[k++] = true;
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
