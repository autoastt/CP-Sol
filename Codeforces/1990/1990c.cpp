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
#define rrep2(i, a, b) for (int i = b; i >= a; i--)
#define rrep3(i, a, b, c) for (int i = b; i >= a; i -= c)
 
const bool CASES = true;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;
 
ll a[N], b[N], c[N];
 
void solve() {
    int n;
    cin >> n;
    ll sum = 0, cnt = 1, pre = 0;
    map<int, int> mp;
    rep (i, 1, n) {
        cin >> a[i];
        mp[a[i]]++;
        if (mp[a[i]] > 1 && a[i] > b[i-1]) b[i] = a[i];
        else b[i] = b[i-1];
        sum += a[i];
    }
    rep (i, 1, n) {
        sum += b[i] + c[i-1];
        if (b[i-1] != b[i] && b[i] != b[i+1])
            b[i] = b[i-1];
        c[i] = c[i-1] + b[i];
    }
    cout << sum << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
