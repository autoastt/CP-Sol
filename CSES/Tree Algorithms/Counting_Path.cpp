#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
#define mp make_pair
#define pb push_back
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
const bool TESTCASE = 0;
const int N = 2e5 + 5;

vector<int> adj[N];
int dp[N], ans[N], jmp[N][20], lv[N];

void dfs1(int u, int p){
    jmp[u][0] = p;
    lv[u] = lv[p] + 1;
    for(int i = 1; i < 20; i++){
        jmp[u][i] = jmp[jmp[u][i-1]][i-1];
    }
    for(auto v : adj[u]) if(v != p) dfs1(v, u);
}

void dfs2(int u, int p){
    for(auto v : adj[u]){
        if(v == p) continue;
        dfs2(v, u);
        dp[u] += dp[v];
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs1(1, 0);
    auto lift = [&](int x, int k){
        for(int i = 0; i < 20; i++){
            if((1 << i) & k) x = jmp[x][i];
        }
        return x;
    };
    auto lca = [&](int u, int v){
        if(lv[u] < lv[v]) swap(u, v);
        u = lift(u, lv[u] - lv[v]);
        if(u == v) return u;
        for(int i = 19; i >= 0; i--){
            if(jmp[u][i] != jmp[v][i]) u = jmp[u][i], v = jmp[v][i];
        }
        return jmp[u][0];
    };
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        dp[u]++; dp[v]++;
        int l = lca(u, v);
        dp[l]--; dp[jmp[l][0]]--;
    }
    dfs2(1, 0);
    for(int i = 1; i <= n; i++) cout << dp[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t(1);
    if(TESTCASE) cin >> t;
    while(t--) {
        solve();
    }
}
