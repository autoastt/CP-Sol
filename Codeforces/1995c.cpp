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

ll a[N];

void solve() {
    ll n;
    cin >> n;
    ll e = 0, cnt = 0;
    bool no = false;
    rep (i, n) cin >> a[i];
    rep (i, 1, n-1) {
        if (a[i-1] == a[i]) cnt += e;
        else if (a[i-1] < a[i]) {
            if (a[i] == 1) {
                no = true;
                break;
            }
            ll x = 0, tmp = a[i-1] * a[i-1];
            while (tmp > 1 && tmp <= a[i]) tmp *= tmp, x++;
            e = max(1ll * 0, e-x);
            cnt += e;
        }
        else {
            if (a[i] == 1) {
                no = true;
                break;
            }
            ll x = 0, tmp = a[i];
            while (a[i-1] > tmp) tmp *= tmp, x++;
            e += x;
            cnt += e;
        }
    }
    if (no) cout << -1 << "\n";
    else cout << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
