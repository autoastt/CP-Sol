#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;

ll dp1[N], dp2[N], sz[N];
vector<int> adj[N];
int n;

void dfs1(int u, int p){
    for(auto v : adj[u]) {
        if(v == p) continue;
        dfs1(v, u);
        dp1[u] += dp1[v] + sz[v];
        sz[u] += sz[v];
    }
}

void dfs2(int u, int p){
    if(p != 0) dp2[u] = dp1[p] - dp1[u] - 2 * sz[u] + dp2[p] + n;
    for(auto v : adj[u]) {
        if(v != p) dfs2(v, u);
    }
}

int main(){
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        sz[i] = 1;
    }
    dfs1(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << dp1[i] + dp2[i] << " ";
    }
}
