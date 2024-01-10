/*
Hotel Queries
7 Dec 2023
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;

int a[N], t[4*N];

void build(int v, int tl, int tr){
    if(tl == tr){
        t[v] = a[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(v*2, tl, tm);
    build(v*2+1, tm+1, tr);
    t[v] = max(t[v*2], t[v*2+1]);
}

int query(int v, int tl, int tr, int x){
    if(x > t[v]) return -1;
    if(tl == tr) return tl;
    int tm = (tl + tr) / 2;
    if(t[v*2] >= x) return query(v*2, tl, tm, x);
    else return query(v*2+1, tm+1, tr, x);
}

void update(int v, int tl, int tr, int pos, int x){
    if(tl == tr){
        t[v] -= x;
        return;
    }
    int tm = (tl + tr) / 2;
    if(pos <= tm) update(v*2, tl, tm, pos, x);
    else update(v*2+1, tm+1, tr, pos, x);
    t[v] = max(t[v*2], t[v*2+1]);
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1, 1, n);
    while(m--){
        int x;
        cin >> x;
        int q = query(1, 1, n, x);
        if(q == -1){
            cout << 0 << " ";
        }
        else{
            update(1, 1, n, q, x);
            cout << q << " ";
        }
    }
}