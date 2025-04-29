#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+5;
ll a[N], b[N];

void solve() {
    ll n, p;
    cin >> n >> p;
    vector<pair<ll,ll>> v;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        int b;
        cin >> b;
        v.push_back({b,a[i]});
    }
    sort(v.begin(), v.end());
    ll cnt = 1, idx = 0, ans = p;
    while(cnt < n){
        if(v[idx].first > p) break;
        if(cnt + v[idx].second >= n) ans += v[idx].first * (n-cnt);
        else ans += v[idx].first * v[idx].second;
        cnt += v[idx].second;
        idx++;
    }
    cout << ans + max(0LL, n-cnt) * p << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}