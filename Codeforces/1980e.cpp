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

int p_row[N], p_col[N];

void solve() {
    int n, m;
    cin >> n >> m;
    int a[n][m], b[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            p_row[a[i][j]] = i;
            p_col[a[i][j]] = j;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }
    // check row
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (p_row[b[i][j]] != p_row[b[i][j-1]])
                return void(cout << "NO\n");
        }
    }
    // check col
    for (int j = 0; j < m; j++) {
        for (int i = 1; i < n; i++) {
            if (p_col[b[i][j]] != p_col[b[i-1][j]])
                return void(cout << "NO\n");
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
