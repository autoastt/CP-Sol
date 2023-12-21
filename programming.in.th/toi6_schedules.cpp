#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;

struct A{
    int s, e, idx;
    bool operator <(const A &o) const{
        return s == o.s ? e < o.e : s < o.s;
    }
};

int fw[N];

void update(int i, int val){
    for(; i < N; i += i & -i) fw[i] += val;
}

int sum(int i){
    int re = 0;
    for(; i > 0; i -= i & -i) re += fw[i];
    return re;
}

vector<A> v;
bool ans[N];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k;
    cin >> n >> k >> m;
    for(int i = 1; i <= n; i++){
        int s, e;
        cin >> s >> e;
        v.push_back({s, e, i});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        auto [s, e, idx] = v[i];
        if(sum(s) < k){
            update(s, 1);
            update(e+1, -1);
            ans[idx] = true;
        }
    }
    while(m--){
        int x; cin >> x;
        cout << (ans[x] ? 'Y' : 'N') << " ";
    }
}