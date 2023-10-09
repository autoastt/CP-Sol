#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    int mn = 10, ans = 1, cnt = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x == 0) {cnt++; mn = 0; continue;}
        ans *= x;
        mn = min(mn, x);
    }
    if(cnt > 1) cout << "0\n";
    else if(cnt == 1) cout << ans << "\n";
    else cout << ans/mn*(mn+1) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}