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
    string s;
    vector<string> a;
    map<char, vector<pii>> mp;
    while (getline(cin, s)) {
        a.pb(s);
    }
    int n = sz(a), m = sz(a[0]);
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    rep (i, n) rep (j, m) if (a[i][j] != '.') mp[a[i][j]].pb({i, j});
    for (auto [c, v] : mp) {
        for (auto [x, y] : v) {
            for (auto [xx, yy] : v) {
                if (x == xx && y == yy) continue;
                int dx = abs(x - xx), dy = abs(y - yy);
                int nx = -1, ny = -1, nxx = -1, nyy = -1;
                if (x <= xx && y <= yy) nx = x - dx, ny = y - dy, nxx = xx + dx, nyy = yy + dy;
                else if (x <= xx && y > yy) nx = x - dx, ny = y + dy, nxx = xx + dx, nyy = yy - dy;
                else if (x > xx && y <= yy)  nx = x + dx, ny = y - dy, nxx = xx - dx, nyy = yy + dy;
                else  nx = x + dx, ny = y + dy, nxx = xx - dx, nyy = yy - dy;
                if (nx < n && nx >= 0 && ny < m && ny >= 0) vis[nx][ny] = 1;
                if (nxx < n && nxx >= 0 && nyy < m && nyy >= 0) vis[nxx][nyy] = 1;
            }
        }
    }
    int ans = 0;
    rep (i, n) rep (j, m) ans += vis[i][j];
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
