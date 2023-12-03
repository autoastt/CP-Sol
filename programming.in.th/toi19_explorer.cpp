#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5+5;
const int M = 1e9+7;
vector<int> adj[N];
bool vis[N];
ll ans = 1, f[N];

void dfs(int u){
    vis[u] = true;
    ll cnt = 0;
    for(auto v : adj[u]){
        if(!vis[v]){
            dfs(v);
            cnt++;
        }
    }
    ans = (ans * f[cnt]) % M;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, x, y, s;
    cin >> n >> x;
    s = x;
    for(int i = 1; i < 2*n-1; i++){
        cin >> y;
        adj[x].push_back(y);
        x = y;
    }
    f[0] = 1;
    for(int i = 1; i < n; i++) f[i] = (f[i-1] * i) % M;
    dfs(s);
    cout << ans;
}