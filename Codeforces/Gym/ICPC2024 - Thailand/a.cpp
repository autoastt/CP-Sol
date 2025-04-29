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

const bool CASES = false;
const int N = 1e6 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

ll p[N], q[N];

void solve() {
    int n;
    cin >> n;
    rep (n) cin >> p[i] >> q[i];
    ll k = p[0] + q[0], cnt0 = p[0], cnt1 = q[0];
    rep (i, 1, n - 1) {
        ll tmp0 = (cnt0 * p[i] % M + cnt1 * q[i] % M) % M;
        ll tmp1 = (cnt0 * q[i] % M + cnt1 * p[i] % M) % M;
        cnt0 = tmp0;
        cnt1 = tmp1;
        k = k * (p[i] + q[i] % M) % M;
    }
    ll d = gcd(k, cnt0);
    cnt0 /= d;
    k /= d;
    auto fastpow = [&](ll x, ll y) {
        ll ret = 1;
        while (y) {
            if (y & 1) ret = ret * x % M;
            x = x * x % M;
            y >>= 1;
        }
        return ret;
    };
    k = fastpow(k, M - 2);
    cnt0 = cnt0 * k % M;
    cout << cnt0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
