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
const int N = 1e6 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

int trie[N][26], nnode;
bool stop[N];

void add(string s) {
    int u = 0;
    for (auto i : s) {
        if (trie[u][i - 'a'] == 0) trie[u][i - 'a'] = ++nnode;
        u = trie[u][i - 'a'];
    }
    stop[u] = true;
}

void solve() {
    int n, k;
    string s;
    cin >> s >> k;
    n = sz(s);
    rep (k) {
        string x;
        cin >> x;
        add(x);
    }
    vll dp(n + 1, 0);
    dp[n] = 1;
    rrep (i, n) {
        int u = 0;
        rep (j, i, n - 1) {
            if (trie[u][s[j] - 'a'] == 0) break;
            u = trie[u][s[j] - 'a'];
            if (stop[u]) dp[i] = (dp[i] + dp[j + 1]) % M;
        }
    }
    cout << dp[0];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
