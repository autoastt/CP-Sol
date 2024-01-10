#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;

ll in[N], out[N], timer, a[N];
vector<int> adj[N];

struct SegTree {
    ll t[4*N], lz[4*N];

    void push(int v){
        if(v >= 2*N) return;
        lz[v*2] = max(lz[v], lz[v*2]);
        t[v*2] = max(t[v*2], lz[v*2]);
        lz[v*2+1] = max(lz[v], lz[v*2+1]);
        t[v*2+1] = max(t[v*2+1], lz[v*2+1]);
        lz[v] = 0;
    }

    void build(int v, int tl, int tr){
        if(tl == tr){
            t[v] = a[tl];
            return;
        }
        int tm = (tl+tr)/2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = max(t[v*2], t[v*2+1]);
    }

    void update(int v, int tl, int tr, int l, int r, ll val){
        push(v);
        if(tl <= l && r <= tr){
            t[v] = max(t[v], val);
            lz[v] = max(lz[v], val);
            return;
        }
        if(r < tl || tr < l) return;
        push(v);
        int tm = (tl+tr)/2;
        update(v*2, tl, tm, l, r, val);
        update(v*2+1, tm+1, tr, l, r, val);
        t[v] = max(t[v*2], t[v*2+1]);
    }

    ll query(int v, int tl, int tr, int l, int r){
        push(v);
        if(tl <= l && r <= tr){
            return t[v];
        }
        if(r < tl || tr < l) return 0;
        int tm = (tl+tr)/2;
        return max(query(v*2, tl, tm, l, r), query(v*2+1, tm+1, tr, l, r));
    }
}t;

void dfs(int u, int p){
    in[u] = ++timer;
    for(auto v : adj[u]) if(v != p) dfs(v, u);
    out[u] = timer;
}


int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    t.build(1, 1, n);
    dfs(1, 0);
    while(q--){
        int k, s, x;
        cin >> k;
        if(k == 1){
            cin >> s >> x;
            t.update(1, 1, n, in[s], out[s], x);
        }
        else{
            int l, r;
            cin >> l >> r;
            l = in[l]; r = in[r];
            if(l > r) swap(l, r);
            cout << t.query(1, 1, n, l, r) << " ";
        }
    }
}