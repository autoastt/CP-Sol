#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

vector<int> adj[N];
int dp[N][25], lv[N];

void dfs(int u, int p){
    dp[u][0] = p;
    lv[u] = lv[p] + 1;
    for(int i = 1; i < 20; i++){
        dp[u][i] = dp[dp[u][i-1]][i-1];
    }
    for(auto v : adj[u]) {
        if(v != p) dfs(v, u);
    }
}

int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    auto lift = [&](int x, int k){
        for(int i = 0; i < 20; i++) if((1 << i) & k) x = dp[x][i];
        return x;
    };
    auto lca = [&](int u, int v){
        if(lv[u] < lv[v]) swap(u, v);
        u = lift(u, lv[u] - lv[v]);
        if(u == v) return u;
        for(int i = 20; i >= 0; i--) if(dp[u][i] != dp[v][i]) u = dp[u][i], v = dp[v][i];
        return dp[u][0];
    };
    while(q--){
        int u, v;
        cin >> u >> v;
        cout << lv[u] + lv[v] - 2 * lv[lca(u, v)] << "\n";
    }
}
