#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
const int K = 22;

int dp[1<<K], a[N];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    fill_n(dp, 1<<K, -1);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        dp[a[i]] = a[i];
    }
    for(int i = 0; i < K; i++){
        for(int mask = 0; mask < (1<<K); mask++){
            if(mask & (1<<i) && dp[mask] == -1) 
                dp[mask] = dp[mask^(1<<i)];
        }
    }
    for(int i = 0; i < n; i++){
        cout << dp[a[i]^((1<<K)-1)] << " ";
    }
}