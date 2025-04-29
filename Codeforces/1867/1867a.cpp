#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;
const int N = 4e4 + 5;

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> v, ans;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        v.push_back({a, i});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        ans.push_back({v[i].second, n-i});
    }
    sort(ans.begin(), ans.end());
    for(auto [i, x] : ans) cout << x << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}