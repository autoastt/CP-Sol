#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    string a, b, c;
    cin >> a >> b >> c;
    bool same = false, same2 = false;
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]){
            same |= (a[i] != c[i] && b[i] != c[i]);
        }
        else{
            same |= a[i] != c[i];
        }
    }
    cout << (same ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}