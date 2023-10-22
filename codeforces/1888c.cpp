#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;
ll a[N];
void solve() {
    ll n, cnt = 0; 
    cin >> n;
    map<ll,ll> m, mr;   
    vector<ll> v;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        a[i] = x;
        if(m[x] >= 1){
            cnt += n-i-1;
            v.push_back(i);
        }
        m[x]++;
    }
    for(int i = n-1; i > 0; i--){
        ll x = a[i];
        if(mr[x] >= 1){ 
            cnt += i;
            ll idx = upper_bound(v.begin(), v.end(), i) - v.begin();
            if(idx == v.size()) continue;
            cnt -= v.size()-idx;
        }
        mr[x]++;
    }
    for(auto [x, i] : m){
        if(i > 1) cnt += i;
    }
    ll ans = n*(n+1)/2 - cnt; 
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