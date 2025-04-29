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
    ll n, k, q, m;
    cin >> n >> k >> q;
    vector<vll> a(k + 1, vll(n + 1));
    rep (i, 1, n) rep (j, 1, k) cin >> a[j][i], a[j][i] |= a[j][i - 1];
    // rep (i, 1, k) rep (j, 1, n) cout << a[i][j] << " \n"[j == n];
    while (q--) {
        ll left = 1, right = n;
        cin >> m;
        rep (m) {
            ll r, c;
            char o;
            cin >> r >> o >> c;
            if (o == '>') {
                ll x = ub(a[r].begin() + 1, a[r].end(), c) - a[r].begin();
                left = max(left, x);
            }
            else {
                ll x = lb(a[r].begin() + 1, a[r].end(), c) - a[r].begin() - 1;
                right = min(right, x);
            }
        }
        if (left > right) cout << -1 << NL;
        else cout << left << NL;
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
