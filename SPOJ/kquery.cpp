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
    int n;
    cin >> n;
    vll a(n + 1);
    vector<pll> v;
    rep (i, 1, n) cin >> a[i], v.pb({a[i], i});
    function<ll(ll, ll)> op = [](ll x, ll y) {
        return x + y;
    };
    Fenwick<ll> s(n);
    sort(all(v));
    int q;
    cin >> q;
    vi ans(q);
    vector<pair<pii, pii>> k(q);
    rep (q) cin >> k[i].second.first >> k[i].second.second >> k[i].first.first, k[i].first.second = i;
    sort(all(k));
    int now = 0;
    rep (q) {
        int x = k[i].first.first;
        auto [l, r] = k[i].second;
        while (now < n && v[now].first <= x) {
            s.add(v[now++].second, 1);
        }
        ans[k[i].first.second] = r - l + 1 - s.sum(l, r);
    }
    rep (q) cout << ans[i] << NL;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
