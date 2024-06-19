#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int lv[N], par[N][20];
vector<int> adj[N];

void dfs(int u, int p){
    lv[u] = lv[p] + 1;
    for(auto v : adj[u]) {
        if(v != p) dfs(v, u);
    }
}

int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 2; i <= n; i++){
        cin >> par[i][0];
        adj[par[i][0]].push_back(i);
    }
    for(int i = 1; i < 20; i++){
        for(int j = 1; j <= n; j++)
            par[j][i] = par[par[j][i-1]][i-1];
    }
    auto lift = [&](int x, int k){
        for(int i = 0; i < 20; i++) if((1 << i) & k) x = par[x][i];
        return x;
    };
    dfs(1, 0);
    auto lca = [&](int u, int v){
        if(lv[u] < lv[v]) swap(u, v);
        u = lift(u, lv[u] - lv[v]);
        if(u == v) return u;
        for(int i = 19; i >= 0; i--) if(par[u][i] != par[v][i]) u = par[u][i], v = par[v][i];
        return par[u][0];
    };
    while(q--){
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << "\n";
    }
}
