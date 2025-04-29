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
const int N = 5000 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

ll p[N] = {1};
ll ncr[N][N];

ll pow(int n) {
    if (p[n]) return p[n];
    ll ret = 1, pp = 2;
    while (n) {
        if (n & 1) ret = (ret * pp) % M;
        pp = (pp * pp) % M;
        n /= 2;
    }
    return p[n] = ret;
}

void cal() {
    ncr[0][0] = ncr[1][0] = ncr[1][1] = 1;
    rep (i, 2, N - 5) {
        ncr[i][0] = ncr[i][i] = 1;
        rep (j, 1, i-1) ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j]) % M;
    }
}

void solve() {
    int n;
    cin >> n;
    ll ans = 1;
    rep (i, 1, n) {
        if (i == n) ans += 2 * n + 1;
        else rep (j, 0, i) {
            ll l = ncr[min(n, i+j)][j];
            ll r = ncr[max(0, n-i-1-j)][i-j];
            ll x = 1ll * (i + 1 + j) * l % M * r % M;
            ans = (ans + x) % M;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    cal();
    while (t--) {
        solve();
    }
}
