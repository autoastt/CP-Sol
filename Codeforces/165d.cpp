#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

int in[N], timer, edge[N], dis[N], first[N], mn[20][1<<20];
vector<pair<int, int>> adj[N];
vector<int> euler;

void dfs(int u, int p, int e, int h){
    in[u] = ++timer;
    edge[e] = timer;
    dis[u] = h;
    first[u] = euler.size();
    euler.push_back(u);
    for(auto [v, id] : adj[u]) if(v != p) dfs(v, u, id, h+1);
}

int find_min(int l, int r){
    int k = 31 - __builtin_clz(r-l+1);
    return min(mn[k][l], mn[k][r-k]);
}

int lca(int u, int v){

}

struct Fenwick {
    int n;
    vector<int> fw;

    Fenwick(int n) : n(n) {fw.assign(n+1, 0);}

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
    int n, m;
    cin >> n;
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }
    dfs(1, 0, 0, 0);
    for(int i = 0; i < euler.size(); i++){
        mn[0][i] = euler[i];
    }
    Fenwick fw(n);
    cin >> m;
    while(m--){
        int op, id, a, b;
        cin >> op;
        if(op == 1){
            cin >> id;
            fw.update(edge[id], -1);
        }
        else if(op == 2){
            cin >> id;
            fw.update(edge[id], 1);
        }
        else{
            cin >> a >> b;
            if(in[a] > in[b]) swap(a, b);
            cout << (fw.sum(in[b]) - fw.sum(in[a]) ? -1 : in[b] - in[a]) << "\n";
        }
    }
}