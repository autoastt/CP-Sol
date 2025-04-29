#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define pb push_back
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const bool CASES = true;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 1, p; j < a[i]; j++) cin >> p;
    }
    sort(rall(a));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 20; j >= 0; j--) {
            int x = a[i] & (1 << j);
            if (!x) continue;
            if (ans & (1 << j)) ans |= (1 << j) - 1;
            else ans |= 1 << j;
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
