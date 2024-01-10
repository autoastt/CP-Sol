#include<bits/stdc++.h>
using namespace std;

unordered_map<int, int> dp;

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        dp[a]++;
        unordered_map<int, int> tmp = dp;
        for(auto [sum, cnt] : tmp){
            dp[sum+a] += cnt;
            dp[sum-a] += cnt;
        }
    }
    cout << dp[0];
}