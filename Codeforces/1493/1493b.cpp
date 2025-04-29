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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

const bool CASES = true;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

vi r = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};

void solve() {
    int h, m;
    cin >> h >> m;
    string s;
    cin >> s;
    string ss = s;
    rep (h * m) {
        int h1 = s[0] - '0', h2 = s[1] - '0';
        int m1 = s[3] - '0', m2 = s[4] - '0';
        int rh1 = r[m2], rh2 = r[m1], rm1 = r[h2], rm2 = r[h1];
        if (rh1 != -1 && rh2 != -1 && rm1 != -1 && rm2 != -1) {
            int hh = rh1 * 10 + rh2;
            int mm = rm1 * 10 + rm2;
            if (hh < h && mm < m) return void(cout << s << NL);
        }
        int hh = h1 * 10 + h2;
        int mm = m1 * 10 + m2 + 1;
        if (mm == m) mm = 0, hh++;
        if (hh == h) hh = 0;
        h1 = hh / 10;
        h2 = hh % 10;
        m1 = mm / 10;
        m2 = mm % 10;
        s = to_string(h1) + to_string(h2) + ':' + to_string(m1) + to_string(m2);
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
