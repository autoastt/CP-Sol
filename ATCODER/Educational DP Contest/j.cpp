#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define GET_MACRO(_1, _2, _3, _4, NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2, rep1, rep0)(__VA_ARGS__)
#define rrep(...) GET_MACRO(__VA_ARGS__, rrep3, rrep2, rrep1, rrep0)(__VA_ARGS__)
#define rep0(a) for (int i = 0; i < a; i++)
#define rep1(i, a) for (int i = 0; i < a; i++)
#define rep2(i, a, b) for (int i = a; i <= b; i++)
#define rep3(i, a, b, c) for (int i = a; i <= b; i += c)
#define rrep0(a) for (int i = (a) - 1; i >= 0; i--)
#define rrep1(i, a) for (int i = (a) - 1; i >= 0; i--)
#define rrep2(i, a, b) for (int i = a; i >= b; i--)
#define rrep3(i, a, b, c) for (int i = a; i >= b; i -= c)
#define NL '\n'

const bool CASES = false;
const int N = 3e2 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

double dp[N][N][N];

void solve() {
    int n;
    cin >> n;
    vi a(n), cnt(4, 0);
    rep (n) cin >> a[i], cnt[a[i]]++;
    rep (k, 0, cnt[3]) {
        rep (j, 0, cnt[2] + cnt[3]) {
            rep (i, 0, cnt[1] + cnt[2] + cnt[3]) {
                double x = i + j + k;
                if (x > n) continue;
                if (x == 0) continue;
                if (i) dp[i][j][k] += 1.0 * i / n * dp[i - 1][j][k];
                if (j) dp[i][j][k] += 1.0 * j / n * dp[i + 1][j - 1][k];
                if (k) dp[i][j][k] += 1.0 * k / n * dp[i][j + 1][k - 1];
                dp[i][j][k] = (dp[i][j][k] + 1) / (1.0 * x / n);
            }
        }
    }
    cout << fixed << setprecision(12) << dp[cnt[1]][cnt[2]][cnt[3]];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
