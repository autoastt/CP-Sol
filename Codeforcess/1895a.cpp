#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    if(x > y) {cout << x << "\n"; return;}
    if(x + k >= y) cout << y << "\n";
    else cout << y+y-x-k << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}