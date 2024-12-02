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
const int N = 1e4 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

int g[N], a[N];

int f(int x, int k) {
    if (x == 0) return 0;
    if (g[x]) return g[x];
    set<int> s;
    rep (k) if (x - a[i] >= 0) s.insert(f(x - a[i], k));
    int mex = 0;
    while (true) {
        if (!s.count(mex)) break;
        mex++;
    }
    return g[x] = mex;
}

void solve() {
    int k, m;
    cin >> k;
    rep (k) cin >> a[i];
    cin >> m;
    while (m--) {
        int n, ans = 0;
        cin >> n;
        rep (n) {
            int x;
            cin >> x;
            ans ^= f(x, k);
        }
        cout << (ans ? 'W' : 'L');
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
