#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+5;
ll a[N], p[N];

void solve() {
    int n, q;
    ll ans[2] = {0};
    string s;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        p[i] = p[i-1] ^ a[i];
    }
    cin >> s;
    for(int i = 0; i < n; i++){
        ans[s[i]-'0'] ^= a[i+1];
        // cout << ans[0] << " " << ans[1] << "\n";
    }
    cin >> q;
    while(q--){
        int k;
        cin >> k;
        if(k == 1){
            int l, r;
            cin >> l >> r;
            ans[0] ^= p[r]^p[l-1];
            ans[1] ^= p[r]^p[l-1];
        }
        else{
            int kk;
            cin >> kk;
            cout << ans[kk] << " ";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
        cout << "\n";
    }
}