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
    vector<string> g;
    string tmp;
    int ans = 0;
    while (getline(cin, tmp)) {
        if (tmp == "-1") break;
        g.pb(tmp);
    }
    int n = sz(g), m = sz(g[0]);
    queue<pii> q;
    rep (i, n) {
        rep (j, m) {
            if (g[i][j] != 'X') continue;
            rep (x, -1, 1) {
                rep (y, -1, 1) {
                    char now = 'X';
                    int ii = i, jj = j;
                    rep (k, 3) {
                        int xx = ii + x, yy = jj + y;
                        if (xx >= n || xx < 0 || yy >= m || yy < 0) break;
                        char nxt = g[xx][yy];
                        if (now == 'X' && nxt == 'M') now = nxt, ii = xx, jj = yy;
                        else if (now == 'M' && nxt == 'A') now = nxt, ii = xx, jj = yy;
                        else if (now == 'A' && nxt == 'S') ans++;
                        else break;
                    }
                }
            }
        }
    }
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        char now = g[x][y];
    }
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
