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

void solve() {
    int n, q;
    string s;
    cin >> n >> q >> s;
    vi x(n + 5), y(n + 5);
    map<pii, vi> mp;
    mp[{0, 0}].pb(0);
    s = " " + s;
    rep (i, 1, n) {
        x[i] = x[i - 1], y[i] = y[i - 1];
        if (s[i] == 'U') y[i]++;
        else if (s[i] == 'D') y[i]--;
        else if (s[i] == 'L') x[i]--;
        else x[i]++;
        mp[{x[i], y[i]}].pb(i);
    }
    while (q--) {
        int xx, yy, l, r;
        cin >> xx >> yy >> l >> r;
        bool ok = false;
        if (mp.count({xx, yy})) {
            if (mp[{xx, yy}][0] < l || mp[{xx, yy}].back() >= r) {
                ok = true;
            }
        }
        if (!ok) {
            int fx = x[l - 1] + x[r] - xx;
            int fy = y[l - 1] + y[r] - yy;
            if (mp.count({fx, fy})) {
                auto f = lb(mp[{fx, fy}].begin(), mp[{fx, fy}].end(), l);
                if (f != mp[{fx, fy}].end() && *f <= r) {
                    ok = true;
                }
            }
        }
        if (ok) cout << "YES" << NL;
        else cout << "NO" << NL;
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
