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
const int N = 1e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

int t[N][26], node;
bool l[N], w[N];

void add(string s) {
    int u = 0;
    for (auto i : s) {
        if (t[u][i - 'a'] == 0) t[u][i - 'a'] = ++node;
        u = t[u][i - 'a'];
    }
}

void dfs(int u) {
    bool ww = 1, ll = 1, leaf = 1;
    rep (26) {
        if (t[u][i] == 0) continue;
        int v = t[u][i];
        dfs(v);
        ww &= w[v];
        ll &= l[v];
        leaf = 0;
    }
    if (leaf) {
        w[u] = 0;
        l[u] = 1;
        return;
    }
    w[u] = !ww;
    l[u] = !ll;
}

void solve() {
    int n, k;
    cin >> n >> k;
    rep (n) {
        string s;
        cin >> s;
        add(s);
    }
    dfs(0);
    bool ww = w[0], ll = l[0];
    if (ww && ll) cout << "First";
    else if (ww) cout << (k & 1 ? "First" : "Second");
    else cout << "Second";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
