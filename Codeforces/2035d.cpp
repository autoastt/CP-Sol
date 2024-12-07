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

const bool CASES = true;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

ll fpow(ll x, ll k) {
    ll ret = 1;
    while (k) {
        if (k & 1) ret = ret * x % M;
        x = x * x % M;
        k >>= 1;
    }
    return ret;
}

void solve() {
    int n;
    cin >> n;
    deque<pll> dq;
    ll ans = 0;
    rep (n) {
        ll x;
        cin >> x;
        ll k = 0, tmp = x;
        while (x % 2 == 0) {
            k++;
            x >>= 1;
        }
        while (!dq.empty() && dq.back().first <= tmp) {
            auto [y, kk] = dq.back();
            dq.pop_back();
            k += kk;
            if (tmp * fpow(2, kk) <= M) tmp *= fpow(2, kk);
            else tmp = M;
            ans = (ans + y - (y * fpow(2, kk) % M) + M) % M;
        }
        dq.pb({x, k});
        ans = (ans + x * fpow(2, k) % M + M) % M;
        cout << ans << " ";
    }
    cout << NL;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
