#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    string a, b;
    cin >> a >> b;
    for(int i = 1; i < a.size(); i++){
        if(a[i-1] == '0' && a[i] == '1' && b[i-1] == '0' && b[i] == '1'){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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