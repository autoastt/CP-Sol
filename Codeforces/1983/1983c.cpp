#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define pb push_back
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
const bool CASES = true;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

ll vv[3][N];

vector<vector<int>> v = {
    {0, 1, 2}, {0, 2, 1},
    {1, 2, 0}, {1, 0, 2},
    {2, 1, 0}, {2, 0, 1}
};

void solve() {
    int n;
    cin >> n;
    for (int j = 0; j < 3; j++)
        for (int i = 1; i <= n; i++) {
            cin >> vv[j][i];
            vv[j][i] += vv[j][i-1];
        }
    ll tot = (vv[0][n] + 2) / 3;
    auto fn = [&](ll a[], ll b[], ll c[], int i) {
        int x = v[i][0], y = v[i][1], z = v[i][2];
        int pos_st = lower_bound(a, a + n, tot) - a;
        ll st = a[pos_st];

        int pos_nd = lower_bound(b, b + n, tot + b[pos_st]) - b;
        ll nd = b[pos_nd] - b[pos_st];

        ll rd = c[n] - c[pos_nd];

        vector<pii> ans(3);
        if(st >= tot && nd >= tot && rd >= tot) {
            ans[x] = {1, pos_st};
            ans[y] = {pos_st+1, pos_nd};
            ans[z] = {pos_nd+1, n};
            for (int i = 0; i < 3; i++)
                cout << ans[i].first << " " << ans[i].second << " ";
            cout << "\n";
            return true;
        }
        return false;
    };
    for (int i = 0; i < sz(v); i++) {
        int x = v[i][0], y = v[i][1], z = v[i][2];
        if (fn(vv[x], vv[y], vv[z], i)) return;
    }
    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
