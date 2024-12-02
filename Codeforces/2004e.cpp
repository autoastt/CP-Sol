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
#define rrep0(a) for (int i = a - 1; i >= 0; i--)
#define rrep1(i, a) for (int i = a - 1; i >= 0; i--)
#define rrep2(i, a, b) for (int i = a; i >= b; i--)
#define rrep3(i, a, b, c) for (int i = a; i >= b; i -= c)
#define NL '\n'
#define S ' '

void yn(bool x);

const bool CASES = true;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

map<int, int> g;
vi prime;
int mark[N];

int grundy(int x) {
    if (x % 2 == 0) return 0;
    if (x == 1) return 1;
    int p = mark[x];
    return lb(all(prime), p) - prime.begin() + 1;
}

void solve() {
    int n, ans = 0;
    cin >> n;
    rep (n) {
        int x;
        cin >> x;
        ans ^= grundy(x);
    }
    cout << (ans ? "Alice" : "Bob") << NL;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    prime.pb(2);
    for (int i = 3; i < N; i += 2) {
        if (mark[i]) continue;
        mark[i] = i;
        prime.pb(i);
        for (ll j = 1ll * i * i; j < N; j += 2 * i) if (!mark[j]) mark[j] = i;
    }
    while (t--) {
        solve();
    }
}

void yn(bool x) {
    cout << (x ? "YES" : "NO") << NL;
}
