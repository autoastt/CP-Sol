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
#define rrep0(a) for (int i = a - 1; i >= 0; i--)
#define rrep1(i, a) for (int i = a - 1; i >= 0; i--)
#define rrep2(i, a, b) for (int i = a; i >= b; i--)
#define rrep3(i, a, b, c) for (int i = a; i >= b; i -= c)
#define NL '\n'

const bool CASES = true;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    map<int, vector<int>> mp;
    rep (n) cin >> a[i];
    sort(all(a));
    rep (n) mp[a[i] % k].pb(a[i]);
    ll ans = 0, mx = 0;
    bool odd = n & 1, found = false;
    for (auto [i, v] : mp) {
        if (sz(v) & 1) {
            if (!odd || found) return void(cout << -1 << NL);
            found = true;
            if (sz(v) == 1) continue;
            vll l(sz(v), 0);
            ll mn = LLINF, r = 0;
            for (int j = 1; j < sz(v); j += 2) {
                if (j > 1) l[j] = l[j - 2];
                l[j] += (v[j] - v[j - 1]) / k;
                mn = l[j];
            }
            for (int j = sz(v) - 2; j > 0; j -= 2) {
                r += (v[j + 1] - v[j]) / k;
                ll now = r;
                if (j > 1) now += l[j - 2];
                mn = min(mn, now);
            }
            ans += mn;
        }
        else for (int j = 1; j < sz(v); j += 2) ans += (v[j] - v[j - 1]) / k;
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
