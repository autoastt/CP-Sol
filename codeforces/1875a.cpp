#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3+5;
int x[N];

void solve() {
    int a,b,n;
    ll ans = 0;
    cin >> a >> b >> n;
    for(int i = 0; i < n; i++){
        cin >> x[i];
        ans += min(a-1, x[i]);
    }
    cout << ans + b << "\n";

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}