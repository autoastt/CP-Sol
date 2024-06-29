#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
const bool TESTCASE = false;
const int N = 2e5 + 5;
const ll M = 998244353;
const int INF = 2e9;
const ll LLINF = 1e18;

int n, q;
ll a[N], b[N];

struct S {
    ll sa, sb, sab, sz;
};

struct F {
    ll x, y;
};

S t[4*N];
F lz[4*N];

void combine(int v) {
    t[v] = {1ll * (t[v*2].sa + t[v*2+1].sa) % M,
        1ll * (t[v*2].sb + t[v*2+1].sb) % M,
        1ll * (t[v*2].sab + t[v*2+1].sab) % M,
        1ll * (t[v*2].sz + t[v*2+1].sz) % M};
}

void op(int v) {
    auto [x, y] = lz[v];
    ll addA = (1ll * t[v].sz * x) % M;
    ll addB = (1ll * t[v].sz * y) % M;
    ll addAB1 = (1ll * t[v].sa * y) % M;
    ll addAB2 = (1ll * t[v].sb * x) % M;
    ll addAB3 = (1ll * (x * y % M * t[v].sz) % M) % M;
    t[v] = {(t[v].sa + addA) % M,
        (t[v].sb + addB) % M,
        t[v].sab,
        t[v].sz % M};
    t[v].sab = (t[v].sab + addAB1) % M;
    t[v].sab = (t[v].sab + addAB2) % M;
    t[v].sab = (t[v].sab + addAB3) % M;
}

void push(int v, int l, int r) {
    op(v);
    if(l != r) { 
        lz[v*2] = {1ll * (lz[v].x + lz[v*2].x) % M, 1ll * (lz[v].y + lz[v*2].y) % M};
        lz[v*2+1] = {1ll * (lz[v].x + lz[v*2+1].x) % M, 1ll * (lz[v].y + lz[v*2+1].y) % M};
    }
    lz[v] = {0, 0};
}

void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = {a[tl], b[tl], (a[tl] * b[tl]) % M, 1};
        lz[v] = {0, 0};
        return;
    }
    int tm = (tl + tr) / 2;
    build(v*2, tl, tm);
    build(v*2+1, tm+1, tr);
    combine(v);
}

void update(int v, int tl, int tr, int l, int r, ll x, ll y) {
    push(v, tl, tr);
    if(l <= tl && tr <= r) {
        lz[v] = {1ll * (lz[v].x + x) % M, 1ll * (lz[v].y + y) % M};
        push(v, tl, tr);
        return;
    }
    if(tl > r || l > tr) return;
    int tm = (tl + tr) / 2;
    update(v*2, tl, tm, l, r, x, y);
    update(v*2+1, tm+1, tr, l, r, x, y);
    combine(v);
}

ll query(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr);
    if(l <= tl && tr <= r) return t[v].sab;
    if(tl > r || l > tr) return 0;
    int tm = (tl + tr) / 2;
    return (query(v*2, tl, tm, l, r) % M + query(v*2+1, tm+1, tr, l, r) % M) % M;
}


void solve() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    build(1, 1, n);
    while(q--) {
        ll o, l, r, x;
        cin >> o >> l >> r;
        if(o == 1) {
            cin >> x;
            update(1, 1, n, l, r, x, 0);
        }
        else if(o == 2) {
            cin >> x;
            update(1, 1, n, l, r, 0, x);
        }
        else cout << query(1, 1, n, l, r) % M << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t(1);
    if(TESTCASE) cin >> t;
    while(t--) {
        solve();
    }
}

