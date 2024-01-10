#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(c) (c).begin(), (c).end()
const int N = 2e5+5;
const int INF = 1e9;

int a[N], b[N];

struct stmx{
    int n, *x;
    vector<int> t;
    
    stmx(int n, int x[]) : t(4*n), n(n), x(x) {
        build(1, 1, n);
    }

    void build(int v, int tl, int tr){
        if(tl == tr){
            t[v] = x[tl];
            return;
        }
        int tm = (tl+tr)/2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = max(t[v*2], t[v*2+1]);
    }

    int query(int v, int tl, int tr, int l, int r){
        if(r < tl || l > tr) return 0;
        if(l <= tl && tr <= r) return t[v];
        int tm = (tl+tr)/2;
        return max(query(v*2, tl, tm, l, r), query(v*2+1, tm+1, tr, l, r));
    }
};

struct stmn{
    int n, *x;
    vector<int> t;
    
    stmn(int n, int x[]) : t(4*n), n(n), x(x) {
        build(1, 1, n);
    }

    void build(int v, int tl, int tr){
        if(tl == tr){
            t[v] = x[tl];
            return;
        }
        int tm = (tl+tr)/2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = min(t[v*2], t[v*2+1]);
    }

    int query(int v, int tl, int tr, int l, int r){
        if(r < tl || l > tr) return INF;
        if(l <= tl && tr <= r) return t[v];
        int tm = (tl+tr)/2;
        return min(query(v*2, tl, tm, l, r), query(v*2+1, tm+1, tr, l, r));
    }
};


void solve() {
    int n, ans = 1;
    cin >> n;
    vector<int> pos[N];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    for(int i = 1; i <= n; i++) cin >> b[i];
    stmx ta(n, a);
    stmn tb(n, b);
    for(int i = 1; i <= n; i++){
        int k = lower_bound(all(pos[b[i]]), i) - pos[b[i]].begin();
        int can = 0;
        if(k < pos[b[i]].size()){
            int r = pos[b[i]][k];
            if(ta.query(1, 1, n, i, r) <= b[i] && tb.query(1, 1, n, i, r) >= b[i]) can = 1;
        }
        if(k > 0){
            int l = pos[b[i]][k-1];
            if(ta.query(1, 1, n, l, i) <= b[i] && tb.query(1, 1, n, l, i) >= b[i]) can = 1;
        }
        ans &= can;
    }
    ans ? cout << "YES\n" : cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}