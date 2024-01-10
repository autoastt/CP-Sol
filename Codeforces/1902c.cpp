#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;
int a[N];

void solve() {
    ll n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    if(n == 1){
        cout << "1\n";
        return;
    }
    ll d = gcd(a[n-1]-a[0], a[n-1]-a[1]);
    for(int i = 2; i < n-1; i++){
        d = gcd(a[n-1]-a[i], d);
    }
    for(int i = 0; i < n; i++) ans += (a[n-1]-a[i])/d;
    for(int i = 1; i <= n; i++){
        if(i == n){
            ans += n;
            break;
        }
        if(a[n-i-1] != a[n-1]-d*i){
            ans += i;
            break;
        }
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