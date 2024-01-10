#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 998244353;
const int N = 1e5+5;
ll a[N], mx[N], power[N], ans;
vector<pair<ll,ll>> v;

void solve() {
    ll n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = n; i > 0; i--){
        mx[i] = a[i];
        for(int j = 2; j*i <= n; j++){
            mx[i] = max(mx[i], mx[i*j]);
        }
        v.push_back({mx[i], i});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        auto [x, num] = v[i];
        ans = (ans + mx[num] * power[i]) % M;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    // cin >> t;
    power[0] = 1;
    power[1] = 2;
    for(int i = 2; i < 1e5; i++){
        power[i] = (power[i-1] * 2) % M;
    }
    while(t--) {
        solve();
    }
}