#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;

int a[N], fw[N], ans[N];
unordered_map<int, int> mp;
vector<pair<int, int>> v[N];

void update(int idx, int val){
    for(; idx < N; idx += idx & -idx) fw[idx] += val;
}

int query(int idx){
    int ret = 0;
    for(; idx > 0; idx -= idx & -idx) ret += fw[idx];
    return ret;
}

int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
        v[y].push_back({x, i});
    }
    for(int i = 1; i <= n; i++){
        if(mp[a[i]]) update(mp[a[i]], -1);
        update(i, 1);
        mp[a[i]] = i;
        int sum = query(i);
        for(auto [x, j] : v[i]){
            ans[j] = sum - query(x-1);
        }
    }
    for(int i = 0; i < q; i++) cout << ans[i] << "\n";
}