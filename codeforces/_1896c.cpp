#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, x, l = 0, r = 1e9, mn = 1e9, j = 0;
    cin >> n >> x;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        v.push_back({k,i});
        mn = min(mn, k);
    }
    sort(v.begin(), v.end());
    vector<int> b;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        b.push_back(k);
        // if(k < mn) r++;
    }
    sort(b.begin(), b.end());
    bool shit = 0;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        while(v[i].first > b[j] && j < n) j++, cnt++;
        l = max(l, min(n-i, j));
        if(l > 0 && !shit) r = l, shit = 1;
        if(j == n) break;
    }
    cout << l << " " << r << "\n";
    if(x < r || x > l){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector<int> ans(n);
    reverse(v.begin(), v.end());
    for(int i = 0, k = 0; i < n; i++){
        if(x) ans[v[i].second] = b[--x];
        else ans[v[i].second] = b[n-1-(k++)];
    }
    for(int i = 0; i < n; i++) cout << ans[i] << " \n"[i==n-1];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}