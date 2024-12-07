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
    string s = "", t;
    bool mul = true;
    ll ans = 0;
    while (getline(cin, t)) {
        if (t == "exit") break;
        s += t;
    }
    for (int i = 0; i < sz(s);) {
        string now = s.substr(i, 3);
        string chk1 = s.substr(i, 4);
        string chk2 = s.substr(i, 7);
        if (chk1 == "do()") mul = true;
        if (chk2 == "don't()") mul = false;
        // cout << now << NL;
        if (now == "mul" && mul) {
            i += 3;
            if (s[i] == '(') {
                bool can = true;
                string a = "", b = "";
                i++;
                while (s[i] != ',') {
                    if (s[i] > '9' || s[i] < '0') {
                        can = false;
                        break;
                    }
                    a += s[i++];
                }
                if (!can) continue;
                // cout << "hi2 " << a << "\n";
                i++;
                while (s[i] != ')') {
                    if (s[i] > '9' || s[i] < '0') {
                        can = false;
                        break;
                    }
                    b += s[i++];
                }
                if (!can) continue;
                // cout << a << " " << b << NL;
                ans += 1ll * stoi(a) * stoi(b);
            }
        }
        else i++;
    }
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
