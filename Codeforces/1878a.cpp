#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, k;
    bool ans = false;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x == k) ans = true;
    }
    cout << (ans ? "yes\n" : "no\n");
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}