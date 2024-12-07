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
const ll M = 600851475143;
const int INF = 2e9;
const ll LLINF = 1e18;

bool dfs(ll x, vll v, int i) {
    if (x == 0 && i == sz(v)) return true;
    else if (i == sz(v)) return false;
    bool ret = false;
    if (x >= v[i]) ret |= dfs(x - v[i], v, i + 1);
    if (x % v[i] == 0) ret |= dfs(x / v[i], v, i + 1);
    string s = to_string(v[i]), t = to_string(x);
    bool can = sz(t) >= sz(s);
    while (sz(s)) {
        if (!can) break;
        if (s.back() != t.back()) can = false;
        s.pop_back();
        t.pop_back();
    }
    if (sz(t) == 0) t = "0";
    return ret | (can ? dfs(stoll(t), v, i + 1) : 0);
}

void solve() {
    string s;
    ll ans = 0;
    while (getline(cin, s)) {
        string t = "";
        vll v;
        int i = 0;
        while (i < sz(s)) {
            if (s[i] == ':') {
                i += 2;
                break;
            }
            t += s[i++];
        }
        ll x = stoll(t);
        t = "";
        while (i < sz(s)) {
            if (s[i] == ' ') {
                i++;
                v.pb(stoll(t));
                t = "";
            }
            else t += s[i++];
        }
        v.pb(stoll(t));
        reverse(all(v));
        if (dfs(x, v, 0)) ans += x;
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
