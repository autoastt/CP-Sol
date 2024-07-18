#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define pb push_back
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
const bool CASES = false;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

void solve() {
    int na, nb, nc;
    cin >> na >> nb >> nc;
    ll a, b, c;
    ll suma = 0, sumb = 0, sumc = 0, mna = INF, mnb = INF, mnc = INF;
    vector<ll> v;
    for (int i = 0; i < na; i++) {
        cin >> a;
        suma += a;
        mna = min(mna, a);
    }
    for (int i = 0; i < nb; i++) {
        cin >> b;
        sumb += b;
        mnb = min(mnb, b);
    }
    for (int i = 0; i < nc; i++) {
        cin >> c;
        sumc += c;
        mnc = min(mnc, c);
    }
    cout << suma + sumb + sumc - 2 * min({suma, sumb, sumc, mna + mnb + mnc - max({mna, mnb, mnc})}) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
