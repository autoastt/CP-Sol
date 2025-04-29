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
const int N = 505;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

struct A {
    int x, y, d;
    bool operator <(const A &o) const {
        return d > o.d;
    }
};

int dis[N][N], ddis[N][N], dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
bool vis[N][N];

void solve() {
    ifstream cin("d20.txt");
    string s;
    vector<string> a;
    while (getline(cin, s)) a.pb(s);
    int n = sz(a), m = sz(a[0]), sx, sy, ex, ey;
    rep (i, n) rep (j, m) {
        if (a[i][j] == 'S') ex = i, ey = j;
        else if (a[i][j] == 'E') sx = i, sy = j;
    }
    auto dijk = [&](bool st = false) {
        fill_n(dis[0], N * N, INF);
        queue<A> pq;
        queue<pii> q;
        pq.push({sx, sy, dis[sx][sy] = 0});
        int ret;
        while (!pq.empty()) {
            auto [x, y, d] = pq.front();
            pq.pop();
            if (dis[x][y] != d) continue;
            if (x == ex && y == ey) {
                q.push({x, y});
                ret = d;
                break;
            }
            rep (4) {
                int xx = x + dx[i], yy = y + dy[i];
                if (xx >= n || xx < 0 || yy >= m || yy < 0) continue;
                if (a[xx][yy] != '#' && dis[xx][yy] > d + 1) pq.push({xx, yy, dis[xx][yy] = d + 1});
            }
        }
        if (st) {
            rep (i, n) rep (j, m) ddis[i][j] = dis[i][j];
            return 0;
        }
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            vis[x][y] = true;
            rep (4) {
                int xx = x + dx[i], yy = y + dy[i];
                if (xx >= n || xx < 0 || yy >= m || yy < 0) continue;
                if (a[xx][yy] != '#' && dis[xx][yy] == dis[x][y] - 1) q.push({xx, yy});
            }
        }
        return ret;
    };
    dijk(1);
    swap(sx, ex);
    swap(sy, ey);
    dijk(0);
    int ans = 0;
    map<int, int> save;
    rep (i, n) {
        rep (j, m) {
            if (vis[i][j]) {
                rep (ii, i - 20, i + 20) {
                    rep (jj, j - 20, j + 20) {
                        int x = abs(ii - i) + abs(jj - j);
                        if (x > 20 || ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
                        if (a[ii][jj] != '#') {
                            int d = dis[i][j] + x + ddis[ii][jj];
                            if (d <= dis[ex][ey] - 100) {
                                ans++;
                            }
                        }
                    }
                }
            }
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
