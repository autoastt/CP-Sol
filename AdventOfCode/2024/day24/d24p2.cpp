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
int v[N], idx[N];
vi q;

struct A {
    string x, y, z, op;
};
vector<A> g;

void print(int i) {
    auto [x, y, z, op] = g[i];
    cout << x << " " << op << " " << y << " " << z << " " << v[mp[z]] << NL;
    auto xx = idx[mp[x]];
    auto yy = idx[mp[y]];
    for (auto j : {xx, yy}) {
        auto k = g[j];
        if (k.x[0] == 'x' || k.x[0] == 'y') continue;
        // print(j);
    }
}

void solve() {
    string s;
    int now = 0;
    ll bx = 0, by = 0;
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
        v[now] = s.back() - '0';
        if (v[now++]) {
            if (t[0] == 'x') bx += 1ll << stoi(t.substr(1, 2));
            else by += 1ll << stoi(t.substr(1, 2));
        }
    }
    while (getline(cin, s)) {
        string x = s.substr(0, 3);
        string op = "";
        int i = 4;
        while (s[i] != ' ') op += s[i++];
        i++;
        string y = s.substr(i, 3);
        string z = s.substr(i + 7, 3);
        if (z == "z12") z = "fgc";
        else if (z == "fgc") z = "z12";
        else if (z == "z29") z = "mtj";
        else if (z == "mtj") z = "z29";
        else if (z == "vvm") z = "z33";
        else if (z == "z33") z = "vvm";
        else if (z == "z34") z = "z35";
        else if (z == "z35") z = "z34";
        g.pb({x, y, z, op});
    }
    int n = sz(g);
    vector<bool> vis(n, false);
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
            idx[now] = i;
            v[now++] = zz;
            vis[i] = true;
            cnt++;
            if (z[0] == 'z') {
                Z[stoi(z.substr(1, 2))] = zz;
            }
        }
        if (!cnt) break;
    }
    auto tmpx = g[idx[mp["dtp"]]];
    auto tmpy = g[idx[mp["hdp"]]];
    // for (auto [x, y, z, op] : {tmpx, tmpy}) cout << x << " " << op << " " << y << " " << z << " " << v[mp[z]] << NL;
    ll ans = 0;
    for (int i = 0; i < sz(Z); i++) ans += (Z[i] ? 1ll << i : 0);
    cout << ans << NL;
    ll bz = bx + by;
    ll w = (ans ^ bz);
    cout << w << NL;
    rep (n) {
        auto [x, y, z, op] = g[i];
        if (z[0] != 'z') continue;
        int k = stoi(z.substr(1, 2));
        if ((bz >> k & 1) ^ v[mp[z]]) {
            q.pb(i);
            // cout << x << " " << v[mp[x]] << " " << op << " " << y << " " << v[mp[y]] << " " << z << " " << v[mp[z]] << NL;
            print(i);
            cout << NL;
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
