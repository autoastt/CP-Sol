#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n; cin >> n;
    vector<int> v(2*n);
    for(int i = 0; i < 2*n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    cout << v[n-1] - v[0] + v[2*n-1] - v[n] << "\n";
    for(int i = 0; i < n; i++){
        cout << v[i] << " " << v[i+n] << "\n";
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