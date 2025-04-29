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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 mt64(chrono::steady_clock::now().time_since_epoch().count());

const bool CASES = false;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

void solve() {
    ll n, k;
    cin >> n >> k;
    ll l = 1, r = n;
    string x;
    if (!k) {
        while (l < r) {
            ll mid = (l + r) / 2;
            cout << l << " " << mid << endl;
            cin >> x;
            if (x == "Yes") r = mid;
            else l = mid + 1;
        }
        cout << r << " " << r << endl;
        cin >> x;
        return;
    }
    auto bs = [&]() {
        while (r - l + 1 > 6 * k) {
            ll mid = (l + r) / 2;
            cout << l << " " << mid << endl;
            cin >> x;
            if (x == "Yes") l = max(1ll, l - k), r = min(n, mid + k);
            else l = max(1ll, mid - k), r = min(n, r + k);
        }
    };
    bs();
    while (1) {
        ll y = l + mt64() % (r - l + 1);
        cout << y << " " << y << endl;
        cin >> x;
        if (x == "Yes") return;
        else {
            l = max(1ll, l - k);
            r = min(n, r + k);
            bs();
        }
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
