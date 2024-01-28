#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;

ll m[N];

void solve() {
    ll n, f, a, b;
    int now = 0;
    cin >> n >> f >> a >> b;
    for(int i = 0; i < n; i++) cin >> m[i];
    for(int i = 0; i < n; i++){
        f -= min(1ll * a * (m[i] - now), b);
        if(f <= 0) return void(cout << "NO\n");
        now = m[i];
    }
    cout << "yes\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}