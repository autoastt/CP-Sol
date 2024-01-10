#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;

ll a[N], t[4*N], lzA[4*N], lzS[4*N];

void lzpush(int v, int tl, int tr){
    if(v >= 2*N) return;
    int tm = (tl+tr)/2;
    if(lzS[v]){
        lzS[v*2] = lzS[v*2+1] = lzS[v];
        t[v*2] = (tm-tl+1) * lzS[v];
        t[v*2+1] = (tr-tm) * lzS[v];
        lzA[v*2] = lzA[v*2+1] = lzS[v] = 0;
    }
    if(lzA[v]){
        lzA[v*2] += lzA[v];
        lzA[2*v+1] += lzA[v];
        t[v*2] += (tm-tl+1) * lzA[v];
        t[v*2+1] += (tr-tm) * lzA[v];
        lzA[v] = 0;
    }
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

void update(int v, int tl, int tr, int l, int r, int val, int type){
    lzpush(v, tl, tr);
    if(l > r) return;
    if(l == tl && r == tr){
        if(type == 1){
            t[v] += 1ll * (r-l+1) * val;
            lzA[v] += val;
        }
        else{
            t[v] = 1ll * (r-l+1) * val;
            lzS[v] = val;
        }
        return;
    }
    int tm = (tl+tr)/2;
    update(v*2, tl, tm, l, min(r,tm), val, type);
    update(v*2+1, tm+1, tr, max(tm+1,l), r, val, type);
    t[v] = t[v*2] + t[v*2+1];
}

ll query(int v, int tl, int tr, int l, int r){
    lzpush(v, tl, tr);
    if(l > r) return 0;
    if(l == tl && r == tr) return t[v];
    int tm = (tl+tr)/2;
    return query(v*2, tl, tm, l, min(r,tm)) + query(v*2+1, tm+1, tr, max(tm+1,l), r);
}

int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while(q--){
        int c, x, y, val;
        cin >> c >> x >> y;
        if(c == 3){
            cout << query(1, 1, n, x, y) << "\n";
        }
        else{
            cin >> val;
            update(1, 1, n, x, y, val, c);
        }
    }
}