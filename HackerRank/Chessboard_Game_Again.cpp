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

int g[20][20], dx[] = {-2, -2, 1, -1}, dy[] = {1, -1, -2, -2};

int cal(int x, int y) {
    if (x <= 2 && y <= 2) return 0;
    if (g[x][y]) return g[x][y];
    set<int> s;
    rep (4) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx > 0 && xx <= 15 && yy > 0 && yy <= 15) s.insert(cal(xx, yy));
    }
    int mex = 0;
    while (1) {
        if (!s.count(mex)) break;
        mex++;
    }
    return g[x][y] = mex;
}

void solve() {
    int k, ans = 0;
    cin >> k;
    rep (k) {
        int x, y;
        cin >> x >> y;
        ans ^= cal(x, y);
    }
    cout << (ans ? "First\n" : "Second\n");
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
