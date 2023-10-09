#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9+7;
const int N = 305;
ll dp[N][N][10], a[N];

int main(){
    int n,k,d;
    cin >> n >> k >> d;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] += a[i-1];
    }

    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++) dp[i][j][1] = 1;
    // dp[1][n][1] = 1;

    for(int x = 2; x <= k; x++){
        for(int j = 1; j <= n; j++){
            for(int i = 1; i <= j; i++){
                for(int mid = i; mid < j; mid++){
                    if(abs(a[mid]-a[i-1] - (a[j]-a[mid])) <= d) 
                        dp[i][j][x] = (dp[i][j][x] + dp[i][mid][x-1] * dp[mid+1][j][x-1]) % M;
                    // cout << i << " " << mid << " " << j << " " << x << " " << dp[i][j][x] << "\n";
                }
            }
        }
    }
    cout << dp[1][n][k];
}