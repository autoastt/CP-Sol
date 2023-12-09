#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int t[4*N], a[N];

int build(int v, int tl, int tr){
    if(tl == tr) return t[v] = 1;
    int tm = (tl+tr)/2;
    return t[v] = build(v*2, tl, tm) + build(v*2+1, tm+1, tr);
}

int query(int v, int tl, int tr, int l, int r){
    if(l > r) return 0;
    if(l == tl && r == tr) return t[v];
    int tm = (tl+tr)/2;
    return query(v*2, tl, tm, l, min(tm, r)) + query(v*2+1, tm+1, tr, max(tm+1, l), r);
}

void update(int v, int tl, int tr, int pos, int val){
    if(tl == tr){
        t[v] = val;
        return;
    }
    int tm = (tl+tr)/2;
    if(pos <= tm) update(v*2, tl, tm, pos, val);
    else update(v*2+1, tm+1, tr, pos, val);
    t[v] = t[v*2] + t[v*2+1];
}
int find_k(int v, int tl, int tr, int k){
    if(tl == tr) return tl;
    int tm = (tl+tr)/2;
    return k <= t[v*2] ? find_k(v*2, tl, tm, k) : find_k(v*2+1, tm+1, tr, k-t[v*2]);
}

void sol(){
    int n, now = 0;
    cin >> n;
    build(1, 1, n);
    for(int i = 1; i <= n; i++){
        int x = (i+1 + query(1, 1, n, 1, now)) % (n-i+1);
        if(x == 0) x = n-i+1;
        now = find_k(1, 1, n, x);
        a[now] = i;
        update(1, 1, n, now, 0);
    }
    for(int i = 1; i <= n; i++) cout << a[i] << " \n"[i==n];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        sol();
    }
}