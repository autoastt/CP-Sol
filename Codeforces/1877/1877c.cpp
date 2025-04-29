#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if(k == 1) cout << "1\n";
    else if(k == 2){
        if(m <= n){
            cout << m << "\n";
            return;
        }
        cout << n + m/n - 1 << "\n";
    }
    else if(k == 3){
        if(m <= n){
            cout << "0\n"; return;
        }
        cout << m - (n + m/n - 1) << "\n";
    }
    else{ cout << "0\n"; return; }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}