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

const bool CASES = true;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

int a[N], cnt[N][32], nl[N], nr[N];
ll sum[N], x[N];

void solve() {
    int n, q;
    cin >> n >> q;
    rep (i, 1, n) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        x[i] = x[i - 1] ^ a[i];
        rep (j, 32) cnt[i][j] = cnt[i - 1][j] + (a[i] >> j & 1);
    }
    rep (i, 1, n) {
        if (a[i - 1] == 0) nr[i] = nr[i - 1];
        else nr[i] = i - 1;
    }
    a[n + 1] = n + 1;
    rrep (i, n, 1) {
        if (a[i + 1] == 0) nl[i] = nl[i + 1];
        else nl[i] = i + 1;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        ll now = sum[r] - sum[l - 1] - (x[r] ^ x[l - 1]);
        if (l == r) {
            cout << l << " " << r << NL;
            continue;
        }
        if (now == 0) {
            cout << l << " " << l << NL;
            continue;
        }
        int xl = l, xr = r, len = r - l + 1;
        int tl = l;
        rep (i, 32) {
            int tr = r;
            rep (j, 32) {
                ll tmp = sum[tr] - sum[tl - 1] - (x[tr] ^ x[tl - 1]);
                if (tmp == now && tr - tl + 1 < len) {
                    xl = tl, xr = tr;
                    len = tr - tl + 1;
                }
                tr = nr[tr];
                if (tl > tr) break;
            }
            tl = nl[tl];
            if (tl > r) break;
        }
        cout << xl << " " << xr << NL;
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
