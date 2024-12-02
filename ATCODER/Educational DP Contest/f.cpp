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
const int N = 3e3 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

struct A {
    int x, i, j;
};

A dp[N][N];

void solve() {
    string s, t;
    cin >> s >> t;
    int n = sz(s), m = sz(t);
    rep (i, n + 1) dp[i][0] = {0, -1, -1};
    rep (j, m + 1) dp[0][j] = {0, -1, -1};
    rep (i, 1, n) {
        rep (j, 1, m) {
            if (dp[i - 1][j].x >= dp[i][j - 1].x) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = dp[i][j - 1];
            if (s[i - 1] == t[j - 1]) {
                if (dp[i - 1][j - 1].x + 1 > dp[i][j].x) {
                    dp[i][j] = {dp[i - 1][j - 1].x + 1, i - 1, j - 1};
                }
            }
        }
    }
    string ans = "";
    int x = dp[n][m].i, y = dp[n][m].j;
    while (y >= 0) {
        ans = t[y] + ans;
        int tmp = x;
        x = dp[x][y].i;
        y = dp[tmp][y].j;
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
