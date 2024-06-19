#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+5;

ll a[N];

void solve() {
    ll n, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if(sum % n) return void(cout << "-1\n");
    sum /= n;
    vector<pair<pair<ll, ll>, ll>> ans;
    for (int i = 2; i <= n; i++) {
        if(a[i] % i) {
            ans.push_back({{1, i}, i - a[i] % i});
            a[i] += i - a[i] % i;
        }
        ans.push_back({{i, 1}, a[i] / i});
    }
    for (int i = 2; i <= n; i++) {
        ans.push_back({{1, i}, sum});
    }
    cout << ans.size() << '\n';
    for(auto [p, x] : ans){
        cout << p.first << " " << p.second << " " << x << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
