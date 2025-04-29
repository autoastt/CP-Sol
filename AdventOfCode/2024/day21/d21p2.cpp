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

map<ll, ll> mp;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
char d[] = {'v', '^', '>', '<'};

string a[4] = {
    "789",
    "456",
    "123",
    ".0A"
};
string b[2] = {
    ".^A",
    "<v>"
};

ll hash(int sx, int sy, int ex, int ey, int r) {
    ll x = sx;
    x *= 4;
    x += sy;
    x *= 4;
    x += ex;
    x *= 4;
    x += ey;
    x *= 30;
    x += r;
    return x;
}

struct A {
    int x, y;
    string k;
};

ll f2(int x)

ll f1(int sx, int sy, int ex, int ey) {
    queue<A> q;
    q.push({sx, sy, ""});
    ll ret = LLINF;
    while (!q.empty()) {
        auto [x, y, s] = q.front();
        q.pop();
        if (x == ex && y == ey) {
            
        }
    }
}

string f2(string s) {
    string ret = "";
    int j = 4, k;
    for (auto i : s) {
        if (i == 'A') k = 4;
        else if (i == 'v') k = 0;
        else if (i == '^') k = 1;
        else if (i == '>') k = 2;
        else k = 3;
        ret += di[j][k] + "A";
        j = k;
    }
    return ret;
}

void solve() {
    string s;
    ll ans = 0;
    auto bfs = [&](int c) {
                queue<A> q;
        q.push({p[c].first, p[c].second, -1, ""});
        mp[c][c] = "";
        while (!q.empty()) {
            auto [x, y, dd, k] = q.front();
            q.pop();
            if (dd != -1) {
                int xx = x + dx[dd];
                int yy = y + dy[dd];
                if (!(xx < 0 || xx >= 4 || yy < 0 || yy >= 3) && !(xx == 3 && yy == 0) && mp[c].find(a[xx][yy]) == mp[c].end()) {
                    mp[c][a[xx][yy]] = k + d[dd];
                    q.push({xx, yy, dd, mp[c][a[xx][yy]]});
                }
            }

            rep (4) {
                if (i == dd) continue;
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (xx < 0 || xx >= 4 || yy < 0 || yy >= 3) continue;
                if (xx == 3 && yy == 0) continue;
                if (mp[c].find(a[xx][yy]) != mp[c].end()) continue;
                mp[c][a[xx][yy]] = k + d[i];
                q.push({xx, yy, i, mp[c][a[xx][yy]]});
            }
        }
    };
    
    while (getline(cin, s)) {
        ll ret = 0;
        int x = 3, y = 2;
        for (auto c : s) {
            rep (i, 4) {
                rep (j, 3) {
                    if (a[i][j] == c) {
                        ret += f1(x, y, i, j);
                        x = i;
                        y = j;
                    }
                }
            }
        }
        cout << s << NL;
        cout << t << " " << sz(t) << NL;
        t = f2(t);
        cout << t << " " << sz(t) << NL;
        t = f2(t);
        cout << t << " " << sz(t) << NL;
        ll x = stoll(s.substr(0, 3));
        cout << sz(t) << " " << x << NL;
        ans += 1ll * sz(t) * x;
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
