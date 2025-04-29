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

void solve() {
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    vi adj[2][n + 1];
    set<pii> mark;
    set<int> can;
    rep (k, 2) {
        int m;
        cin >> m;
        rep (m) {
            int u, v;
            cin >> u >> v;
            if (u > v) swap(u, v);
            adj[k][u].pb(v);
            adj[k][v].pb(u);
            if (!k) mark.insert({u, v});
            else if (mark.count({u, v})) can.insert(u), can.insert(v);
        }
    }
    struct A {
        int d, u1, u2, odd;
        bool operator <(const A &o) const {
            return d > o.d;
        }
    };
    priority_queue<A> q;
    vector<vi> dp0(n + 1, vi(n + 1, INF));
    vector<vi> dp1(n + 1, vi(n + 1, INF));
    q.push({dp1[s1][s2] = 0, s1, s2, 1});
    while (!q.empty()) {
        auto [d, u1, u2, o] = q.top();
        q.pop();
        if (o == 0 && d != dp0[u1][u2]) continue;
        if (o == 1 && d != dp1[u1][u2]) continue;
        for (auto v1 : adj[0][u1]) {
            for (auto v2 : adj[1][u2]) {
                int x = d + abs(v1 - v2);
                if (o) {
                    if (dp0[v1][v2] > x) q.push({dp0[v1][v2] = x, v1, v2, !o});
                }
                else {
                    if (dp1[v1][v2] > x) q.push({dp1[v1][v2] = x, v1, v2, !o});
                }
            }
        }
    }
    int ans = INF;
    for (auto i : can) ans = min({ans, dp0[i][i], dp1[i][i]});
    cout << (ans == INF ? -1 : ans) << NL;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
