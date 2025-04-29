#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 998244353;
const int N = 3e5+5;

vector<int> adj[N];
ll dp[N][2];

void dfs(int u, int p){
    ll sum0 = 0, sum1 = 0, pro = 1;
    for(auto v : adj[u]){
        if(v == p) continue;
        dfs(v, u);
        sum0 = (sum0 + dp[v][0]) % M;
        sum1 = (sum1 + dp[v][1]) % M;
        pro = (pro * (1 + dp[v][0])) % M;
    }
    dp[u][0] = pro;
    dp[u][1] = sum0 + sum1;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        dp[i][0] = dp[i][1] = 0;
    }
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << (1 + dp[1][0] + dp[1][1]) % M << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
