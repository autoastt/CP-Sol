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
    ll a, b, c;
    string s;
    cin >> a >> b >> c >> s;
    int i = 0;
    auto combo = [&](ll x) {
        if (x <= 3) return x;
        else if (x == 4) return a;
        else if (x == 5) return b;
        else if (x == 6) return c;
    };
    while (i < sz(s)) {
        if (s[i] == '0') {
            int k = combo(s[i + 2] - '0');
            a /= (1ll << k);
            i += 4;
        }
        else if (s[i] == '1') {
            int k = s[i + 2] - '0';
            b ^= k;
            i += 4;
        }
        else if (s[i] == '2') {
            int k = combo(s[i + 2] - '0');
            b = k % 8;
            i += 4;
        }
        else if (s[i] == '3') {
            if (a == 0) i += 4;
            else i = 2 * (s[i + 2] - '0');
        }
        else if (s[i] == '4') {
            b = b ^ c;
            i += 4;
        }
        else if (s[i] == '5') {
            int k = combo(s[i + 2] - '0');
            cout << k % 8 << ',';
            i += 4;
        }
        else if (s[i] == '6') {
            int k = combo(s[i + 2] - '0');
            b = a / (1ll << k);
            i += 4;
        }
        else {
            int k = combo(s[i + 2] - '0');
            c = a / (1ll << k);
            i += 4;
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
