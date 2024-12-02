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

const bool CASES = false;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

void solve() {
    int n, cnt = 0;
    string s;
    cin >> n >> s;
    rep (i, 1, n-2) {
        if (s[i] == s[i-1]) {
            if (s[i] == 'R') {
                if (s[i+1] == 'R' || s[i+1] == 'G') s[i] = 'B';
                else s[i] = 'G';
            }
            else if (s[i] == 'B') {
                if (s[i+1] == 'B' || s[i+1] == 'G') s[i] = 'R';
                else s[i] = 'G';
            }
            else {
                if (s[i+1] == 'G' || s[i+1] == 'R') s[i] = 'B';
                else s[i] = 'R';
            }
            cnt++;
        }
    }
    if (s[n-1] == s[n-2]) {
        if (s[n-1] == 'R') s[n-1] = 'B';
        else if (s[n-1] == 'B') s[n-1] = 'G';
        else s[n-1] = 'R';
        cnt++;
    }
    cout << cnt << '\n' << s;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
