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

template <class T, auto op, T e>
struct SegmentTree {
    int n;
    vector<ll> a;
    vector<T> t;

    SegmentTree(int n): n(n), a(n + 1, e), t(4 * n) {};
    SegmentTree(vector<ll> a): n(sz(a) - 1), a(a), t(4 * n) {};

    void build(int x, int tl, int tr) {
        if (tl == tr) {
            t[x] = {a[tl], 1, a[tl]};
            return;
        }
        int m = (tl + tr) / 2;
        build(x * 2, tl, m);
        build(x * 2 + 1, m + 1, tr);
        t[x] = op(t[x * 2], t[x * 2 + 1]);
    }

    void upd(int idx, T val, int x, int tl, int tr) {
        if (tl == tr) {
            t[x] = a[tl] = val;
            return;
        }
        int m = (tl + tr) / 2;
        if (idx <= m) upd(idx, val, x * 2, tl, m);
        else upd(idx, val, x * 2 + 1, m + 1, tr);
        t[x] = op(t[x * 2], t[x * 2 + 1]);
    }

    T query(int l, int r, int x, int tl, int tr) {
        if (tr < l || r < tl) return e;
        else if (l <= tl && tr <= r) return t[x];
        int m = (tl + tr) / 2;
        return op(query(l, r, x * 2, tl, m), query(l, r, x * 2 + 1, m + 1, tr));
    }

    void build() {
        build(1, 1, n);
    }

    void upd(int idx, T val) {
        upd(idx, val, 1, 1, n);
    }

    T query(int l, int r) {
        return query(l, r, 1, 1, n);
    }
};

void solve() {
    int n;
    cin >> n;
    vll a(n + 1);
    rep (i, 1, n) cin >> a[i];
    struct A {
        ll mn, cnt, gcd;
    };
    auto op = [](A x, A y) {
        A ret;
        if (x.mn > y.mn) swap(x, y);
        if (x.mn == 0) return y;
        ret.mn = x.mn;
        ret.cnt = x.cnt;
        if (x.mn == y.mn) ret.cnt += y.cnt;
        ret.gcd = gcd(x.gcd, y.gcd);
        return ret;
    };
    SegmentTree<A, op, {0, 0, 0}> s(a);
    s.build();
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        auto x = s.query(l, r);
        if (x.gcd == x.mn) cout << r - l + 1 - x.cnt << NL;
        else cout << r - l + 1 << NL;
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
