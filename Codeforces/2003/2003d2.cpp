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

ll f[N], cnt[N];

void solve() {
    ll n, m;
    cin >> n >> m;
    rep (N) f[i] = i, cnt[i] = 0;
    ll ans = 0, mx = 0, dummy = 0;
    vector<pll> mexx;
    while (n--) {
        set<int> s;
        ll mex = 0, pre = -1, l;
        cin >> l;
        while (l--) {
            int x;
            cin >> x;
            s.insert(x);
        }
        while (mex <= *s.rbegin()) {
            if (s.count(mex)) mex++;
            else {
                if (pre == -1) pre = mex++;
                else break;
            }
        }
        if (pre == -1) pre = mex++;
        mexx.pb({pre, mex});
        cnt[pre]++;
        mx = max(mx, mex);
    }
    sort(rall(mexx));
    for (auto [i, j] : mexx) f[i] = max(f[i], f[j]);
    rep (mx + 1) {
        if (cnt[i] > 1) dummy = max(dummy, f[i]);
        else if (cnt[i] == 1) dummy = max(dummy, 1ll * i);
    }
    for (ll i = 0; i <= min(mx, m); i++) ans += max(dummy, f[i]);
    if (m > mx) ans += m * (m + 1) / 2 - mx * (mx + 1) / 2;
    cout << ans << NL;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
