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

const bool CASES = false;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vll> a(n + 5, vll(m + 5, 0));
    vector<vector<char>> c(n + 5, vector<char>(m + 5, '.')), ans;
    rep (i, 1, n) {
        rep (j, 1, m) {
            cin >> c[i][j];
            a[i][j] = (c[i][j] == 'X') + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }
    ans = c;
    ll l = 0, r = min(n, m);
    while (l < r) {
        ll mid = (l + r + 1) / 2;
        vector<vll> b(n + 5, vll(m + 5, 0));
        vector<vector<char>> ret(n + 5, vector<char>(m + 5, '.'));
        rep (i, mid + 1, n - mid) rep (j, mid + 1, m - mid) {
            ll area = a[i+mid][j+mid] - a[i-mid-1][j+mid] - a[i+mid][j-mid-1] + a[i-mid-1][j-mid-1];
            if (area == (2 * mid + 1) * (2 * mid + 1)) {
                ret[i][j] = 'X';
                b[i-mid][j-mid]++;
                b[i-mid][j+mid+1]--;
                b[i+mid+1][j-mid]--;
                b[i+mid+1][j+mid+1]++;
            }
        }
        bool check = true;
        rep (i, 1, n) rep (j, 1, m) {
            b[i][j] += b[i-1][j] + b[i][j-1] - b[i-1][j-1];
            if (c[i][j] == 'X' && b[i][j] == 0) check = false;
            if (c[i][j] == '.' && b[i][j] != 0) check = false;
            if (!check) break;
        }
        if (check) l = mid, ans = ret;
        else r = mid - 1;
    }
    cout << l << "\n";
    rep (i, 1, n) {
        rep (j, 1, m) cout << ans[i][j];
        cout << "\n";
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
