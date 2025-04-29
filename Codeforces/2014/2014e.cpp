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

vector<pll> adj[N];
ll dis[2][N][2];
bool horse[N];

struct A {
    ll u, d, h;
    bool operator <(const A &o) const {
        return d > o.d;
    }
};

void solve() {
    int n, m, h;
    cin >> n >> m >> h;
    rep (n + 1) adj[i].clear(), horse[i] = false;
    rep (i, 2)
        rep (j, n + 1)
            rep (k, 2)
                 dis[i][j][k] = LLINF;
    rep (h) {
        int x;
        cin >> x;
        horse[x] = true;
    }
    rep (m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    auto dijk = [&](int st, int k) {
        priority_queue<A> pq;
        pq.push({st, dis[k][st][0] = 0, 0});
        while (!pq.empty()) {
            auto [u, d, x] = pq.top();
            pq.pop();
            if (dis[k][u][x] != d) continue;
            if (!x && horse[u] && dis[k][u][1] > d) {
                pq.push({u, dis[k][u][1] = d, 1});
            }
            for (auto [v, w] : adj[u]) {
                if (dis[k][v][x] > d + (x ? w / 2 : w)) {
                    pq.push({v, dis[k][v][x] = d + (x ? w / 2 : w), x});
                }
            }
        }
    };
    dijk(1, 0);
    dijk(n, 1);
    ll ans = LLINF;
    rep (i, 1, n) {
        rep (j, 2)
            rep (k, 2)
                ans = min(ans, max(dis[0][i][j], dis[1][i][k]));
    }
    cout << (ans == LLINF ? -1 : ans) << NL;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
