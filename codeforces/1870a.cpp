#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    if(x < k-1 || n < k){
        cout << "-1\n";
        return;
    }
    int ans = k*(k-1)/2;
    if(x != k) ans += (n-k)*x;
    else ans += (n-k) * (k-1);
    cout << ans << "\n";
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