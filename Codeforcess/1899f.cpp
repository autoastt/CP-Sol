#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, q;
    cin >> n >> q;
    for(int i = 1; i < n; i++) cout << i << " " << i+1  << "\n";
    int now = n-1;
    while(q--){
        int d;
        cin >> d;
        if(d == now) {cout << "-1 -1 -1\n"; continue;}
        cout << n << " " << now << " " << d << "\n";
        now = d;
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