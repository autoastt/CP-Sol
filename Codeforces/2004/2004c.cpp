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
#define S ' '

void yn(bool x);

const bool CASES = true;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

void solve() {
    ll n, k;
    cin >> n >> k;
    vll a(n);
    rep (n) cin >> a[i];
    sort(rall(a));
    vll x;
    ll sa = 0, sb = 0;
    rep (n) {
        if (i & 1) {
            sb += a[i];
            x.pb(a[i-1] - a[i]);
        }
        else sa += a[i];
    }
    rep (sz(x)) {
        if (k >= x[i]) k -= x[i], sb += x[i];
        else {
            sb += k;
            break;
        }
    }
    cout << sa - sb << NL;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}

void yn(bool x) {
    cout << (x ? "YES" : "NO") << NL;
}
