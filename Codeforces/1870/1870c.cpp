#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+5;
int a[N];

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> pos[k], ans;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]-1].push_back(i);
    }   
    int mn = N, mx = 0;
    for(int i = k; i; i--){
        if(pos[i-1].size() == 0){
            ans.push_back(0);
            continue;
        }
        for(auto j : pos[i-1]){
            mn = min(mn, j);
            mx = max(mx, j);
        }
        ans.push_back(2*(mx-mn+1));
    }
    reverse(ans.begin(), ans.end());
    for(auto x : ans) cout << x << " ";
    cout << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}