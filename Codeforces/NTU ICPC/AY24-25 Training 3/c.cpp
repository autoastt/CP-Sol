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

const bool CASES = false;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    map<string, string> mp, mp2;
    vector<int> zero(m, 0), one(m, 0);
    rep (i, n) {
        string var, tmp, val;
        cin >> var >> tmp >> val;
        if (val[0] == '1' || val[0] == '0') mp[var] = mp2[var] = val;
        else {
            string b1 = val, op, b2;
            cin >> op >> b2;
            string val0 = "", val1 = "";
            rep (k, m) {
                int k1, k2, k3, k4;

                if (b1 != "?") k1 = mp[b1][k] - '0', k3 = mp2[b1][k] - '0';
                else k1 = 0, k3 = 1;
                if (b2 != "?") k2 = mp[b2][k] - '0', k4 = mp2[b2][k] - '0';
                else k2 = 0, k4 = 1;

                if (op == "OR") {
                    val0 += to_string(k1 | k2);
                    val1 += to_string(k3 | k4);
                    zero[k] += k1 | k2;
                    one[k] += k3 | k4;
                }
                else if (op == "AND") {
                    val0 += to_string(k1 & k2);
                    val1 += to_string(k3 & k4);
                    zero[k] += k1 & k2;
                    one[k] += k3 & k4;
                }
                else {
                    val0 += to_string(k1 ^ k2);
                    val1 += to_string(k3 ^ k4);
                    zero[k] += k1 ^ k2;
                    one[k] += k3 ^ k4;
                }
            }
            mp[var] = val0;
            mp2[var] = val1;
        }
    }
    string mn = "", mx = "";
    rep (i, m) {
        if (zero[i] > one[i]) mx += '0', mn += '1';
        else if (zero[i] == one[i]) mx += '0', mn += '0';
        else mx += '1', mn += '0';
    }
    cout << mn << "\n" << mx;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
