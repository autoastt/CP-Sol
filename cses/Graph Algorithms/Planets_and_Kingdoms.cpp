#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

vector<int> adj[N][2], st;
bool vis[N];
int scc[N];

void dfs(int u, int t, int cnt = 0){
    vis[u] = true;
    for(auto v : adj[u][t]){
        if(!vis[v]) dfs(v, t, cnt);
    }
    if(t) scc[u] = cnt;
    else st.push_back(u);
}

int main(){
    int n, m, now = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u][0].push_back(v);
        adj[v][1].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs(i, 0);
    }
    fill_n(vis, N, false);
    reverse(st.begin(), st.end());
    for(int i = 0; i < n; i++){
        if(!vis[st[i]]) dfs(st[i], 1, ++now);
    }
    cout << now << "\n";
    for(int i = 1; i <= n; i++) cout << scc[i] << " ";
}