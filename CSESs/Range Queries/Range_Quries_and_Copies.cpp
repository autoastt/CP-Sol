#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;

struct Node{
    ll sum;
    Node *l, *r;

    Node(ll val) : sum(val), l(nullptr), r(nullptr) {}

    Node(Node *l, Node *r) : l(l), r(r) {
        if(l) sum += l->sum;
        if(r) sum += r->sum;
    }

    Node(Node *v) : sum(v->sum), l(v->l), r(v->r) {}
};

Node *root[N];
ll a[N];

Node *build(int tl, int tr){
    if(tl == tr) return new Node(a[tl]);
    int tm = (tl+tr)/2;
    return new Node(build(tl, tm), build(tm+1, tr));
}

Node *update(Node *v, int tl, int tr, int pos, int val){
    if(tl == tr) return new Node(val);
    int tm = (tl+tr)/2;
    if(pos <= tm) return new Node(update(v->l, tl, tm, pos, val), v->r);
    return new Node(v->l, update(v->r, tm+1, tr, pos, val));
}

ll query(Node *v, int tl, int tr, int l, int r){
    if(r < tl || l > tr) return 0;
    if(l <= tl && tr <= r) return v->sum;
    int tm = (tl+tr)/2;
    return query(v->l, tl, tm, l, r) + query(v->r, tm+1, tr, l, r);
}


int main(){
    int n, q, t = 1;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    root[1] = build(1, n);
    while(q--){
        int op;
        cin >> op;
        if(op == 1){
            int k, pos, val;
            cin >> k >> pos >> val;
            root[k] = update(root[k], 1, n, pos, val);
        }
        else if(op == 2){
            int k, x, y;
            cin >> k >> x >> y;
            cout << query(root[k], 1, n, x, y) << "\n";
        }
        else{
            int k;
            cin >> k;
            root[++t] = new Node(root[k]);
        }
    }

}
