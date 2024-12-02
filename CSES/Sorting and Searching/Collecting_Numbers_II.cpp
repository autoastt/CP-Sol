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
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n + 1), pos(n + 1, INF);
    rep (i, 1, n) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int ans = 0;
    rep (i, 1, n) ans += pos[i] < pos[i - 1];
    while (m--) {
        int x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);
        int pre = 0, aft = 0, i = a[x], j = a[y];
        if (i - 1 > 0 && pos[i] < pos[i - 1]) pre++;
        if (i + 1 <= n && pos[i + 1] < pos[i]) pre++;
        if (i != j - 1 && j - 1 > 0 && pos[j] < pos[j - 1]) pre++;
        if (i != j + 1 && j + 1 <= n && pos[j + 1] < pos[j]) pre++;
        swap(pos[a[x]], pos[a[y]]);
        swap(a[x], a[y]);
        if (i - 1 > 0 && pos[i] < pos[i - 1]) aft++;
        if (i + 1 <= n && pos[i + 1] < pos[i]) aft++;
        if (i != j - 1 && j - 1 > 0 && pos[j] < pos[j - 1]) aft++;
        if (i != j + 1 && j + 1 <= n && pos[j + 1] < pos[j]) aft++;
        ans += aft - pre;
        cout << ans << NL;
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
