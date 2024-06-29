#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
const bool TESTCASE = false;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

int adj[N], vis[N], scc[N], ans[N], cnt, sz;
vector<int> ts, radj[N];

void dfs1(int u) {
    vis[u] = true;
    int v = adj[u];
    if(!vis[v]) dfs1(v);
    ts.pb(u);
}

void dfs2(int u) {
    vis[u] = true;
    sz++;
    for(int v : radj[u])
        if(!vis[v]) dfs2(v);
    scc[u] = cnt;
    ans[u] = sz;
}

int dfs3(int u) {
    int v = adj[u];
    if(scc[v] != scc[u]) return ans[u] = dfs3(v) + 1;
    return ans[u];
}

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> adj[i];
        radj[adj[i]].pb(i);
    }
    for(int i = 1; i <= n; i++) if(!vis[i]) dfs1(i);
    reverse(all(ts));
    fill_n(vis, N, false);
    for(int i : ts) {
        if(!vis[i]) {
            cnt++;
            sz = 0;
            dfs2(i);
        }
    }
    ll ret = 0;
    for(int i = 1; i <= n; i++) {
        ret += dfs3(i);
    }
    cout << ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t(1);
    if(TESTCASE) cin >> t;
    while(t--) {
        solve();
    }
}

