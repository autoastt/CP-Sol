#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define mp make_pair
#define pb push_back
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
const bool CASES = true;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

int a[N];

void solve() {
    fill_n(a, N, 0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 1; i <= n; i++) {
        a[i] += a[i-1];
    }
    int ans = INF;
    for (int i = 0; i <= 20; i++) {
        int ii = 1 << i;
        for (int j = 0; j <= 20; j++) {
            int jj = 1 << j;
            for (int k = 0; k <= 20; k++) {
                int kk = 1 << k;

                int pos_i = upper_bound(a, a+n+1, ii) - a - 1;
                int low = a[pos_i];

                int pos_j = upper_bound(a, a+n+1, jj + low) - a - 1;
                if(pos_i == pos_j && pos_i != n) continue;
                int mid = a[pos_j] - low;

                int high = a[n] - mid - low;
                if(high > kk) continue;
                ans = min(ans, ii + jj + kk - low - mid - high);
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
