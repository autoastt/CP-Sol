#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
#define mp make_pair
#define pb push_back
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
const bool TESTCASE = false;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

vector<int> adj[N];
int a[N], in[N], out[N], euler[N], timer, ans[N];

void dfs1(int u, int p){
    in[u] = ++timer;
    euler[timer] = u;
    for(auto v : adj[u]) if(v != p) dfs1(v, u);
    out[u] = timer;
}

struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick(int n) : n(n) { bit.assign(n+1, 0); }

    void update(int i, int x){
        for(; i <= n; i += i & -i) bit[i] += x;
    }

    int sum(int i){
        int ret = 0;
        for(; i > 0; i -= i & -i) ret += bit[i];
        return ret;
    }
};

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs1(1, 0);
    Fenwick fw(n);
    unordered_map<int, int> cur;
    for(int i = n; i > 0; i--){
        int u = euler[i];
        if(cur[a[u]]){
            fw.update(cur[a[u]], -1);
        }
        cur[a[u]] = i;
        fw.update(i, 1);
        ans[u] = fw.sum(out[u]);
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t(1);
    if(TESTCASE) cin >> t;
    while(t--) {
        solve();
    }
}

