#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;

vector<int> adj[N], adj_r[N], st;
vector<pair<int,int>> node(N);
int scc[N], opp[N];
bool vis[N];

void dfs1(int u){
    vis[u] = true;
    for(int v : adj[u])
        if(!vis[v]) dfs1(v);
    st.push_back(u);
}

void dfs2(int u, int cnt){
    vis[u] = true;
    for(int v : adj_r[u])
        if(!vis[v]) dfs2(v, cnt);
    scc[u] = cnt;
}

void solve(){
    int n, m, now = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> node[i].first >> node[i].second;
    }
    for(int i = 0; i < m; i += 2){
        int x, y;
        cin >> x >> y;
        opp[x] = y;
        opp[y] = x;
    }
    for(int i = 0; i < n; i++){
        auto [x, y] = node[i];
        adj[opp[x]].push_back(y);
        adj[opp[y]].push_back(x);
        adj_r[x].push_back(opp[y]);
        adj_r[y].push_back(opp[x]);
    }
    for(int i = 1; i <= m; i++){
        if(!vis[i]) dfs1(i);
    }
    fill_n(vis, N, false);
    for(int i = m-1; i >= 0; i--){
        if(!vis[st[i]]) dfs2(st[i], ++now);
    }
    for(int i = 1; i <= m; i++){
        if(scc[i] == scc[opp[i]]){
            return void(cout << 'N');
        }
    }
    cout << 'Y';
}

void clear(){
    for(int i = 0; i < N; i++){
        adj[i].clear();
        adj_r[i].clear();
        vis[i] = false;
    }
    st.clear();
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 5;
    while(t--){
        solve();
        clear();
    }
}