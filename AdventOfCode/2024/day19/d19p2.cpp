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

set<string> v;
int mx = 0;

int dfs(string s, int pos) {
    if (pos == sz(s)) {
        return true;
    }
    bool ret = 0;
    string t = "";
    rep (i, pos, sz(s) - 1) {
        if (sz(t) > mx) break;
        t += s[i];
        if (v.count(t)) ret += dfs(s, i + 1);
    }
    return ret;
}

void solve() {
    ifstream Input("d19.txt");
    string s;
    getline(Input, s);
    string t = "";
    rep (sz(s)) {
        if (s[i] == ',') v.insert(t), mx = max(mx, sz(t)), t = "", i++;
        else t += s[i];
    }
    v.insert(t);
    getline(Input, s);
    // for (auto i : v) cout << i << NL;
    ll ans = 0;
    while (getline(Input, s)) {
        int n = sz(s);
        vll dp(n + 1);
        dp[0] = 1;
        rep (i, 1, n) {
            for (auto j : v) {
                if (sz(j) <= i) {
                    bool can = true;
                    rep (k, sz(j)) {
                        if (j[sz(j) - k - 1] == s[i - k - 1]) continue;
                        can = false;
                        break;
                    }
                    if (can)
                        dp[i] += dp[i - sz(j)];
                }
            }
        }
        ans += dp[n];
    }
    std::cout << ans;
    Input.close();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
