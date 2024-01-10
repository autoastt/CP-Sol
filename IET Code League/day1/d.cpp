#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;
int a[N];

void solve() {
    int n, k, yes = 0;
    cin >> n >> k;
    int cnt = 0;
    for(int i = 0; i < n; i++){ 
        cin >> a[i];
        if(a[i] % k == 0){
            if(cnt == 0) cnt = a[i];
            else cnt = gcd(a[i], cnt);
        }
        // if(a[i] == k) yes = 1;
    }
    // cout << cnt << "\n";
    cout << (cnt == k ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}