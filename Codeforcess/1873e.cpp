#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;
ll a[N];

void solve() {
    ll n, x;
    cin >> n >> x;
    for(int i = 1; i <= n; i++) cin >> a[i];
    ll l = 1, r = 1e12, mid, ans=1;
    while(l < r){
        mid = (l+r+1)/2;
        ll cnt = 0;
        for(int i = 1; i <= n; i++) if(a[i] < mid) cnt += mid - a[i];
        if(cnt <= x) l = mid, ans = mid;
        else r = mid-1;
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