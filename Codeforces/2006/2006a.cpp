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

vi adj[N];
string a;
int cnt, cnt0, cnt1, cnt2;

void dfs(int u, int p) {
    bool found = false;
    for (auto v : adj[u]) if (v != p) {
        dfs(v, u);
        found = true;
    }
    if (!found) {
        if (a[u] == '?') cnt++;
        else if (a[u] == '0') cnt0++;
        else cnt1++;
    }
    else cnt2 += u != 1 && a[u] == '?';
}

void solve() {
    int n;
    cin >> n;
    rep (n + 1) adj[i].clear();
    rep (n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    cin >> a;
    a = " " + a;
    cnt = cnt0 = cnt1 = cnt2 = 0;
    dfs(1, 0);
    if (a[1] == '0') {
        cout << cnt1 + (cnt + 1) / 2 << NL;
    }
    else if (a[1] == '1') {
        cout << cnt0 + (cnt + 1) / 2 << NL;
    }
    else {
        if (cnt0 != cnt1) cout << max(cnt0, cnt1) + cnt / 2 << NL;
        else cout << max(cnt0, cnt1) + (cnt + (cnt2 & 1)) / 2 << NL;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
