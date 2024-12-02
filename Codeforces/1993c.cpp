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

const bool CASES = true;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

void solve() {
    ll n, k;
    cin >> n >> k;
    ll mx = 0, kk = 2 * k;
    vll cnt(kk + 5, 0);
    rep (n) {
        ll x; cin >> x;
        mx = max(mx, x);
        cnt[x % kk]++;
        ll y = (x + k) % kk;
        if (y < x % kk) cnt[0]++;
        cnt[y]--;
    }
    ll ans = INT_MAX;
    if (cnt[0] == n) {
        if (mx % kk == 0) ans = min(ans, mx);
        else if (mx % kk < kk) ans = min(ans, mx + kk - (mx % kk));
        else ans = min(ans, mx + 2 * kk - (mx % kk));
    }
    rep (i, 1, kk) {
        cnt[i] += cnt[i-1];
        if (cnt[i] == n) {
            if (mx % kk == i) ans = min(ans, mx);
            else if (mx % kk < i) ans = min(ans, mx + i - (mx % kk));
            else ans = min(ans, mx + kk + i - (mx % kk));
        }
    }
    if (ans == INT_MAX) cout << -1 << "\n";
    else cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
