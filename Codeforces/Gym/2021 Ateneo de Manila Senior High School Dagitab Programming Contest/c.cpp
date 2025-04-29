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
mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

const bool CASES = false;
const int N = 5e6 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

map<int, int> nim;

int f(int n) {
    if (nim.count(n)) return nim[n];
    set<int> s;
    s.insert(f(1));
    for (int i = 2; i * i <= n; i++) {
        if (n % i) continue;
        s.insert(f(i));
        s.insert(f(n / i));
    }
    int mex = 0;
    while (mex < sz(s)) {
        if (s.count(mex)) mex++;
        else break;
    }
    return nim[n] = mex;
}

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    nim[0] = nim[1] = 0;
    vll p, lp(N + 1), cnt(N + 1);
    rep (i, 2, N) {
        if (!lp[i]) p.pb(i), lp[i] = i, cnt[i] = 1;
        rep (j, sz(p)) {
            if (1ll * p[j] * i > N) break;
            lp[i * p[j]] = p[j];
            cnt[i * p[j]] = cnt[i] + 1;
            if (p[j] == lp[i]) break;
        }
    }
    ll ans = 0;
    map<ll, ll> mp;
    rep (x + 1) {
        mp[cnt[n - i]]++;
    }
    rep (y + 1) {
        ans += x + 1 - mp[cnt[m - i]];
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
