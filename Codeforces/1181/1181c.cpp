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
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    rep (n) cin >> a[i];
    vector<vi> cnt(n, vi(m));
    rep (m) {
        char c = a[0][i];
        cnt[0][i] = 1;
        int j = 1;
        while (j < n) {
            while (j < n && a[j][i] == c) {
                cnt[j][i] = cnt[j - 1][i] + 1;
                j++;
            }
            if (j < n) {
                cnt[j][i] = 1;
                c = a[j][i];
                j++;
            }
        }
    }
    ll ans = 0;
    rep (i, 2, n - 1) {
        vector<pair<char, int>> pre;
        int pj = 0;
        rep (j, m) {
            vector<pair<char, int>> v;
            int ii = i;
            while (sz(v) < 3 && ii >= 0) {
                if (sz(v) == 1 && cnt[ii][j] != cnt[i][j]) break;
                else if (sz(v) == 2 && cnt[ii][j] < cnt[i][j]) break;
                v.pb({a[ii][j], cnt[i][j]});
                ii -= cnt[ii][j];
            }
            if (sz(v) == 3) {
                if (v != pre) pre = v, pj = j;
                ans += j - pj + 1;
            }
            else pre.clear();
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
