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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const bool CASES = true;
const int N = 2e5 + 5;
const int M = 998244353;
const int INF = 2e9;
const ll LLINF = 1e18;

void solve() {
    int n;
    cin >> n;
    vi adj[n + 1], p(n + 1);
    p[1] = 1;
    rep (i, 2, n) {
        int x;
        cin >> x;
        adj[i].pb(x);
        adj[x].pb(i);
        p[i] = x;
    }
    vll dp(n + 1), cnt(n + 1);
    queue<pii> q;
    q.push({1, 0});
    ll ans = 0;
    while (!q.empty()) {
        auto [u, d] = q.front();
        q.pop();
        if (p[u] != 1) {
            dp[u] = (cnt[d - 1] - dp[p[u]] + M) % M;
            cnt[d] = (cnt[d] + dp[u]) % M;
        }
        else {
            dp[u] = 1;
            cnt[d]++;
        }
        ans = (ans + dp[u]) % M;
        for (auto v : adj[u]) {
            if (v != p[u]) {
                q.push({v, d + 1});
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
