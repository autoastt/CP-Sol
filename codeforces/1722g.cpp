#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, now = 0;
    cin >> n;
    for(int i = 1; i < n-2; i++){
        now ^= i;
    }
    if(now){
        for(int i = 0; i < n-2; i++) cout << i << " ";
        cout << (1<<30) << " " << (now^(1<<30)) << "\n";
        return;
    }
    for(int i = 1; i <= n-2; i++) cout << i << " ";
    cout << (1<<30) << " " << (now^(1<<30)^(n-2)) << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}