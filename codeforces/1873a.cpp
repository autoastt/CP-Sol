#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 0; i < 3; i++) if(s[i] != 'a'+i) cnt++;
    if(cnt == 2 || cnt == 0) cout << "Yes\n";
    else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}