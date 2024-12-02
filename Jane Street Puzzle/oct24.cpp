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
const int N = 6;
const int M = 2024;
const int MXSIM = 1e7;
const int MXPATH = 10;
const int MNANS = 8;
const int INF = 2e5;

string A[N] = {
    {"abbccc"},
    {"abbccc"},
    {"aabbcc"},
    {"aabbcc"},
    {"aaabbc"},
    {"aaabbc"},
};

int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

struct Node {
    int x, y;
    vector<vector<bool>> vis;
    vector<pii> path;

    Node(int i, int j) : x(i), y(j) {
        vis.assign(N, vector<bool>(N, 0));
        vis[i][j] = true;
        path.assign(1, {i, j});
    }
};

void solve() {
    queue<Node> q;
    vector<vector<pii>> path[2];
    auto bfs = [&](int ex, int ey, int cnt) {
        int sim = 0;
        set<vector<vector<bool>>> combi;
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            // cout << u.x << " " << u.y << " " << cnt << NL;
            if (combi.count(u.vis)) continue;
            bool can = false;
            rep (8) {
                int xx = u.x + dx[i];
                int yy = u.y + dy[i];
                if (xx < 0 || yy < 0 || xx >= N || yy >= N || u.vis[xx][yy]) continue;
                Node now = u;
                now.x = xx;
                now.y = yy;
                now.vis[xx][yy] = true;
                now.path.pb({xx, yy});
                // cout << "hi " << now.x << " " << now.y << NL;
                if (xx == ex && yy == ey && sz(now.path) > MXPATH) {
                    path[cnt].pb(now.path);
                    continue;
                }
                q.push(now);
                can = true;
            }
            if (!can) {
                combi.insert(u.vis);
            }
            if (sim++ > MXSIM) break;
        }
    };

    cout << "bfs1\n";
    Node st(0, 0);
    q.push(st);
    bfs(N - 1, N - 1, 0);
    while (!q.empty()) q.pop();
    cout << "bfs2\n";
    st = Node(N - 1, 0);
    q.push(st);
    bfs(0, N - 1, 1);
    cout << "fin " << sz(path[0]) << " " << sz(path[1]) << NL << NL;
    int found[] = {0, 0};
    auto chk = [&](vector<pii> p, int a, int b, int c) {
        int sum = 1;
        char pre = 'x';
        unordered_map<char, int> mp;
        mp['a'] = a;
        mp['b'] = b;
        mp['c'] = c;
        for (auto [i, j] : p) {
            if (A[i][j] != pre) sum *= mp[A[i][j]];
            else sum += mp[A[i][j]];
            pre = A[i][j];
            if (sum > M) break;
        }
        // cout << a << " " << b << " " << c << " " << sum << NL;
        return sum == M;
    };
    int xa = INF, xb = INF, xc = INF;
    vector<vector<pii>> xans(2);
    rep (a, 1, 50) {
        rep (b, 1, 50) {
            rep (c, 1, 50) {
                if (a == b || a == c || b == c) continue;
                if (a + b + c >= MNANS) continue;
                found[0] = found[1] = 0;
                vector<vector<pii>> ans(2);
                rep (k, 2) {
                    for (auto x : path[k]) {
                        if (chk(x, a, b, c)) {
                            found[k] = true;
                            ans[k] = x;
                            break;
                        }
                    }
                }
                if (found[0] && found[1]) {
                    if (xa + xb + xc > a + b + c) {
                        xa = a;
                        xb = b;
                        xc = c;
                        xans = ans;
                    }
                }
            }
        }
    }
    cout << xa << " " << xb << " " << xc << NL;
    rep (k, 2) {
        cout << "Path " << k << NL;
        for (auto [i, j] : xans[k]) {
            cout << char('a' + j) << 6 - i << NL;
        }
        cout << NL;
    }
}
/*
4 7 8
Path 0: a6 b4 d3 e1 c2 e3 f1
Path 1: a1 c2 e1 d3 b4 d5 f6

2 5 4
Path 0: a6 b4 d3 c5 e4 c3 d1 e3 f1
Path 1: a1 c2 e1 d3 f4 e2 c3 e4 f6

1 5 2
Path 0: a6 b4 c6 e5 c4 d6 e4 c3 d5 e3 f1
Path 1: a1 b3 c5 e6 d4 f5 d6 c4 e3 d5 f6

1,3,2,a1,b3,c1,d3,e5,c4,d6,e4,f2,d1,b2,a4,b6,d5,f6,a6,b4,c2,d4,e6,c5,b3,c1,e2,c3,d5,b6,c4,e3,f1
*/
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
