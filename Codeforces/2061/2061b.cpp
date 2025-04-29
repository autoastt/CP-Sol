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
    int n;
    cin >> n;
    map<int, int> mp;
    int r = -1;
    rep (n) {
        int x;
        cin >> x;
        mp[x]++;
        if (mp[x] == 2) r = max(r, x);
    }
    if (r == -1) return void(cout << -1 << NL);
    mp[r] -= 2;
    vi a;
    for (auto [x, i] : mp) rep (j, i) a.pb(x);
    int x, y, mn = INF;
    rep (i, 1, sz(a) - 1) {
        if (a[i] == r && a[i - 1] == r) continue;
        int d = a[i] - a[i - 1];
        if (d < mn) {
            mn = a[i] - a[i - 1];
            x = a[i - 1];
            y = a[i];
        }
    }
    if (mn >= 2 * r) return void(cout << -1 << NL);
    cout << r << " " << r << " " << x << " " << y << NL;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
