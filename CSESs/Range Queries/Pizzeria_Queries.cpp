#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;
const int INF = 1e9;

struct T{
    ll mnm, mnp;
};

ll a[N];
T t[4*N];

T combine(T x, T y){
    return {min(x.mnm, y.mnm), min(x.mnp, y.mnp)};
}

void build(int v, int tl, int tr){
    if(tl == tr){
        t[v] = {a[tl]-tl, a[tl]+tl};
        return;
    }
    int tm = (tl+tr)/2;
    build(v*2, tl, tm);
    build(v*2+1, tm+1, tr);
    t[v] = combine(t[v*2], t[v*2+1]);
}

void update(int v, int tl, int tr, int pos, int val){
    if(tl == tr){
        t[v] = {val-tl, val+tl};
        return;
    }
    int tm = (tl+tr)/2;
    if(pos <= tm) update(v*2, tl, tm, pos, val);
    else update(v*2+1, tm+1, tr, pos, val);
    t[v] = combine(t[v*2], t[v*2+1]);
}

T query(int v, int tl, int tr, int l, int r){
    if(l > r) return {INF, INF};
    if(l == tl && r == tr) return t[v];
    int tm = (tl+tr)/2;
    return combine(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while(q--){
        int x;
        cin >> x;
        if(x == 1){
            int pos, val;
            cin >> pos >> val;
            update(1, 1, n, pos, a[pos] = val);
        }
        else{
            int pos;
            cin >> pos;
            cout << min(query(1, 1, n, 1, pos).mnm + pos, query(1, 1, n, pos, n).mnp - pos) << "\n";
        }
    }
}