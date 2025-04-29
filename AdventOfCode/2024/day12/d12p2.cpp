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
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

void solve() {
    string s;
    vector<string> a;
    while (getline(cin, s)) {
        a.pb(s);
    }
    int n = sz(a), m = sz(a[0]);
    ll ans = 0;
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    auto bfs = [&](int sx, int sy) {
        queue<pii> q;
        q.push({sx, sy});
        vis[sx][sy] = 1;
        int p = 0, area = 0;
        set<int> h[200], v[200];
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            area++;
            h[x].insert(y);
            h[x + 1].insert(y);
            v[y].insert(x);
            v[y + 1].insert(x);
            rep (4) {
                int xx = x + dx[i], yy = y + dy[i];
                if (xx >= n || xx < 0 || yy >= m || yy < 0 || a[xx][yy] != a[sx][sy]) continue;
                if (i == 0) v[y + 1].erase(x);
                else if (i == 1) h[x + 1].erase(y);
                else if (i == 2) v[y].erase(x);
                else h[x].erase(y);
                if (!vis[xx][yy]) {
                    vis[xx][yy] = 1;
                    q.push({xx, yy});
                }
            }
        }
        rep (n + 1) {
            int pre = -INF;
            for (auto j : h[i]) {
                if (j != pre + 1) p++;
                else if (a[i][pre] == a[sx][sy] ^ a[i][j] == a[sx][sy]) p++;
                pre = j;
            }
        }
        rep (m + 1) {
            int pre = -INF;
            for (auto j : v[i]) {
                if (j != pre + 1) p++;
                else if (a[pre][i] == a[sx][sy] ^ a[j][i] == a[sx][sy]) p++;
                pre = j;
            }
        }
        // cout << sx << " " << sy << " " << a[sx][sy] << " " << p << " " << area << NL;
        return p * area;
    };
    rep (i, n) {
        rep (j, m) {
            if (!vis[i][j]) ans += bfs(i, j);
        }
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
