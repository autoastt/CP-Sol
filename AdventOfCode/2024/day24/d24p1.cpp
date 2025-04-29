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

map<string, int> mp;
map<int, string> rmp;
int v[N];

struct A {
    string x, y, z, op;
};
vector<A> g;

void solve() {
    string s;
    int now = 0;
    while (getline(cin, s)) {
        if (sz(s) <= 2) break;
        string t = "";
        for (auto i : s) {
            if (i == ':') {
                mp[t] = now;
                rmp[now] = t;
                break;
            }
            t += i;
        }
        v[now++] = s.back() - '0';
    }
    while (getline(cin, s)) {
        string x = s.substr(0, 3);
        string op = "";
        int i = 4;
        while (s[i] != ' ') op += s[i++];
        i++;
        string y = s.substr(i, 3);
        string z = s.substr(i + 7, 3);
        g.pb({x, y, z, op});
    }
    int n = sz(g);
    vector<bool> vis(n, false);
    cout << n << NL;
    vi Z(50);
    while (true) {
        int cnt = 0;
        rep (n) {
            if (vis[i]) continue;
            auto [x, y, z, op] = g[i];
            if (mp.find(x) == mp.end() || mp.find(y) == mp.end()) continue;
            int xx = v[mp[x]];
            int yy = v[mp[y]];
            int zz;
            if (op == "AND") zz = xx & yy;
            else if (op == "XOR") zz = xx ^ yy;
            else zz = xx | yy;
            mp[z] = now;
            rmp[now] = z;
            v[now++] = zz;
            vis[i] = true;
            cnt++;
            if (z[0] == 'z') {
                Z[stoi(z.substr(1, 2))] = zz;
            }
        }
        if (!cnt) break;
    }
    ll ans = 0;
    for (int i = 0; i < sz(Z); i++) ans += (Z[i] ? 1ll << i : 0);
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
