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
    stack<pll> st;
    set<pll> vv;
    ll n = 0, cnt = -1;
    for (int i = 0; i < sz(s); i++) {
        if (i & 1) {
            vv.insert({n, s[i] - '0'});
        }
        else st.push({s[i] - '0', n}), cnt++;
        n += s[i] - '0';
    }
    vll v(n + 1, -1);
    ll ans = 0;
    while (!st.empty()) {
        auto [k, i] = st.top();
        st.pop();
        auto it = vv.begin();
        while ((it->second < k || it->first > i) && it != vv.end()) it++;
        if (it == vv.end()) {
            while (k--) v[i++] = cnt;
        }
        else {
            auto [j, kk] = *it;
            int tmp = k;
            while (tmp--) v[j++] = cnt;
            vv.erase(it);
            if (kk - k > 0) vv.insert({j, kk - k});
        }
        cnt--;
    }
    rep (n) cout << v[i];
    cout << NL;
    rep (n) if (v[i] != -1) ans += 1ll * v[i] * i;
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
