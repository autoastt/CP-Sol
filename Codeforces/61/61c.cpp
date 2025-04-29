#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
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

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 mt64(chrono::steady_clock::now().time_since_epoch().count());

const bool CASES = false;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

void solve() {
    int a;
    string b, c;
    cin >> a >> b >> c;
    reverse(all(c));
    ll x = 0, now = 1;
    rep (sz(c)) {
        if (c[i] <= '9' && c[i] >= '0') {
            x += (c[i] - '0') * now;
        }
        else {
            x += (c[i] - 'A' + 10) * now;
        }
        now *= a;
    }
    string ans = "";
    if (b == "R") {
        while (x >= 1000) ans += 'M', x -= 1000;
        if (x >= 900) ans += "CM", x -= 900;
        while (x >= 500) ans += 'D', x -= 500;
        if (x >= 400) ans += "CD", x -= 400;
        while (x >= 100) ans += 'C', x -= 100;
        if (x >= 90) ans += "XC", x -= 90;
        while (x >= 50) ans += 'L', x -= 50;
        if (x >= 40) ans += "XL", x -= 40;
        while (x >= 10) ans += 'X', x-= 10;
        if (x >= 9) ans += "IX", x -= 9;
        while (x >= 5) ans += 'V', x -= 5;
        if (x >= 4) ans += "IV", x -= 4;
        while (x >= 1) ans += 'I', x -= 1;
    }
    else {
        int bb = stoi(b);
        if (!x) return void(cout << 0);
        while (x) {
            int k = x % bb;
            char c;
            if (k < 10) c = k + '0';
            else c = k + 'A' - 10;
            ans += c;
            x /= bb;
        }
        reverse(all(ans));
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
