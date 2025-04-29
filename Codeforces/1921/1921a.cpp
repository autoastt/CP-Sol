#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int x[4], y[4];
    for(int i = 0; i < 4; i++){
        cin >> x[i] >> y[i];
    }
    int xx, yy;
    for(int i = 1; i < 4; i++){
        if(x[i] != x[i-1]) xx = abs(x[i]-x[i-1]);
        if(y[i] != y[i-1]) yy = abs(y[i]-y[i-1]);
    }
    cout << xx * yy << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}