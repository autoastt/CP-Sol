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

int a[N], b[N], c[N], d[N];

void solve() {
    int n;
    cin >> n;
    int cnt = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        c[i] = a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        d[i] = b[i];
        mp[b[i]] = i;
    }
    sort(c, c + n);
    sort(d, d + n);
    for (int i = 0; i < n; i++) if (c[i] != d[i]) return void(cout << "NO\n");
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) continue;
        int tmp = mp[a[i]];
        swap(b[i], b[tmp]);
        mp[b[tmp]] = tmp;
        mp[b[i]] = i;
        cnt++;
    }
    if (cnt & 1) cout << "NO\n";
    else cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
