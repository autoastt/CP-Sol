#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;
ll a[N];

void solve() {
    int n;
    ll ans = 0, x = 0;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    for(int i = 0, j = n-1; i <= j; ){
        if(i == j){
            if(a[i] == 1) ans++;
            else ans += (a[i]-x)/2+1+((a[i]+x)%2);
            break;
        }
        if(x + a[i] < a[j]){
            x += a[i];
            ans += a[i];
            i++;
        }
        else{
            ans += a[j] - x + 1;
            a[i] -= a[j] - x;
            if(a[i] == 0) i++;
            x = 0;
            j--;
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