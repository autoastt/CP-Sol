#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, mnA = 1e9, mxB = 0;
    string s;
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        if(s[i] == 'A') mnA = min(mnA, i);
        else mxB = max(mxB, i);
    }
    cout << max(0, mxB-mnA) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}