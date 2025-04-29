#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
const int K = 24;

int dp[1<<K], ans;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int x = s[0] - ' a', y = s[1] - ' a', z = s[2] - 'a';
        x = 1 << x; y = 1 << y; z = 1 << z;
        dp[x]++; dp[y]++; dp[z]++;
        dp[x | y]--; dp[y | z]--; dp[z | x]--;
        dp[x | y | z]++;
    }
    for(int i = 0; i < K; i++){
        for(int mask = 0; mask < (1 << K); mask++){
            if(mask & (1 << i)){
                dp[mask] += dp[mask ^ (1 << i)];
            }
        }
    }
    for(int mask = 0; mask < (1 << K); mask++){
        ans ^= dp[mask] * dp[mask];
    }
    cout << ans;
}
