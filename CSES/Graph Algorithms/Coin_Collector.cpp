#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;

vector<int> adj[N], adj_r[N], adj_scc[N], st, comp, roots;
bool vis[N];
ll val[N], cval[N], parent[N], dp[N], ans;

void dfs1(int u){
    vis[u] = true;
    for(int v : adj[u])
        if(!vis[v]) dfs1(v);  
    st.push_back(u);
}

void dfs2(int u){
    vis[u] = true;
    comp.push_back(u);
    for(int v : adj_r[u])
        if(!vis[v]) dfs2(v);  
}

ll dfs3(int u){
    if(dp[u]) return dp[u];
    dp[u] = cval[u];
    for(int v : adj_scc[u])
        dp[u] = max(dp[u], dfs3(v) + cval[u]);
    return dp[u];
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> val[i];
    }
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj_r[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        if(!vis[i]) dfs1(i);
    }
    reverse(st.begin(), st.end());
    fill_n(vis, N, false);
    for(auto i : st){
        if(!vis[i]){
            dfs2(i);
            int root = comp.front();
            for(auto j : comp){
                parent[j] = root;
            }
            roots.push_back(root);
            comp.clear();
        }
    }
    for(int i = 1; i <= n; i++) cval[parent[i]] += val[i];
    for(int u = 1; u <= n; u++){
        for(auto v : adj[u]){
            if(parent[v] != parent[u]){
                adj_scc[parent[u]].push_back(parent[v]);
            }
        }
    }
    for(auto i : roots){
        ans = max(dfs3(i), ans);
    }
    cout << ans;
}
