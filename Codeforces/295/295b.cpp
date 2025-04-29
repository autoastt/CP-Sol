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
mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

const bool CASES = false;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<vll> dp(n + 1, vll(n + 1, LLINF));
    vector<vll> a(n + 1, vll(n + 1, 0));
    rep (i, n) rep (j, n) cin >> a[i][j];
    vll X(n), p;
    rep (n) cin >> X[i], X[i]--;
    reverse(all(X));
    vector<bool> vis(n);
    for (auto x : X) {
        vis[x] = true;
        rep (i, n) if (vis[i]) dp[i][x] = min(dp[i][x], a[i][x]), dp[x][i] = min(dp[x][i], a[x][i]);
        ll ans = 0;
        rep (i, n) {
            rep (j, n) {
                if (!vis[i] || !vis[j]) continue;
                if (dp[x][i] != LLINF && dp[i][j] != LLINF && dp[x][j] > dp[x][i] + dp[i][j])
                    dp[x][j] = dp[x][i] + dp[i][j];
            }
        }
        rep (i, n) {
            rep (j, n) {
                if (!vis[i] || !vis[j]) continue;
                if (dp[i][j] != LLINF && dp[j][x] != LLINF && dp[i][x] > dp[i][j] + dp[j][x])
                    dp[i][x] = dp[i][j] + dp[j][x];
            }
        }
        rep (i, n) {
            rep (j, n) {
                if (!vis[i] || !vis[j]) continue;
                if (dp[i][x] != LLINF && dp[x][j] != LLINF && dp[i][j] > dp[i][x] + dp[x][j])
                    dp[i][j] = dp[i][x] + dp[x][j];
            }
        }
        rep (i, n) rep (j, n) {
            if (!vis[i] || !vis[j]) continue; 
            ans += dp[i][j];
        }
        p.pb(ans);
    }
    reverse(all(p));
    for (auto i : p) cout << i << " ";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}

