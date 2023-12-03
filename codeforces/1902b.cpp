#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n, p, x, t;
    cin >> n >> p >> x >> t;
    ll l = 0, r = n, mid, ans;
    while(l < r){
        mid = (l+r)/2;
        ll cnt = mid * x + min((n-mid+7)/7, 2*mid) * t;
        if(cnt >= p) r = mid;
        else l = mid+1;
    }
    cout << n-r << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}