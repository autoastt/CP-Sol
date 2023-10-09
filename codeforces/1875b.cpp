#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n,m,k,sum1 = 0, sum2 = 0, mx2 = 0, mx1 = 0, mn1 = 1e9, mn2 = 1e9, x;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        cin >> x;
        sum1 += x;
        mx1 = max(mx1, x);
        mn1 = min(mn1, x);
    }
    for(int i = 0; i < m; i++){
        cin >> x;
        sum2 += x;
        mx2 = max(mx2, x);
        mn2 = min(mn2, x);
    }
    if(k == 1){
        cout << sum1 + max(0LL, mx2 - mn1) << "\n";
    }
    else{
        if(mx2 > mn1){
            sum1 = sum1 + mx2 - mn1;
            mx1 = max(mx1, mx2);
            mn2 = min(mn1, mn2);
            if(k % 2) cout << sum1 << "\n";
            else cout << sum1 - mx1 + mn2 << "\n";
        }
        else{
            sum1 = sum1 - mx1 + mn2;
            mn1 = min(mn1, mn2);
            mx2 = max(mx1, mx2);
            if(k % 2 == 0) cout << sum1 << "\n";
            else cout << sum1 + mx2 - mn1 << "\n";
        }
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