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
const int N = 1e3 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

char a[] = {'n', 'a', 'r', 'e', 'k'};
set<char> ss = {'n', 'a', 'r', 'e', 'k'};

void solve() {
    ll n, m;
    cin >> n >> m;
    vll dp(5, -LLINF);
    dp[4] = 0;
    rep (n) {
        string s;
        cin >> s;
        vll ndp = dp;
        ll cnt = 0;
        for (auto j : s) cnt += ss.count(j);
        rep (j, 5) {
            ll score = 0, now = (j + 1) % 5;
            for (auto k : s) {
                if (k == a[now]) now++;
                if (now == 5) score++, now = 0;
            }
            now = (now + 4) % 5;
            if (dp[j] != -LLINF) ndp[now] = max(ndp[now], dp[j] + 1ll * 10 * score - cnt);
        }
        dp = ndp;
    }
    cout << *max_element(all(dp)) << NL;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
