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

int p[N], s[N], ans;

int fp(int u) {
    return p[u] = u == p[u] ? u : fp(p[u]);
}

void com(int u, int v) {
    u = fp(u);
    v = fp(v);
    if (u == v) return;
    if (s[u] < s[v]) swap(u, v);
    p[v] = u;
    s[u] += s[v];
    ans--;
}

void solve() {
    int n, m;
    cin >> n >> m;
    ans = n;
    rep (i, 1, n) {
        p[i] = i;
        s[i] = 1;
    }
    vector<pii> v[15][15];
    rep (m) {
        int a, d, k;
        cin >> a >> d >> k;
        v[d][a % d].pb({a, k});
    }
    rep (d, 1, 10) {
        rep (i, d) {
            sort(all(v[d][i]));
            int pre = i;
            for (auto [a, k] : v[d][i]) {
                int tmp = a + k * d;
                if (pre > a) k -= (pre - a) / d, a = pre;
                int b = a + d;
                while (k > 0) {
                    com(a, b);
                    b += d;
                    k--;
                }
                pre = max(pre, tmp);
            }
        }
    }
    cout << ans << NL;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
