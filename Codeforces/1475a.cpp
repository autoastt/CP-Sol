#include<bits/stdc++.h>
using namespace std;
long long p[64];

void solve() {
    long long n; cin >> n;
    for(int i = 0, j = 0; i < 64; i++){
        if(n & p[i]) j++;
        if(j > 1){cout << "Yes\n"; return;}
    }
    cout << "No\n";
}
 
int main() {
    int t;
    cin >> t;
    p[0] = 1;
    for(int i = 1; i < 64; i++) p[i] = 2*p[i-1];
    while(t--) {
        solve();
    }
}
