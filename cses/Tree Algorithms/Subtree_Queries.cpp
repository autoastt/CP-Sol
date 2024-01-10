/*
Euler Tour Training
5 Jan 2024
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;

struct Fenwick{
    vector<ll> fw;
    int n;

    Fenwick(int n) : n(n) {
        fw.assign(n+1, 0);
    }

    void update(int i, ll val){
        for(; i <= n; i += i & -i) fw[i] += val;
    }

    ll sum(int i){
        ll ret = 0;
        for(; i > 0; i -= i & -i) ret += fw[i];
        return ret;
    }

    ll sum(int l, int r){
        return sum(r) - sum(l-1);
    }
};


ll in[N], out[N], idx[N], timer, v[N];
vector<int> adj[N];

void dfs(int u, int p){
    in[u] = ++timer;
    for(auto v : adj[u])
        if(v != p) dfs(v ,u);
    out[u] = timer;
}

int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    Fenwick fw(n);
    for(int i = 1; i <= n; i++) fw.update(in[i], v[i]);
    while(q--){
        int k, s, x;
        cin >> k >> s;
        if(k == 1){
            cin >> x;
            fw.update(in[s], x - v[s]);
            v[s] = x;
        }
        else{
            cout << fw.sum(in[s], out[s]) << "\n";
        }
    }
}
