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
const ll LLINF = 2e18;

void solve() {
    int n;
    cin >> n;
    vll a(n), b;
    rep (n) cin >> a[i];
    b = a;
    sort(all(a));
    rep (n / 2) {
        ll sum = a[i] + a[n - i - 1];
        a[i] = sum / 2;
        a[n - i - 1] = (sum + 1) / 2;
    }
    ll mx = -LLINF, mn = LLINF, now = 0;
    rep (n) {
        if (b[i] == a[i]) continue;
        else if (b[i] > a[i]) {
            now -= b[i] - a[i];
            if (now > 0) break;
            b[i] = a[i];
        }
        else {
            now -= b[i] - a[i];
            if (now > 0) break;
            b[i] = a[i];
        }
    }
    rep (n) mx = max(mx, b[i]), mn = min(mn, b[i]);
    cout << mx - mn << NL;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
