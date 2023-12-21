#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+1;

struct Node{
    int sz;
    Node *l, *r;

    Node() : sz(1e9), l(this), r(this) {}

    Node(int sz) : sz(sz), l(nullptr), r(nullptr) {}

    Node(Node *l, Node *r) : sz(1e9), l(l), r(r) {
        if(l) sz = min(sz, l->sz);
        if(r) sz = min(sz, r->sz);
    }

    Node(Node *v) : sz(v->sz), l(v->l), r(v->r) {}
};

Node *root[N];
map<int,int> mp;
int n, a[N];

Node *update(Node *v, int pos, int val, int tl = 1, int tr = n){
    if(tl == tr) return new Node(val);
    int tm = (tl+tr)/2;
    if(pos <= tm) return new Node(update(v->l, pos, val, tl, tm), v->r);
    return new Node(v->l, update(v->r, pos, val, tm+1, tr));
}

int query(Node *v, int l, int r, int tl = 1, int tr = n){
    if(r < tl || l > tr) return 1e9;
    if(l <= tl && tr <= r) return v->sz;
    int tm = (tl+tr)/2;
    return min(query(v->l, l, r, tl, tm), query(v->r, l, r, tm+1, tr));
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    root[0] = new Node();
    for(int i = 1; i <= n; i++){
        int last = mp[a[i]];
        mp[a[i]] = i;
        root[i] = root[i-1];
        if(last) root[i] = update(root[i], last, i-last);
    }
    while(q--){
        int x, y;
        cin >> x >> y;
        int ans = query(root[y], x, y);
        cout << (ans == 1e9 ? -1 : ans) << "\n";
    }
}