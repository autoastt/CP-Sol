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
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

ll fastpow(ll x, ll n) {
    ll ret = 1;
    while (n) {
        if (n & 1) ret = ret * x % M;
        x = x * x % M;
        n >>= 1;
    }
    return ret;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    if (n == 1) return void(cout << k);
    else if (n == 2) return void(cout << 1ll * k * k % M);
    ll x = n / 3;
    if (n % 3 == 0) cout << 1ll * k * fastpow(k - 1, x - 1) % M;
    else if (n % 3 == 1) {
        ll cnt = k * fastpow(k - 1, x) % M;
        cout << 1ll * cnt * (x + 1) % M;
    }
    else {
        ll cnt1 = k * fastpow(k - 1, x + 1) % M;
        cnt1 = (x + 2) * (x + 1) / 2 % M * cnt1 % M;
        ll cnt2 = k * fastpow(k - 1, x) % M;
        cnt2 = (x + 1) * cnt2 % M;
        cout << 1ll * (cnt1 + cnt2) % M;
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
