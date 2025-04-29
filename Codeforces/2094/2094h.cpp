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
const int N = 1e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<pair<pii, pii>> v;
    vi a(n);
    rep (n) cin >> a[i];
    rep (q) {
        int k, l, r;
        cin >> k >> l >> r;
        v.pb({{--l, --r}, {k, i}});
    }
    vll ans(q);
    sort(rall(v));
    int pre = n - 1;
    vi first(N, -1);
    for (auto [len, p] : v) {
        auto [l, r] = len;
        auto [k, j] = p;
        while (pre >= l) {
            first[a[pre]] = pre;
            pre--;
        }
        vi d;
        for (int i = 2; 1ll * i * i <= k; i++) {
            if (k % i == 0) {
                if (first[i] != -1 && first[i] <= r) d.pb(first[i]);
                if (1ll * i * i != k && first[k / i] != -1 && first[k / i] <= r) d.pb(first[k / i]);
            }
        }
        if (first[k] != -1 && first[k] <= r) d.pb(first[k]);
        sort(all(d));
        ll pl = l;
        for (auto x : d) {
            ans[j] += (x - pl) * k;
            while (k % a[x] == 0) k /= a[x];
            pl = x;
        }
        ans[j] += (r - pl + 1) * k;
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
