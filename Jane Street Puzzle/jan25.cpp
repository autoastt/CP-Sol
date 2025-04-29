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

vector<vll> board = {
    {-1, -1, -1, -1, -1, -1, -1, 2, -1},
    {-1, -1, -1, -1, 2, -1, -1, -1, 5},
    {-1, 2, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, 0, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, 2, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, 0, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, 2, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, 5, -1, -1}
};
ll ans = 0, p;

bool chk() {
    set<int> row[10], col[10];
    bool can = true, res = true;
    ll ret = 0, r5;
    rep (i, 9) {
        ll now = 0;
        rep (j, 9) {
            if (board[i][j] == -1) {
                res = false;
                continue;
            }
            if (row[board[i][j]].count(i)) can = false;
            if (col[board[i][j]].count(j)) can = false;
            if (!can) return false;
            now = now * 10 + board[i][j];
            row[board[i][j]].insert(i);
            col[board[i][j]].insert(j);
        }
        if (i == 4) r5 = now;
        ret = gcd(ret, now);
    }
    // cout << res << " hi\n";
    if (res) {
        if (ret > ans) p = r5;
        ans = max(ans, ret);
    }
    return can;
}


void dfs(int i, int j) {
    // cout << i << " " << j << NL;
    if (i == 8 && j == 8) {
        chk();
        return;
    }
    if (j == 9) {
        dfs(i + 1, 0);
        return;
    }
    else if (board[i][j] != -1) {
        dfs(i, j + 1);
        return;
    }
    if (!chk()) return;
    rep (x, 10) {
        board[i][j] = x;
        dfs(i, j + 1);
        board[i][j] = -1;
    }
}

void solve() {
    rep (i, 9) {
        rep (j, 9) cout << board[i][j] << " ";
        cout << NL;
    }
    dfs(0, 0);
    cout << ans << NL << p;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
