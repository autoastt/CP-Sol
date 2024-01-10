/*
Euler Tour Training
5 Jan 2024
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;

ll in[N], out[N], timer, v[N];
vector<int> adj[N];

struct Fenwick {
    int n;
    vector<ll> t;
    
    Fenwick(int n) : n(n) { t.assign(n+1, 0); }

    void update(int i, int val){
        for(; i <= n; i += i & -i) t[i] += val;
    }

    ll sum(int i){
        ll ret = 0;
        for(; i > 0; i -= i & -i) ret += t[i];
        return ret;
    }

};

void dfs(int u, int p){
    in[u] = ++timer;
    for(auto v : adj[u]) if(v != p) dfs(v, u);
    out[u] = timer;
}

int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    Fenwick fw(n);
    for(int i = 1; i <= n; i++){
        fw.update(in[i], v[i]);
        fw.update(out[i]+1, -v[i]);
    }
    while(q--){
        int k, s, x;
        cin >> k >> s;
        if(k == 1){
            cin >> x;
            fw.update(in[s], x - v[s]);
            fw.update(out[s]+1, -(x - v[s]));
            v[s] = x;
        }
        else{
            cout << fw.sum(in[s]) << "\n";
        }
    }
}