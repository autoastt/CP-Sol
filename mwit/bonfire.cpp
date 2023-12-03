#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 155;
const int M = 1e9+7;

int dp[2][55][55][55][3][3], ans;

int main(){
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    dp[1][1][0][0][0][0] = dp[1][0][1][0][1][1] = dp[1][0][0][1][2][2] = 1;
    for(int x = 2; x <= n; x++){
        int sz = x%2, p = (x-1)%2;
        for(int i = 0; i <= a; i++){
            for(int j = 0; j <= b; j++){
                for(int k = 0; k <= c; k++){
                    for(int s = 0; s <= 2; s++){
                        if(i) dp[sz][i][j][k][s][0] += dp[p][i-1][j][k][s][1] + dp[p][i-1][j][k][s][2];
                        if(j) dp[sz][i][j][k][s][1] += dp[p][i][j-1][k][s][0] + dp[p][i][j-1][k][s][2];
                        if(k) dp[sz][i][j][k][s][2] += dp[p][i][j][k-1][s][0] + dp[p][i][j][k-1][s][1];
                        dp[sz][i][j][k][s][0] %= M;
                        dp[sz][i][j][k][s][1] %= M;
                        dp[sz][i][j][k][s][2] %= M;
                    }
                }
            }
        }
    }
    n %= 2;
    ans += dp[n][a][b][c][0][1] + dp[n][a][b][c][0][2];
    ans %= M;
    ans += dp[n][a][b][c][1][0] + dp[n][a][b][c][1][2];
    ans %= M;
    ans += dp[n][a][b][c][2][0] + dp[n][a][b][c][2][1];
    ans %= M;
    cout << ans;
}