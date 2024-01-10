#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;
int a[N];

void solve() {
    int n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    reverse(a, a+n);
    vector<int> v, vv;
    for(int i = 0; i < n; i++){
        auto x = upper_bound(v.begin(), v.end(), a[i]);
        if(x == v.end()) v.push_back(a[i]);
        else {
            auto y = upper_bound(vv.begin(), vv.end(), a[i]);
            if(y == vv.end()) vv.push_back(a[i]);
            else{ 
                // vv[y-vv.begin()] = a[i];
                ans++;
            }
        }
    }
    // for(int i = 0; i < v.size(); i++){
    //     s.insert(i);
    //     // cout << v[i].first << " " << v[i].second << "\n";
    // }
    // ans = v.size();
    // v.clear();
    // for(int i = 0; i < n; i++){
    //     if(s.count(i)) continue;
    //     auto x = upper_bound(v.begin(), v.end(), make_pair(a[i], i));
    //     if(x == v.end()) v.push_back({a[i], i});
    //     else v[x-v.begin()] = {a[i], i};
    // }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}