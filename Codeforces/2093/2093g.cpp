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

const bool CASES = true;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

struct Trie {
    struct Node {
        int nxt[2] = {0, 0}, mx = -1;
    };
    vector<Node> t;
    int n;

    Trie(): t(1), n(0) {};

    void add(int x, int idx) {
        int u = 0;
        rrep (32) {
            int j = x >> i & 1;
            if (t[u].nxt[j] == 0) {
                t.emplace_back(Node());
                t[u].nxt[j] = ++n;
            }
            u = t[u].nxt[j];
            t[u].mx = max(t[u].mx, idx);
        }
    }

    int find(int x, int k) {
        int u = 0, ret = -1;
        rrep (32) {
            int xi = x >> i & 1;
            int ki = k >> i & 1;
            if (ki) {
                if (t[u].nxt[!xi]) u = t[u].nxt[!xi];
                else return ret;
            }
            else {
                if (t[u].nxt[!xi]) ret = max(ret, t[t[u].nxt[!xi]].mx);
                if (t[u].nxt[xi]) u = t[u].nxt[xi];
                else return ret;
            }
        }
        ret = max(ret, t[u].mx);
        return ret;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    Trie t;
    int ans = INF;
    rep (n) {
        int x;
        cin >> x;
        t.add(x, i);
        int j = t.find(x, k);
        if (j != -1) ans = min(ans, i - j + 1);
    }
    cout << (ans == INF ? -1 : ans) << NL;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
