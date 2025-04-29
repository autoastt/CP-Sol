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

const bool CASES = false;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vll cnt(m + 1, 0), ans(q, -1);
    rep (n) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    vector<pll> qq, occ;
    rep (q) {
        ll k;
        cin >> k;
        qq.pb({k - n, i});
    }
    rep (i, 1, m) occ.pb({cnt[i], i});
    sort(all(qq));
    sort(all(occ));
    ll pre = 1, j = 0;
    ordered_set<int> s;
    rep (i, 1, m - 1) {
        ll nxt = pre + i * (occ[i].first - occ[i - 1].first);
        s.insert(occ[i - 1].second);
        while (j < q && qq[j].first < nxt) {
            ll idx = (qq[j].first - pre) % i;
            ans[qq[j].second] = *s.find_by_order(idx);
            j++;
        }
        pre = nxt;
    }
    rep (q) if (ans[qq[i].second] == -1) {
        ans[qq[i].second] = (qq[i].first - pre) % m + 1;
    }
    rep (q) cout << ans[i] << NL;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
