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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const bool CASES = true;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

void solve() {
    int n;
    cin >> n;
    vi a(n), z;
    rep (n) {
        cin >> a[i];
        if (!a[i]) z.pb(i);
    }
    if (sz(z) == 0) {
        cout << 1 << NL << 1 << " " << n << NL;
        return;
    }
    if (sz(z) == 1) {
        cout << 2 << NL;
        if (z[0] == 0) cout << 1 << " " << 2 << NL;
        else cout << z[0] << " " << z[0] + 1 << NL;
        cout << 1 << " " << n - 1 << NL;
        return;
    }
    int l = z[0], r = z.back();
    if (l == 0 && r == n - 1) {
        cout << 3 << NL;
        cout << 3 << " " << n << NL;
        cout << 1 << " " << 2 << NL;
        cout << 1 << " " << 2 << NL;
    }
    else if (l == 0) {
        cout << 2 << NL;
        cout << 1 << " " << r + 1 << NL;
        cout << 1 << " " << n - r << NL;
    }
    else if (r == n - 1) {
        cout << 2 << NL;
        cout << l + 1 << " " << n << NL;
        cout << 1 << " " << l + 1 << NL;
    }
    else {
        cout << 2 << NL;
        cout << l + 1 << " " << r + 1 << NL;
        cout << 1 << " " << n - (r - l) << NL;
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
