#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;

int a[N], n;

bool dfs(int l, int r, int now){
    if(l == 1 && r == n) return true;
    // cout << l << " " << r << " " << now << "\n";
    bool x = false;
    if(l > 1 && abs(a[l-1]-now) == 1) x |= dfs(l-1, r, min(now, a[l-1]));
    if(r < n && abs(a[r+1]-now) == 1) x |= dfs(l, r+1, min(now, a[r+1]));
    return x;
}

void solve() {
    int mx = 0;
    bool ans = false;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    for(int i = 1; i <= n; i++){
        ans |= dfs(i, i, a[i]);
    }
    cout << (ans ? "YES" : "NO") << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}