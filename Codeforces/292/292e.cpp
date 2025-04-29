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
struct SegmentTree {
    int n;
    vector<T> a, t, lz;

    SegmentTree(int n): n(n), a(n + 1), t(4 * n, -INF), lz(4 * n) {};

    void push(int x) {
        if (!lz[x]) return;
        t[x * 2] = t[x * 2 + 1] = t[x];
        lz[x * 2] = lz[x * 2 + 1] = true;
        lz[x] = false;
    }

    void upd(int l, int r, T val, int x, int tl, int tr) {
        if (tr < l || r < tl) return;
        else if (l <= tl && tr <= r) {
            t[x] = val;
            lz[x] = true;
            return;
        }
        push(x);
        int m = (tl + tr) / 2;
        upd(l, r, val, x * 2, tl, m);
        upd(l, r, val, x * 2 + 1, m + 1, tr);
    }

    T query(int pos, int x, int tl, int tr) {
        if (tl == tr) {
            return t[x];
        }
        push(x);
        int m = (tl + tr) / 2;
        if (pos <= m) return query(pos, x * 2, tl, m);
        return query(pos, x * 2 + 1, m + 1, tr);
    }

    void upd(int l, int r, T val) {
        upd(l, r, val, 1, 1, n);
    }

    T query(int pos) {
        return query(pos, 1, 1, n);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n + 1), b(n + 1);
    rep (i, 1, n) cin >> a[i];
    rep (i, 1, n) cin >> b[i];
    auto op = [](ll x, ll y) {
        return min(x, y);
    };
    SegmentTree<ll> s(n);
    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            s.upd(y, y + k - 1, x - y);
        }
        else {
            int x;
            cin >> x;
            ll y = s.query(x);
            if (y == -INF) cout << b[x] << NL;
            else cout << a[x + y] << NL;
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
