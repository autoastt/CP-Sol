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
const int N = 2e3 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

ll dis[N][N][4];
bool vis[N][N];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

struct A {
    int x, y, di;
    ll d;
    bool operator <(const A &o) const {
        return d > o.d;
    }
};

void solve() {
    vector<string> a;
    string s;
    while (getline(cin, s)) a.pb(s);
    int n = sz(a), m = sz(a[0]);
    fill_n(dis[0][0], N * N * 4, LLINF);
    priority_queue<A> pq;
    rep (i, n) rep (j, m) {
        if (a[i][j] == 'S') {
            pq.push({i, j, 0, 0});
            dis[i][j][0] = 0;
        }
    }
    queue<pair<pii, int>> q;
    while (!pq.empty()) {
        auto [x, y, di, d] = pq.top();
        pq.pop();
        if (d != dis[x][y][di]) continue;
        if (a[x][y] == 'E') {
            cout << d << NL;
            vis[x][y] = true;
            q.push({{x, y}, di});
            break;
        }
        int xx = x + dx[di], yy = y + dy[di];
        if (xx >= 0 && xx < n && yy >= 0 && yy < m && a[xx][yy] != '#' && dis[xx][yy][di] > d + 1)
            pq.push({xx, yy, di, dis[xx][yy][di] = d + 1});
        for (auto i : {-1, 1}) {
            int k = (di + i + 4) % 4;
            if (dis[x][y][k] > d + 1000)
                pq.push({x, y, k, dis[x][y][k] = d + 1000});
        }
    }
    int ans = 0;
    while (!q.empty()) {
        auto [c, di] = q.front();
        auto [x, y] = c;
        q.pop();
        ll mn = LLINF;
        rep (4) mn = min(mn, dis[x][y][i]);
        int xx = x - dx[di], yy = y - dy[di];
        if (xx >= 0 && xx < n && yy >= 0 && yy < m && dis[xx][yy][di] < dis[x][y][di])
            q.push({{xx, yy}, di}), vis[xx][yy] = true;
        rep (4) if (dis[x][y][i] == mn && i != di) q.push({{x, y}, i});
    }
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
