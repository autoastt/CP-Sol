#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int a, b;
    cin >> a >> b;
    cout << ((a + b) % 2 ? "Alice" : "Bob") << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}