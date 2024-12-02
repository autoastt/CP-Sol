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
#define rrep0(a) for (int i = a; i > 0; i--)
#define rrep1(i, a) for (int i = a; i > 0; i--)
#define rrep2(i, a, b) for (int i = a; i >= b; i--)
#define rrep3(i, a, b, c) for (int i = a; i >= b; i -= c)

const bool CASES = false;
const int N = 1e6 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

map<ll, int> dp[65];

int grundy(int x, ll st) {
    if (x == 0 || st == 0) return 0;
    if (dp[x].count(st)) return dp[x][st];
    set<int> s;
    rep (x) if ((1ll << i) & st) s.insert(grundy(x - i - 1, st ^ (1ll << i)));
    int mex = 0;
    while (true) {
        if (!s.count(mex)) return dp[x][st] = mex;
        mex++;
    }
    return 0;
}

void solve() {
    int n, ans = 0;
    cin >> n;
    rep (i, 1, 60) grundy(i, (1ll << i) - 1);
    rep (n) {
        int x;
        cin >> x;
        ans ^= dp[x][(1ll << x) - 1];
    }
    cout << (!ans ? "YES" : "NO");
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
