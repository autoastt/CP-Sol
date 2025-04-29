#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define pb push_back
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const bool CASES = false;
const int N = 5e3 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

// dp[i][j] = number of paths ending with a_j after i moves
ll a[N], dp[N][N], cnt[N];

// actually, no need fenwick
ll fw[N];

void update(int idx, ll x) {
    for (int i = idx; i < N; i += i & -i) fw[i] = (fw[i] + x) % M;
}

ll sum(int idx) {
    ll ret = 0;
    for (int i = idx; i > 0; i -= i & -i) ret = (ret + fw[i] + M) % M;
    return ret;
}

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[0][i] = 1;
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % M;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            cnt[i] = (cnt[i] + dp[j][i] * dp[k-j][i]) % M;
        }
        update(i, cnt[i] * a[i] % M);
    }
    while (q--) {
        ll i, x;
        cin >> i >> x;
        update(i, cnt[i] * (x - a[i]) % M);
        a[i] = x;
        cout << sum(n) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
