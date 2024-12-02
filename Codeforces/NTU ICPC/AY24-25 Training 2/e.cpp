#include <bits/stdc++.h>
using namespace std;
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
#define rrep0(a) for (int i = a; i > 0; i--)
#define rrep1(i, a) for (int i = a; i > 0; i--)
#define rrep2(i, a, b) for (int i = a; i >= b; i--)
#define rrep3(i, a, b, c) for (int i = a; i >= b; i -= c)

const bool CASES = false;
const int N = 1e6 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

pll t[4 * N];
ll dpmx[N], dpmn[N];

pll combine(pll x, pll y) {
    return {max(x.first, y.first), min(x.second, y.second)};
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = {0, INF};
        return;
    }
    int tm = (tl + tr) / 2;
    build(v*2, tl, tm);
    build(v*2+1, tm+1, tr);
    t[v] = combine(t[v*2], t[v*2+1]);
}

void update(int v, int tl, int tr, int pos, int x) {
    if (tl == tr) {
        t[v] = {x, x};
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) update(v*2, tl, tm, pos, x);
    else update(v*2+1, tm+1, tr, pos, x);
    t[v] = combine(t[v*2], t[v*2+1]);
}

pll query(int v, int tl, int tr, int l, int r) {
    if (l <= tl && tr <= r) return t[v];
    else if (tr < l || r < tl) return {0, INF};
    int tm = (tl + tr) / 2;
    return combine(query(v*2, tl, tm, l, r), query(v*2+1, tm+1, tr, l, r));
}

// find first greater
int query2(int v, int tl, int tr, int l, int r, int x) {
    if (tr < l || r < tl) return -1;
    if (t[v].first <= x) return -1;
    if (tl == tr) return tl;
    int tm = (tl + tr) / 2;
    int right = query2(v*2+1, tm+1, tr, l, r, x);
    if (right != -1) return right;
    return query2(v*2, tl, tm, l, r, x);
}

// find first lesser
int query3(int v, int tl, int tr, int l, int r, int x) {
    if (tr < l || r < tl) return -1;
    if (t[v].second >= x) return -1;
    if (tl == tr) return tl;
    int tm = (tl + tr) / 2;
    int right = query3(v*2+1, tm+1, tr, l, r, x);
    if (right != -1) return right;
    return query3(v*2, tl, tm, l, r, x);
}

void solve() {
    int n;
    cin >> n;
    ll ans = 0;
    rep (i, 1, n) {
        ll x;
        cin >> x;
        ll bmx, bmn;
        bmx = query2(1, 1, n, 1, i-1, x);
        bmn = query3(1, 1, n, 1, i-1, x);
        if (bmx == -1) bmx = 0;
        dpmx[i] = (1ll * i - bmx) * x + dpmx[bmx];
        if (bmn == -1) bmn = 0;
        dpmn[i] = (1ll * i - bmn) * x + dpmn[bmn];
        ans += dpmx[i] - dpmn[i];
        update(1, 1, n, i, x);
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
