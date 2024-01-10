#include<bits/stdc++.h>
using namespace std;
#define ll long long

int dis[1005][1005], vis[1005][1005];
int mx[1005], mxx, mnx = 1e9;
vector<pair<int,int>> adj[1005];
bool ts[1005];

void dfs(int u, int p, int d){
    // if(dis[p][u]) return;
    // dis[p][u] = d;
    // cout << u << ' ' << p << ' ' << d << '\n';
    ts[u] = true;
    for(auto [v, w] : adj[u]) {
        if(ts[v]) continue;
        dis[p][v] = max(d, w);
        dfs(v, p, max(d, w));
    }
}

void solve() {
    int n, ans = 0;
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        ans += w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        vis[u][v] = vis[v][u] = w;
    }
    for(int i = 1; i <= n; i++){
        fill_n(ts, 1005, false);
        dfs(i, i, 0);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(vis[i][j] || i == j) continue;
            // cout << i << " " << j << "\n";
            // int tmp = 0;
            // for(auto k : adj[i]){
            //     if(adj[j].count(k)) {
            //         tmp = max({tmp, vis[j][k], vis[i][k]});
            //         cout << i << ' ' << k << " " << j << " " << tmp << "\n";
            //     }
            // }
            // if(!tmp) tmp = max(mx[i], mx[j]);
            int tmp = dis[i][j];
            // cout << i << ' ' << j << " " << tmp << "\n";
            ans += tmp + 1;
            vis[i][j] = vis[j][i] = tmp;
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}