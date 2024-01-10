/*
Prefix Sum Queries
Segment Tree Practice
9 Dec 2023
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;

struct T{
    ll sum, mx;
};

ll a[N];
T t[4*N];

T combine(T x, T y){
    return {x.sum + y.sum, max(x.mx, x.sum + y.mx)};
}

void build(int v, int tl, int tr){
    if(tl == tr){
        t[v] = {a[tl], max(1ll*0, a[tl])};
        return;
    }
    int tm = (tl+tr)/2;
    build(v*2, tl, tm);
    build(v*2+1, tm+1, tr);
    t[v] = combine(t[v*2], t[v*2+1]);
}

void update(int v, int tl, int tr, int pos, int val){
    if(tl == tr){
        t[v] = {val, max(0, val)};
        return;
    }
    int tm = (tl+tr)/2;
    if(pos <= tm) update(v*2, tl, tm, pos, val);
    else update(v*2+1, tm+1, tr, pos, val);
    t[v] = combine(t[v*2], t[v*2+1]);
}

T query(int v, int tl, int tr, int l, int r){
    if(l > r) return {0, 0};
    if(l == tl && tr == r) return t[v];
    int tm = (tl+tr)/2;
    return combine(query(v*2, tl, tm, l, min(tm, r)), query(v*2+1, tm+1, tr, max(tm+1, l), r));
}

int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while(q--){
        int k, x, y;
        cin >> k >> x >> y;
        if(k == 1){
            a[x] = y;
            update(1, 1, n, x, y);
        }
        else cout << query(1, 1, n, x, y).mx << "\n";
    }
}