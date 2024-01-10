#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 3e5+5;
int dp[15][15];

void solve() {
    string s, l, r;
    int m, mx = 0;
    cin >> s >> m >> l >> r;
    fill_n(dp[0], 15*15, 1e9);
    for(int i = 1; i <= m; i++){
        int tmp = mx;
        for(int j = mx+1; j <= s.size(); j++){
            if(l[i-1] <= s[j-1] && s[j-1] <= r[i-1]){
                if(dp[i][s[j-1]-'0'] != 1e9) continue; 
                dp[i][s[j-1]-'0'] = j;
                tmp = max(tmp, j);
            }
        }
        mx = tmp;
    }
    for(int j = 1; j <= m; j++){
        for(int i = l[j-1]-'0'; i <= r[j-1]-'0'; i++){
            if(dp[j][i] == 1e9){
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO" <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}