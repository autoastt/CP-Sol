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

int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

void solve() {
    int n = 71, m = 71;
    vector<vi> dis(100, vi(100, INF)), tmp(100, vi(100, INF));
    string s;
    vector<pii> v;
    while (getline(cin, s)) {
        string k = "";
        int x, y;
        for (auto i : s) {
            if (i == ',') x = stoi(k), k = "";
            else k += i;
        }
        y = stoi(k);
        v.pb({y, x});
    }
    for (auto [sx, sy] : v) {
        tmp[sx][sy] = -1;
        dis = tmp;
        queue<pii> q;
        dis[0][0] = 0;
        q.push({0, 0});
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            rep (4) {
                int xx = x + dx[i], yy = y + dy[i];
                if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
                if (dis[xx][yy] != -1 && dis[xx][yy] > dis[x][y] + 1) {
                    dis[xx][yy] = dis[x][y] + 1;
                    q.push({xx, yy});
                }
            }
        }
        if (dis[n - 1][m - 1] == INF) return void(cout << sy << " " << sx);
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
