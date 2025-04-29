#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 998244353;
const int N = 3e5 + 5;
ll a[N];

void solve() {
    ll n, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 0; i < 30; i++){
        ll cnt[2] = {}, sum[2] = {}, now = 1<<i;
        bool cur = 0;
        cnt[0] = 1;
        for(int j = 1; j <= n; j++){
            cur ^= (a[j] & now ? 1 : 0);
            cnt[cur]++;
            sum[cur] += j;
            ans = (ans + (cnt[cur^1] * j - sum[cur^1]) % M * now) % M;
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}