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

const bool CASES = true;
const int N = 20;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

// bad[mask] = not satisfy the conditions if excluding this mask
bool bad[1 << N];

void solve() {
    int n, c, k;
    string s;
    cin >> n >> c >> k >> s;
    fill_n(bad, 1 << N, false);
    bad[1 << (s.back() - 'A')] = true;
    vector<int> cnt(c, 0);
    int mask = 0, ans = INF;
    rep (i, k) {
        int now = s[i] - 'A';
        mask |= 1 << now;
        cnt[now]++;
    }
    bad[mask] = true;

    rep (i, k, n-1) {
        int last = s[i-k] - 'A';
        int now = s[i] - 'A';
        cnt[last]--;
        if (!cnt[last]) mask ^= 1 << last;
        cnt[now]++;
        mask |= 1 << now;
        bad[mask] = true;
    }

    rep (i, 1 << c) {
        rep (j, c) {
            if (i & (1 << j)) {
                bad[i] |= bad[i ^ (1 << j)];
            }
        }
    }

    rep (i, 1 << c) {
        if (!bad[i]) ans = min(ans, c - __builtin_popcount(i));
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
