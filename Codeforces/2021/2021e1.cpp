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
    int n, m, p;
    cin >> n >> m >> p;
    vll x(p), ans(n + 1, 0);
    rep (p) cin >> x[i];
    vector<vll> d(n + 1, vll(n + 1, LLINF));
    rep (m) {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = d[v][u] = w;
    }
    rep (k, 1, n) {
        rep (i, 1, n) {
            rep (j, 1, n) {
                d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
            }
        }
    }
    ll sum = 0;
    vll mark;
    rrep (k, p - 1, 1) {
        ll mn = LLINF, use = -1;
        cout << k << NL;
        rep (i, p) {
            ll now = LLINF;
            for (auto j : mark) {
                rep (x, p)
            }
            // if (x[i] == -1) continue;
            // rep (j, p) {
            //     if (i == j || x[j] == -1) continue;
            //     now = min(now, d[x[i]][x[j]]);
            // }
            cout << i << " " << now << NL;
            if (now < mn) mn = now, use = i;
        }
        cout << k << " use = " << x[use] << NL;
        sum += mn;
        ans[k] = sum;
        x[use] = -1;
    }
    rep (i, 1, n) cout << ans[i] << " ";
    cout << NL;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
