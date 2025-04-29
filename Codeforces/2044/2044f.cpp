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

const bool CASES = false;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vll a(n + 1), b(m + 1);
    ll suma = 0, sumb = 0;
    unordered_map<ll, bool> ma, mb;
    rep (i, 1, n) cin >> a[i], suma += a[i], ma[a[i]] = true;
    rep (i, 1, m) cin >> b[i], sumb += b[i], mb[b[i]] = true;
    while (q--) {
        ll x;
        cin >> x;
        ll y = abs(x);
        bool can = false;
        for (ll i = 1; i * i <= y; i++) {
            if (y % i) continue;
            ll j = x / i;
            can |= (ma[suma - i] && mb[sumb - j]) || (ma[suma - j] && mb[sumb - i]);
            i = -i, j = -j;
            can |= (ma[suma - i] && mb[sumb - j]) || (ma[suma - j] && mb[sumb - i]);
            i = -i;
            if (can) break;
        }
        cout << (can ? "YES" : "NO") << NL;
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
