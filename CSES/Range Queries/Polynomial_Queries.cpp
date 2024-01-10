#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;
 
ll t[4*N], a[N], qs[N];
pair<ll,ll> lz[4*N];
// lz.first = number of updates
// lz.second = sum of (l - 1)

void lzpush(int v, int tl, int tr){
    if(v >= 2*N) return;
    int tm = (tl+tr)/2;
    t[v*2] += lz[v].first*(qs[tm] - qs[tl-1]) - lz[v].second * (tm-tl+1);
    t[v*2+1] += lz[v].first*(qs[tr] - qs[tm]) - lz[v].second * (tr-tm);
    lz[v*2] = {lz[v*2].first + lz[v].first, lz[v*2].second + lz[v].second}; 
    lz[v*2+1] = {lz[v*2+1].first + lz[v].first, lz[v*2+1].second + lz[v].second};
    lz[v] = {0, 0};
}
 
void build(int v, int tl, int tr){
    if(tl == tr){
        t[v] = a[tl];
        return;
    }
    int tm = (tl+tr)/2;
    build(v*2, tl, tm);
    build(v*2+1, tm+1, tr);
    t[v] = t[v*2] + t[v*2+1];
}
 
void update(int v, int tl, int tr, int l, int r){
    lzpush(v, tl, tr);
    if(r < tl || l > tr) return;
    if(l <= tl && r >= tr){
        t[v] += qs[tr] - qs[tl-1] - 1ll * (l-1) * (tr-tl+1);
        lz[v] = {lz[v].first + 1, lz[v].second + l - 1}; 
        return;
    }
    int tm = (tl+tr)/2;
    update(v*2, tl, tm, l, r);
    update(v*2+1, tm+1, tr, l, r);
    t[v] = t[v*2] + t[v*2+1];
}
 
ll query(int v, int tl, int tr, int l, int r){
    lzpush(v, tl, tr);
    if(r < tl || l > tr) return 0;
    if(l <= tl && r >= tr) return t[v];
    int tm = (tl+tr)/2;
    return query(v*2, tl, tm, l, r) + query(v*2+1, tm+1, tr, l, r);
}
 
int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        qs[i] = i + qs[i-1];
    }
    build(1, 1, n);
    while(q--){
        int op, x, y;
        cin >> op >> x >> y;
        if(op == 1) update(1, 1, n, x, y);
        else cout << query(1, 1, n, x, y) << "\n"; 
    }
}
