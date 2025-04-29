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
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

void solve() {
    int n;
    cin >> n;
    vi h(n), w(n), ans(n, -1);
    vector<pii> vh, vw;
    rep (n) {
        cin >> h[i] >> w[i];
        vh.pb({h[i], i});
        vw.pb({w[i], i});
    }
    sort(all(vh));
    sort(all(vw));
    vector<pii> mnw(n + 1, {INF, -1}), mnh(n + 1, {INF, -1});
    int ph = n, pw = n;
    rep (n) {
        auto [x, j] = vh[i];
        auto [y, k] = vw[i];
        if (i) {
            mnw[i] = mnw[i - 1];
            mnh[i] = mnh[i - 1];
        }
        if (mnw[i].first > w[j]) mnw[i] = {w[j], j};
        if (mnh[i].first > h[k]) mnh[i] = {h[k], k};

    }
    rep (n) {
        int j = lb(all(vh), make_pair(h[i], 0)) - vh.begin() - 1;
        int k = lb(all(vw), make_pair(h[i], 0)) - vw.begin() - 1;
        if (j != -1 && mnw[j].first < w[i]) ans[i] = mnw[j].second + 1;
        else if (k != -1 && mnh[k].first < w[i]) ans[i] = mnh[k].second + 1;
    }
    for (auto i : ans) cout << i << " ";
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
