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

map<string, int> mp;
map<int, string> rmp;
set<int> adj[N];
set<string> sans;
int ans;

void bronkerbosch(set<int> r, set<int> p, set<int> x) {
    if (p.empty() && x.empty()) {
        if (ans < sz(r)) {
            ans = sz(r);
            sans.clear();
            for (auto i : r) sans.insert(rmp[i]);
        }
        return;
    }
    auto tmp = p;
    for (auto v : tmp) {
        set<int> rr, pp, xx;
        for (auto u : adj[v]) {
            for (auto up : p) if (up == u) pp.insert(u);
            for (auto ux : x) if (ux == u) xx.insert(u);
        }
        rr = r;
        rr.insert(v);
        bronkerbosch(rr, pp, xx);
        p.erase(v);
        x.insert(v);
    }
}

void solve() {
    string s;
    int n = 0;
    while (getline(cin, s)) {
        string u = s.substr(0, 2);
        string v = s.substr(3, 2);
        if (mp.find(u) == mp.end()) mp[u] = n++;
        if (mp.find(v) == mp.end()) mp[v] = n++;
        int x = mp[u], y = mp[v];
        rmp[x] = u;
        rmp[y] = v;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    set<int> r, p, x;
    rep (n) p.insert(i);
    bronkerbosch(r, p, x);
    cout << ans << NL;
    for (auto i : sans) cout << i << ",";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
