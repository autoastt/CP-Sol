#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n, c, s;
    cin >> n >> c >> s;
    vector<pair<ll, ll>> v;
    for(int i = 2; i <= n ; i++){
        ll x; cin >> x;
        v.push_back({i*c-x, x});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n-1; i++){
        if(s >= v[i].first){
            s += v[i].second;
        }
        else{
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}