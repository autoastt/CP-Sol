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
#define rrep0(a) for (int i = (a) - 1; i >= 0; i--)
#define rrep1(i, a) for (int i = (a) - 1; i >= 0; i--)
#define rrep2(i, a, b) for (int i = a; i >= b; i--)
#define rrep3(i, a, b, c) for (int i = a; i >= b; i -= c)
#define NL '\n'

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const bool CASES = false;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

struct Fenwick {
    int n;
    vll fw;

    Fenwick(int n): n(n) {
        fw.assign(n + 1, 0);
    }

    ll sum(int idx) {
        ll ret = 0;
        for (; idx > 0; idx -= idx & -idx) ret = (ret + fw[idx]) % M;
        return ret;
    }

    void upd(int idx, ll x) {
        for (; idx <= n; idx += idx & -idx) fw[idx] = (fw[idx] + x) % M;
    }
};

void solve() {
    int n;
    cin >> n;
    ll ans = 0;
    vector<pll> v;
    vll x(n);
    rep (n) {
        cin >> x[i];
        v.pb({x[i], i});
    }
    sort(all(v));
    ll pre = 0, idx = 0;
    rep (n) {
        if (v[i].first != pre) {
            pre = v[i].first;
            idx++;
        }
        x[v[i].second] = idx;
    }
    Fenwick fw(n);
    rep (n) {
        ll cnt = fw.sum(x[i] - 1) + 1;
        ans = (ans + cnt) % M;
        fw.upd(x[i], cnt);
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
