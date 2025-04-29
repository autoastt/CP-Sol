#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define pb push_back
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
const bool CASES = true;
const int N = 3e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

int a[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int cnt = 0;
    vector<bool> yes(n+1, false);
    auto hill = [&](int i) {
        if (i == 1 || i == n) return false;
        if (a[i-1] < a[i] && a[i] > a[i+1]) return true;
        return false;
    };
    auto valley = [&](int i) {
        if (i == 1 || i == n) return false;
        if (a[i-1] > a[i] && a[i] < a[i+1]) return true;
        return false;
    };
    for (int i = 2; i < n; i++) {
        if (hill(i) || valley(i)) {
            yes[i] = true;
            cnt++;
        }
    }
    int rem = 0;
    for (int i = 1; i <= n; i++) {
        int aa = a[i], tmp;
        a[i] = a[i-1];
        tmp = yes[i-1] + yes[i] + yes[i+1];
        for (int j = -1; j <= 1; j++) {
            if (hill(i+j) || valley(i+j)) tmp--;
        }
        rem = max(rem, tmp);
        a[i] = a[i+1];
        tmp = yes[i-1] + yes[i] + yes[i+1];
        for (int j = -1; j <= 1; j++) {
            if (hill(i+j) || valley(i+j)) tmp--;
        }
        rem = max(rem, tmp);
        a[i] = aa;
    }
    cout << cnt - rem << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
