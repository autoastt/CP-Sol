#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    string s;
    int n, k; 
    cin >> n >> k >> s;
    int cnt[30] = {}, odd = 0;
    for(int i = 0; i < s.size(); i++){
        cnt[s[i] - 'a']++;
    }
    for(int i = 0; i < 26; i++){
        odd += cnt[i] % 2;
    }
    cout << (k >= max(0, odd-1) ? "YES" : "NO") << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}