#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5;
const ll M = 1e9 + 7;
ll dp[N][2], ans;

int main(){
    ll n, m, k;
    cin >> n >> m >> k;
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        dp[i][0] = ((dp[i-1][1] + dp[i-1][0]) * (m-1)) % M;
        dp[i][1] = (dp[i-1][0] + dp[i-1][1] - (i > k ? dp[i-k-1][0] : 0)) % M;
        dp[i][0] += dp[i][0] < 0 ? M : 0;
        dp[i][1] += dp[i][1] < 0 ? M : 0;
    }
    cout << (dp[n][0] + dp[n][1]) % M;
}