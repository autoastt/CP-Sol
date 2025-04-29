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
    int n;
    cin >> n;
    vector<pii> c0, c1;
    rep (i, 1, n) {
        rep (j, 1, n)
            if ((i + j) & 1) c1.pb({i, j});
            else c0.pb({i, j});
    }
    rep (n * n) {
        int x;
        cin >> x;
        if (x == 1) {
            if (sz(c1)) {
                cout << 2 << " " << c1.back().first << " " << c1.back().second << endl;
                c1.pop_back();
            }
            else {
                cout << 3 << " " << c0.back().first << " " << c0.back().second << endl;
                c0.pop_back();
            }
        }
        else if (x == 2) {
            if (sz(c0)) {
                cout << 1 << " " << c0.back().first << " " << c0.back().second << endl;
                c0.pop_back();
            }
            else {
                cout << 3 << " " << c1.back().first << " " << c1.back().second << endl;
                c1.pop_back();
            }
        }
        else {
            if (sz(c0)) {
                cout << 1 << " " << c0.back().first << " " << c0.back().second << endl;
                c0.pop_back();
            }
            else {
                cout << 2 << " " << c1.back().first << " " << c1.back().second << endl;
                c1.pop_back();
            }
        }
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
