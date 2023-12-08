#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;

ll a[N], b[N];

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    ll l = 0, r = 1e9, mid;
    while(l < r){
        mid = (l+r)/2;
        ll now = 0, low = 0, up = 0;
        bool yes = true;
        for(int i = 1; i <= n; i++){
            low = max(low-mid, a[i]);
            up = min(up+mid, b[i]);
            if(up < low || low > b[i] || up < a[i]){
                yes = false;
                break;
            }
        }
        if(yes) r = mid;
        else l = mid+1;
    }
    cout << r << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}