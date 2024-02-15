#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;

ll a[N];

void solve() {
  ll n, x, y;
  ll ans = 0;
  cin >> n >> x >> y;
  map<pair<ll, ll>, ll> mp;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    mp[make_pair(a[i] % y, a[i] % x)]++;
  }
  for(auto [p, cnt] : mp){
    // cout << p.first << " " << p.second << " " << cnt << "\n";
    if(p.second > x / 2) continue;
    ll k = mp[make_pair(p.first, x - p.second)];
    if((x % 2 == 0 && p.second == x / 2) || p.second == 0) ans += (cnt) * (cnt-1) / 2;
    else ans += k * cnt;
  }
  cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
