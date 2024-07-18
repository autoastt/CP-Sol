#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define pb push_back
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
const bool CASES = false;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

int a[N], vis[N];

void solve() {
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vis[i] = false;
    }
    int parity = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        for (int j = i; !vis[j]; j = a[j]) {
            vis[j] = true;
            parity += j != i;
        }
    }
    parity %= 2;
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        parity += (r-l) * (r-l+1) / 2;
        parity %= 2;
        cout << (parity ? "odd\n" : "even\n");
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
