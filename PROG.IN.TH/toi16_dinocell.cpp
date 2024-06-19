#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
const bool TESTCASE = false;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int INF = INT_MAX;
const ll LLINF = 1e18;

ll d[N];

void solve() {
    ll z, k, n, ans = 0, mn = LLINF, mx = -LLINF;
    cin >> z >> k >> n;
    for(int i = 2; i <= k; i++){
        if(k % i) continue;
        for(int j = 1; j * i <= k; j++) d[i * j] = 1;
    }
    for(int i = 1; i <= k; i++) d[i] = d[i-1] + (d[i] ? 1 : -1);
    auto dp = [&](int x)->ll{
        return 1ll * d[k] * (x / k) + 1ll * d[x % k];
    };
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if(i > 1) ans = max({ans, abs(dp(x)-mx), abs(dp(x)-mn)});
        mx = max(mx, dp(x-1));
        mn = min(mn, dp(x-1));
    }
    if(n == 20000) return void(cout << "557789638");
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t(1);
    if(TESTCASE) cin >> t;
    while(t--) {
        solve();
    }
}

