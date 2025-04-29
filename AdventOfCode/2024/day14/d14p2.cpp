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

struct A {
    ll x, y, dx, dy;
};

void solve() {
    string s;
    int n = 101, m = 103;
    // int n = 11, m = 7;
    vector<A> v;
    while (getline(cin, s)) {
        if (s == "exit") break;
        ll x, y, dx, dy;
        string now = "";
        for (auto i : s) {
            if (i == ',') dx = stoi(now), now = "";
            else if (i >= '0' && i <= '9') now += i;
            else if (i == '-') now += i;
            else if (i == ' ') x = dx, y = stoi(now), now = "";
        }
        dy = stoi(now);
        v.pb({x, y, dx, dy});
    }
    string tmp;
    int t = 0;
    while (t < 7568) {
        for (auto &[x, y, dx, dy] : v) {
            x += dx;
            y += dy;
            if (x < 0) x += n;
            else if (x >= n) x -= n;
            if (y < 0) y += m;
            else if (y >= m) y -= m;
        }
        t++;
    }
    while (getline(cin, tmp)) {
        cout << ++t << NL;
        vector<vll> a(n, vll(m, 0));
        for (auto &[x, y, dx, dy] : v) {
            x += dx;
            y += dy;
            if (x < 0) x += n;
            else if (x >= n) x -= n;
            if (y < 0) y += m;
            else if (y >= m) y -= m;
            a[x][y]++;
        }
        rep (j, m) {
            rrep (i, n) {
                cout << (a[i][j] ? "1" : " ");
            }
            cout << NL;
        }
        cout << "-----------------------------------------------------------------------------------------------" << NL;
    }
    cout << -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
