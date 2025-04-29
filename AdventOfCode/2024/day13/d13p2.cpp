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
    string a, b, c, tmp;
    ll ans = 0;
    while (getline(cin, a)) {
        getline(cin, b);
        getline(cin, c);
        getline(cin, tmp);
        pll aa, bb, cc;
        string now = "";
        for (auto i : a) {
            if (i == ',') aa.first = stoll(now), now = "";
            if (i >= '0' && i <= '9') now += i;
        }
        aa.second = stoll(now);
        now = "";
        for (auto i : b) {
            if (i == ',') bb.first = stoll(now), now = "";
            if (i >= '0' && i <= '9') now += i;
        }
        bb.second = stoll(now);
        now = "";
        for (auto i : c) {
            if (i == ',') cc.first = stoll(now), now = "";
            if (i >= '0' && i <= '9') now += i;
        }
        cc.second = stoll(now);
        ll k = 1e13;
        ll c1 = cc.first * bb.second - cc.second * bb.first + k * (bb.second - bb.first);
        ll c2 = aa.first * bb.second - aa.second * bb.first;
        if (c1 % c2) continue;
        ll x = c1 / c2;
        ll c3 = k + cc.second - aa.second * x;
        if (c3 % bb.second) continue;
        ll y = c3 / bb.second;
        ans += 3 * x + y;
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
