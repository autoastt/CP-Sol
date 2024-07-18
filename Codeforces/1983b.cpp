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

int a[505][505], b[505][505];
string s[505];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) a[i][j] = s[i][j] - '0';
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) b[i][j] = s[i][j] - '0';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == b[i][j]) continue;
            if (i == n-1 || j == m-1) {
                if (a[i][j] != b[i][j]) return void(cout << "NO\n");
            }
            if ((a[i][j] == 1 && b[i][j] == 2) || (a[i][j] == 0 && b[i][j] == 1) || (a[i][j] == 2 && b[i][j] == 0)) {
                a[i][j] = (a[i][j] + 1) % 3;
                a[i+1][j+1] = (a[i+1][j+1] + 1) % 3;
                a[i][j+1] = (a[i][j+1] + 2) % 3;
                a[i+1][j] = (a[i+1][j] + 2) % 3;
            }
            else {
                a[i][j] = (a[i][j] + 2) % 3;
                a[i+1][j+1] = (a[i+1][j+1] + 2) % 3;
                a[i][j+1] = (a[i][j+1] + 1) % 3;
                a[i+1][j] = (a[i+1][j] + 1) % 3;
            }
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
