#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;

vector<int> adj[N];
int in[N], out[N], timer, a[N];
bool level[N];

void dfs(int u, int p, bool parity){
    in[u] = ++timer;
    level[u] = parity;
    for(auto v : adj[u]){
        if(v != p) dfs(v, u, !parity);
    }
    out[u] = timer;
}

struct Fenwick {
    int n;
    vector<int> fw;

    Fenwick(int n) : n(n) { fw.assign(n+1, 0); }

    void update(int i, int val){
        for(; i <= n; i += i & -i) fw[i] += val;
    }

    int sum(int i){
        int ret = 0;
        for(; i > 0; i -= i & -i) ret += fw[i];
        return ret;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 0);
    Fenwick fw(n);
    while(m--){
        int k, x, val;
        cin >> k >> x;
        int lv = (level[x] ? -1 : 1);
        if(k == 1){
            cin >> val;
            fw.update(in[x], val * lv);
            fw.update(out[x]+1, -val * lv);
        }
        else{
            cout << a[x] + fw.sum(in[x]) * lv << "\n";
        }
    }
}