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

ll a[N], dp[2 * N];

void solve() {
    int n, k;
    cin >> n >> k;
    fill_n(dp, 2 * N, 0);
    multiset<ll> cnt;
    ll mx = 0, mxsum = 0, ans = INF;
    rep (i, 1, n) cin >> a[i];
    rep (i, 1, n/2) {
        ll sum = a[i] + a[n-i+1];
        ll l = min(a[i], a[n-i+1]) + 1;
        ll r = max(a[i], a[n-i+1]) + k;
        cnt.insert(sum);
        dp[l]++;
        dp[r+1]--;
    }
    rep (i, 2, 2*k) {
        dp[i] += dp[i-1];
        ll one = dp[i] - cnt.count(i);
        ll two = n/2 - dp[i];
        ans = min(ans, one + 2 * two);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
