#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;

vector<int> adj[N];
int vis[N];

bool dfs(int u){
  if(vis[u] == 1) return true;
  if(vis[u] == 2) return false;
  vis[u] = 1;
  for(auto v : adj[u]){
    if(dfs(v)) return true;
  }
  vis[u] = 2;
  return false;
}

void solve() {
  int n, k;
  cin >> n >> k;
  fill_n(vis, n+1, 0);
  for(int i = 1; i <= n; i++) adj[i].clear();
  for(int i = 0; i < k; i++){
    int u, v; 
    if(n == 1){
      cin >> u;
      continue;
    }
    cin >> v >> u;
    for(int j = 2; j < n; j++){
      cin >> v;
      adj[u].push_back(v);
      u = v;
    }
  }
  if(n < 3) return void(cout << "YES\n");
  for(int i = 1; i <= n; i++){
    if(dfs(i)) return void(cout << "NO\n");
  }
  cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
