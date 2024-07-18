#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define pb push_back
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
const bool CASES = true;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

int a[N], vis[N];

void solve() {
    int n;
    cin >> n;
    auto parity = [&]() {
        int ret = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            int cnt = 0;
            for (int j = i; !vis[j]; j = a[j]) {
                vis[j] = true;
                cnt++;
            }
            ret += --cnt;
        }
        return ret % 2;
    };
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vis[i] = false;
    }
    unordered_set<int> s;
    for (int i = 1; i <= n; i++) {
        if (s.count(a[i])) return void(cout << "YES\n");
        s.insert(a[i]);
    }
    cout << (parity() ? "NO\n" : "YES\n");
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
