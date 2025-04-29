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
    string s;
    vector<T> t;

    SegmentTree(string s): n(sz(s)), s(s), t(4 * n) {};

    void build(int x, int tl, int tr) {
        if (tl == tr) {
            if (s[tl - 1] == '(') t[x].b = 1;
            else t[x].c = 1;
            return;
        }
        int m = (tl + tr) / 2;
        build(x * 2, tl, m);
        build(x * 2 + 1, m + 1, tr);
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

    T query(int l, int r) {
        return query(l, r, 1, 1, n);
    }
};

void solve() {
    string s;
    cin >> s;
    struct A {
        ll a, b, c;
    };
    auto op = [](A x, A y) -> A {
        ll k = min(x.b, y.c);
        return {x.a + y.a + 2 * k, x.b + y.b - k, x.c + y.c - k};
    };
    SegmentTree<A, op, {0, 0, 0}> st(s);
    st.build();
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << st.query(l, r).a << NL;
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
