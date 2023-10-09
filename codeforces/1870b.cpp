#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n, m, ans1 = 0, ans2;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        ans1 ^= x;
    }
    ans2 = 0;
    for(int i = 0; i < m; i++){
        ll x;
        cin >> x;
        ans2 |= x;
    }
    // cout << "hi " << ans1 << " " << ans2 << "\n";
    if(n%2) ans2 |= ans1;
    else {
        int tmp = ans1;
        for(int i = 0;i < 32; i++){
            if((1<<i) & ans1){
                if((1<<i) & ans2) tmp ^= (1<<i);
            }
        }
        ans2 = tmp;
    }
    cout << min(ans1, ans2) << " " << max(ans1, ans2) << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}