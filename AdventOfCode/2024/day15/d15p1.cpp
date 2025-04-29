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

void solve() {
    string s;
    vector<string> a;
    while (getline(cin, s)) {
        if (s == "exit") break;
        a.pb(s);
    }
    int n = sz(a), m = sz(a[0]), x, y;
    rep (i, n) rep (j, m) if (a[i][j] == '@') x = i, y = j;
    auto mv = [&](int xx, int yy, int d) {
        int tx = xx, ty = yy;
        while (a[tx][ty] == 'O') tx += dx[d], ty += dy[d];
        if (a[tx][ty] != '.') return false;
        swap(a[tx][ty], a[xx][yy]);
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
            else if (a[xx][yy] == 'O') {
                if (mv(xx, yy, d)) swap(a[xx][yy], a[x][y]), x = xx, y = yy;
            }
        }
    }
    ll ans = 0;
    rep (i, n) rep (j, m) if (a[i][j] == 'O') ans += 100 * i + j;
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
