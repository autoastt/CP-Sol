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
#define rrep0(a) for (int i = a - 1; i >= 0; i--)
#define rrep1(i, a) for (int i = a - 1; i >= 0; i--)
#define rrep2(i, a, b) for (int i = a; i >= b; i--)
#define rrep3(i, a, b, c) for (int i = a; i >= b; i -= c)
#define NL '\n'
#define S ' '

void yn(bool x);

const bool CASES = true;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

// BG, BR, BY, GR, GY, or RY

map<string, int> mp = {
    {"BG", 0}, {"BR", 1}, {"BY", 2}, {"GR", 3}, {"GY", 4}, {"RY", 5}
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<string> s(n + 1);
    vi pos[6];
    rep (i, 1, n) {
        cin >> s[i];
        pos[mp[s[i]]].pb(i);
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (y < x) swap(x, y);

        if (s[x][0] == s[y][0] || s[x][0] == s[y][1]) {
            cout << y - x << NL;
            continue;
        }
        if (s[x][1] == s[y][0] || s[x][1] == s[y][1]) {
            cout << y - x << NL;
            continue;
        }

        int px = mp[s[x]], py = mp[s[y]], ans = 1e9;
        rep (6) {
            if (i == px || i == py) continue;
            if (!sz(pos[i])) continue;
            int p = lb(all(pos[i]), x) - pos[i].begin(), l = -1, r = -1;

            if (p < pos[i].size()) r = pos[i][p];
            if (p > 0) l = pos[i][p-1];

            if (r > y) ans = min(ans, r - x + (r - y));
            else if (r > x) ans = min(ans, y - x);
            if (l > 0 && l < x) ans = min(ans, x - l + (y - l));
        }
        cout << (ans == 1e9 ? -1 : ans) << NL;
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

void yn(bool x) {
    cout << (x ? "YES" : "NO") << NL;
}
