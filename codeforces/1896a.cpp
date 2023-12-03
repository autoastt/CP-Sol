#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 15;

void solve() {
    int n, yes = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if(i == 1 && x == 1) yes = 1;
    }
    cout << (yes ? "YES" : "NO") << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}