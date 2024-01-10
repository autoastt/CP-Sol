#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;
const int INF = 1e9;

struct T{
    ll sum, pre, suf, mx;
};

T t[4*N];
ll arr[N];

T combine(T a, T b){
    ll pre = max(a.pre, a.sum + b.pre);
    ll suf = max(b.suf, b.sum + a.suf);
    return {a.sum + b.sum, pre, suf, max({a.mx, b.mx, a.suf+b.pre})};
}

void build(int v, int tl, int tr){
    if(tl == tr){
        t[v] = {arr[tl], max(1ll*0, arr[tl]), max(1ll*0, arr[tl]), max(1ll*0, arr[tl])};
        return;
    }
    int tm = (tl+tr)/2;
    build(v*2, tl, tm);
    build(v*2+1, tm+1, tr);
    t[v] = combine(t[v*2], t[v*2+1]);
}

void update(int v, int tl, int tr, int pos, int val){
    if(tl == tr){
        t[v] = {val, max(0, val), max(0, val), max(0, val)};
        return;
    }
    int tm = (tl+tr)/2;
    if(pos <= tm) update(v*2, tl, tm, pos, val);
    else update(v*2+1, tm+1, tr, pos, val);
    t[v] = combine(t[v*2], t[v*2+1]);
}

int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    build(1, 1, n);
    while(q--){
        int pos, val;
        cin >> pos >> val;
        update(1, 1, n, pos, val);
        cout << t[1].mx << "\n";
    }
}