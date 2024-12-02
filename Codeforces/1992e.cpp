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
#define rrep0(a) for (int i = a; i > 0; i--)
#define rrep1(i, a) for (int i = a; i > 0; i--)
#define rrep2(i, a, b) for (int i = a; i >= b; i--)
#define rrep3(i, a, b, c) for (int i = a; i >= b; i -= c)

const bool CASES = true;
const int N = 1e4;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<pii> ret;
    vi digit = {n % 10, (n / 10) % 10, (n / 100) % 10};
    int d = to_string(n).size(), x = 0;
    reverse(digit.begin(), digit.begin() + d);
    if (n == 1) rep (i, 2, N) ret.pb({i, i-1});
    else rep (i, 1, to_string(n * N).size()) {
        x = x * 10 + digit[(i - 1) % d];
        if ((x - i) % (n - d)) continue;
        int a = (x - i) / (n - d);
        int b = d * a - i;
        if (a > N || b > min(N, a * n)) continue;
        if (a == 0 || b == 0) continue;
        ret.pb({a, b});
    }
    cout << sz(ret) << "\n";
    for (auto [a, b] : ret) cout << a << " " << b << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
