#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3+5;
const int M = 1e9+7;
pair<ll,ll> dp[N][N];
ll a[N];
// dp[i][j] = {max including j bloggers from i bloggers, num possible}
void solve() {
    ll n, k, mx = 0, ans = 0;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    dp[0][0] = {0, 1};
    for(int i = 1; i <= n; i++){
        dp[i][0] = {0, 1};
        for(int j = 1; j <= k; j++){
            ll now = dp[i-1][j-1].first + a[i];
            dp[i][j] = dp[i-1][j];
            if(dp[i][j].first < now){
                dp[i][j] = {now, dp[i-1][j-1].second};
            }
            else if(dp[i][j].first == now) dp[i][j].second = (dp[i][j].second + dp[i-1][j-1].second) % M;
        }
    }
    cout << dp[n][k].second << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}