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

int dx[] = {0, 0, -1 ,1}, dy[] = {1, -1, 0, 0};
vector<string> a;

bool dfs(int x, int y1, int y2, int d) {
    int xx = x + dx[d];
    if (a[xx][y1] == '.' && a[xx][y2] == '.') return true;
    else if (a[xx][y1] == '[') return dfs(xx, y1, y2, d);
    else if (a[xx][y1] == ']' && a[xx][y2] == '.') return dfs(xx, y1 - 1, y1, d);
    else if (a[xx][y1] == '.' && a[xx][y2] == '[') return dfs(xx, y2, y2 + 1, d);
    else if (a[xx][y1] == ']' && a[xx][y2] == '[') return dfs(xx, y1 - 1, y1, d) && dfs(xx, y2, y2 + 1, d);
    return false;
}

bool mv2(int xx, int yy, int d) {
    int tx1 = xx, ty1, tx2 = xx, ty2;
    if (a[xx][yy] == '[') ty1 = yy, ty2 = yy + 1;
    else ty1 = yy - 1, ty2 = yy;
    tx1 += dx[d], ty1 += dy[d];
    tx2 += dx[d], ty2 += dy[d];
    if (a[tx1][ty1] == '[') mv2(tx1, ty1, d);
    else if (a[tx1][ty1] == ']' && a[tx2][ty2] == '.') mv2(tx1, ty1, d);
    else if (a[tx1][ty1] == '.' && a[tx2][ty2] == '[') mv2(tx2, ty2, d);
    else if (a[tx1][ty1] == ']' && a[tx2][ty2] == '[') {
        if (dfs(tx1, ty1 - 1, ty1, d) && dfs(tx2, ty2, ty2 + 1, d)) {
            mv2(tx1, ty1, d);
            mv2(tx2, ty2, d);
        }
    }
    if (a[tx1][ty1] == '.' && a[tx2][ty2] == '.') {
        swap(a[tx1][ty1], a[tx1 -= dx[d]][ty1 -= dy[d]]);
        swap(a[tx2][ty2], a[tx2 -= dx[d]][ty2 -= dy[d]]);
        return true;
    }
    return false;
}

void solve() {
    string s;
    while (getline(cin, s)) {
        if (s == "exit") break;
        string t = "";
        for (auto i : s) {
            if (i == '@') t += "@.";
            else if (i == '#') t += "##";
            else if (i == '.') t += "..";
            else t += "[]";
        }
        a.pb(t);
    }
    int n = sz(a), m = sz(a[0]), x, y;
    rep (i, n) rep (j, m) if (a[i][j] == '@') x = i, y = j;
    auto mv1 = [&](int xx, int yy, int d) {
        int tx = xx, ty = yy;
        while (a[tx][ty] == '[' || a[tx][ty] == ']') ty += dy[d];
        if (a[tx][ty] != '.') return false;
        while (ty != yy) swap(a[tx][ty], a[tx][ty - dy[d]]), ty -= dy[d];
        return true;
    };
    while (getline(cin, s)) {
        for (auto c : s) {
            int d, xx, yy;
            if (c == '>') d = 0;
            else if (c == '<') d = 1;
            else if (c == '^') d = 2;
            else d = 3;
            xx = x + dx[d];
            yy = y + dy[d];
            if (a[xx][yy] == '.') swap(a[xx][yy], a[x][y]), x = xx, y = yy;
            else if (a[xx][yy] == '[' || a[xx][yy] == ']') {
                bool can;
                if (d < 2) can = mv1(xx, yy, d);
                else can = mv2(xx, yy, d);
                if (can) swap(a[xx][yy], a[x][y]), x = xx, y = yy;
            }
        }
    }
    ll ans = 0;
    rep (i, n) rep (j, m) if (a[i][j] == '[') ans += 100 * i + j;
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
