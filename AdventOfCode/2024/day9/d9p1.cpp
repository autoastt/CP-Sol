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

void solve() {
    string s;
    cin >> s;
    deque<int> dq;
    stack<pii> st;
    int n = 0;
    for (int i = 0; i < sz(s); i++) {
        if (!(i & 1)) {
            n += s[i] - '0';
        }
    }
    vll v(n + 1, -1);
    ll ans = 0;
    int j = 0, cnt = 0;
    for (int i = 0; i < sz(s); i++) {
        if (!(i & 1)) {
            int k = s[i] - '0';
            while (k && j < n) v[j++] = cnt, k--;
            if (k > 0) st.push({k, cnt});
            cnt++;
        }
        else j += s[i] - '0';
    }
    j = 0;
    while (!st.empty()) {
        auto [k, x] = st.top();
        st.pop();
        while (k--) {
            while (v[j] != -1) j++;
            v[j++] = x;
        }
    }
    rep (n) ans += v[i] * i;
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
