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

vector<vi> l, k;

void solve() {
    string s;
    vector<string> v;
    auto ch = [&]() {
        bool chk = false;
        if (v.back() == ".....") chk = true;
        vi x(5);
        rep (j, 5) {
            int lv = 0;
            rep (i, 7) if (v[i][j] == '#') lv++;
            x[j] = lv - 1;
        }
        if (chk) l.pb(x);
        else k.pb(x);
    };
    while (getline(cin, s)) {
        if (sz(s) < 5) {
            ch();
            v.clear();
            continue;
        }
        v.pb(s);
    }
    ch();
    cout << sz(l) << " " << sz(k) << NL;
    int ans = 0;
    rep (i, sz(l)) {
        rep (j, sz(k)) {
            bool can = true;
            rep (o, 5) {
                if (l[i][o] + k[j][o] > 5) can = false;
            }
            ans += can;
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
