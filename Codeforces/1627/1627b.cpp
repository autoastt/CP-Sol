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

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vi> dis(n, vi(m, -1));
    queue<pii> q;
    vi v;
    v.pb(dis[n / 2][m / 2] = 0);
    if (n & 1 && m & 1) {
        q.push({n / 2, m / 2});
    }
    else if (m & 1) {
        q.push({n / 2, m / 2});
        q.push({n / 2 - 1, m / 2});
        v.pb(dis[n / 2 - 1][m / 2] = 0);
    }
    else if (n & 1) {
        q.push({n / 2, m / 2});
        q.push({n / 2, m / 2 - 1});
        v.pb(dis[n / 2][m / 2 - 1] = 0);
    }
    else {
        q.push({n / 2, m / 2});
        q.push({n / 2 - 1, m / 2});
        q.push({n / 2, m / 2 - 1});
        q.push({n / 2 - 1, m / 2 - 1});
        v.pb(dis[n / 2 - 1][m / 2] = 0);
        v.pb(dis[n / 2][m / 2 - 1] = 0);
        v.pb(dis[n / 2 - 1][m / 2 - 1] = 0);
    }
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        rep (4) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 0 || xx >= n || yy < 0 || yy >= m || dis[xx][yy] != -1) continue;
            q.push({xx, yy});
            v.pb(dis[xx][yy] = dis[x][y] + 1);
        }
    }
    sort(all(v));
    int ans = n / 2 + m / 2;
    for (auto i : v) cout << (ans + i) << ' ';
    cout << NL;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
