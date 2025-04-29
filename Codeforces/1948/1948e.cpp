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
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

void clique(int st, int n) {
    if (n == 1) return void(cout << st + 1 << " ");
    int mid = n / 2;
    rep (i, 1, mid) cout << mid - i + 1 + st << " ";
    rep (i, mid+1, n) cout << mid + n - i + 1 + st << " ";
}

void solve() {
    int n, k;
    cin >> n >> k;
    if (k >= n) {
        clique(0, n);
        cout << "\n";
        cout << 1 << "\n";
        rep (n) cout << 1 << " ";
        cout << "\n";
        return;
    }
    int last = n - (n % k), j = 1;
    rep (i, 0, last - 1, k) clique(i, k);
    clique(last, n % k);
    cout << "\n" << (n + k - 1) / k << "\n";
    rep (i, 1, n) cout << j << " ", j += !(i % k);
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
