#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, ans = 0;
    string s;
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        if(s[i] == '+') ans++;
        else ans--;
    }
    cout << abs(ans) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}