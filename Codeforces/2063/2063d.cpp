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

void solve() {
    ll n, m;
    cin >> n >> m;
    vll a(n), b(m);
    rep (n) cin >> a[i];
    rep (m) cin >> b[i];
    if (n < 2 && m < 2) return void(cout << 0 << NL);
    sort(all(a));
    sort(all(b));
    vll ans;
    ll f = 0, lx = 0, ly = 0, rx = n - 1, ry = m - 1, remx = 0, remy = 0;
    while (true) {
        ll dx = a[rx] - a[lx];
        ll dy = b[ry] - b[ly];
        if (rx - lx + 1 - remx <= 1) dx = 0;
        if (ry - ly + 1 - remy <= 1) dy = 0;
        if (dx == 0 && dy == 0) break;
        if (dx > dy) {
            f += dx;
            rx--;
            lx++;
            remy++;
        }
        else {
            f += dy;
            ry--;
            ly++;
            remx++;
        }
        ans.pb(f);
        if (rx - lx + 1 - remx == 0) {
            rx++;
            lx--;
            remy--;
            if (lx < 0 || rx >= n) break;
            f -= a[rx] - a[lx];
            if (ry - ly + 1 - remy == 0) break;
            f += b[ry--] - b[ly++];
            remx++;
        }
        else if (ry - ly + 1 - remy == 0) {
            ry++;
            ly--;
            remx--;
            if (ly < 0 || ry >= m) break;
            f -= b[ry] - b[ly];
            if (rx - lx + 1 - remx == 0) break;
            f += a[rx--] - a[lx++];
            remy++;
        }
        if (rx - lx + 1 - remx == 0 && ry - ly + 1 - remy == 0) break;
        if (lx > rx || ly > ry) break;
    }
    cout << sz(ans) << NL;
    for (auto i : ans) cout << i << " ";
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
