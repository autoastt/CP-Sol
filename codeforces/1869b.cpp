#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;
ll p[N][2], d[N][2];

void solve() {
    ll n, k, a, b, ans = 0, mna = 1e18, mnb = 1e18;
    cin >> n >> k >> a >> b;
    for(int i = 1; i <= n; i++) cin >> p[i][0] >> p[i][1];
    ans = ((a <= k && b <= k) ? 0 : abs(p[a][0] - p[b][0]) + abs(p[a][1] - p[b][1]));
    for(int i = 1; i <= k; i++){
        ll da = abs(p[a][0] - p[i][0]) + abs(p[a][1] - p[i][1]);
        ll db = abs(p[b][0] - p[i][0]) + abs(p[b][1] - p[i][1]);
        mna = min(mna, da);
        mnb = min(mnb, db);
    }
    cout << min(ans, mna + mnb) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}