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
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;
 
int trie[N][26], nnode, dis[N][26], mxd[N][26];
vi adj[N];
bool stop[N], vis[N];
 
void add(string s) {
    int u = 0;
    for (auto i : s) {
        if (trie[u][i - 'a'] == 0) trie[u][i - 'a'] = ++nnode;
        u = trie[u][i - 'a'];
    }
    stop[u] = true;
}
 
vector<char> ret;
vector<vector<char>> ans(26);

void dfs0(int u) {
    rep (26) {
        int v = trie[u][i];
        if (v) {
            dfs0(v);
            mxd[u][i] = *max_element(mxd[v], mxd[v] + 26) + 1;
        }
    }
}

void dfs1(int u, int now = -1) {
    vis[u] = true;
    if (stop[u]) {
        ans[now].pb('P');
    }
    vector<pii> tmp;
    rep (26) {
        if (mxd[u][i]) tmp.pb({mxd[u][i], i});
    }
    sort(all(tmp));
    for (auto [d, i] : tmp) {
        int v = trie[u][i];
        if (!u) now = i;
        if (!vis[v]) {
            ans[now].pb('a' + i);
            dfs1(v, now);
            ans[now].pb('-');
        }
    }
}
 
void solve() {
    int n;
    cin >> n;
    rep (n) {
        string x;
        cin >> x;
        add(x);
    }
    dfs0(0);
    dfs1(0);
    sort(all(ans), [](vector<char> a, vector<char> b) {
        int aa = 0, bb = 0;
        while (sz(a) && a.back() == '-') a.pop_back(), aa++;
        while (sz(b) && b.back() == '-') b.pop_back(), bb++;
        return aa < bb;
    });
    rep (26) {
        rep (j, sz(ans[i])) ret.pb(ans[i][j]);
    }
    while (ret.back() == '-') ret.pop_back();
    cout << sz(ret) << NL;
    for (auto i : ret) cout << i << NL;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
