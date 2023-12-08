#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    string s;
    cin >> s;
    for(int i = 1; i <= 8; i++){
        if(i == s[1]-'0') continue;
        cout << s[0] << i << "\n";
    }
    for(int i = 'a'; i <= 'h'; i++){
        if(i == s[0]) continue;
        cout << char(i) << s[1] << "\n";
    }
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