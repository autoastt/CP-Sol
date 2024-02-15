#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;

vector<pair<int, int>> v;
int a[N];
bool vis[N];

int main(){
  int n, m, k, x, ans = 0;
  cin >> m >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < k; i++) {
    int u, h;
    cin >> u >> h;
    v.push_back({h, u}); 
  }
  sort(v.begin(), v.end());
  cin >> x;
  vis[x] = vis[x+1] = vis[x-1] = true;
  for(auto [h, u] : v){
    swap(vis[u], vis[u+1]);
    if(u == x) x++;
    else if(u+1 == x) x--;
    vis[x] = vis[x+1] = vis[x-1] = true;
  }
  for(int i = 1; i <= n; i++){
    if (vis[i]) {
      ans = max(a[i], ans);
    }
  }
  cout << ans << '\n' << (a[x] == ans ? "NO" : "USE");
}
