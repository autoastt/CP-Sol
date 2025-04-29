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
const int N = 1e3 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

struct A {
    ll d, u;
    bool operator <(const A &o) const {
        return d > o.d;
    }
};

struct E {
    ll u, v, w;
};

vector<pll> adj[N];

void solve() {
    ll n, m, l, s, t;
    cin >> n >> m >> l >> s >> t;
    vector<E> e;
    rep (m) {
        ll u, v, w;
        cin >> u >> v >> w;
        e.pb({u, v, w});
        if (!w) continue;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    vll dis;
    auto dijk = [&]() {
        dis.assign(n + 1, LLINF);
        priority_queue<A> pq;
        pq.push({dis[s] = 0, s});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d != dis[u]) continue;
            for (auto [v, w] : adj[u])
                if (dis[v] > d + w)
                    pq.push({dis[v] = d + w, v});
        }
    };
    dijk();
    if (dis[t] < l) return void(cout << "NO");
    bool found = dis[t] == l;
    for (auto &[u, v, w] : e) {
        if (w) continue;
        w = found ? LLINF : 1;
        if (found) continue;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
        dijk();
        if (dis[t] <= l) {
            found = true;
            w = l - dis[t] + 1;
        }
    }
    if (!found) return void(cout << "NO");
    cout << "YES\n";
    for (auto [u, v, w] : e) cout << u << " " << v << " " << w << NL;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
