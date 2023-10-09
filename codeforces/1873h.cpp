#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;
vector<int> adj[N];
int vis[N], p[N], cy, in[N];

bool dfs(int u, int pre){
    vis[u] = 1;
    // cout << u << " " << pre << "\n";
    for(auto v : adj[u]){
        if(v == pre) continue;
        if(vis[v] == 1) {
            cy = v;
            p[v] = u;
            return true;
        }
        p[v] = u;
        if(dfs(v, u)) return true;
    }
    return false;
}

pair<int,int> bfs(int st, int shit){
    queue<int> q;
    q.push(st);
    fill_n(vis, N, -1);
    // cout << "hello\n";
    vis[st] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        // cout << u << "\n";
        for(auto v : adj[u]){
            if(vis[v] != -1) continue;
            vis[v] = vis[u] + 1;
            if(in[v] && shit == 0) return {vis[v], v};
            q.push(v);
        }
    }
    return {0,0};
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    fill_n(vis, N, 0);
    fill_n(p, N, 0);
    fill_n(in, N, 0);
    for(int i = 1; i <= n; i++) adj[i].clear();
    for(int i = 0; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(a == b){cout << "No\n"; return;}
    dfs(1, 0);
    // cout << "p ";
    // for(int i = 1; i <= n; i++) cout << p[i] << " \n"[i==n];
    // cout << "cy= " << cy << "\n";
    int tmp = p[cy];
    in[cy] = 1;
    // cout << cy << "\n";
    while(tmp != cy){
        in[tmp] = 1;
        // cout << tmp << "\n";
        tmp = p[tmp];
    }
    // for(int i = 1; i <= n; i++) cout << in[i] << " \n"[i==n];

    if(in[b]) cout << "YES\n";
    else{
        auto [disb, bb] = bfs(b, 0);
        bfs(a, bb);
        if(vis[bb] <= disb) cout << "NO\n";
        else cout << "YES\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        // cout << "test\n";
        solve();
    }
}