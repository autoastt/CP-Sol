#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e12;
const int N = 1e5+5;

void solve() {
    int n,m;
    cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) 
            cin >> a[i][j];
    }
    ll l = 1, r = INF;
    while(l < r) {
        ll mid = (l+r+1)/2;
        bool ch[N] = {}, two = false, can = true;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < m; j++){
                if(a[i][j] >= mid) ch[j] = true, cnt++;
            }
            if(cnt >= 2) two = true;
        }
        for(int i = 0; i < m; i++) can = can && ch[i];
        if(two && can) l = mid;
        else r = mid-1;
    }
    cout << l << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        // string d; cin >> d;
        solve();
    }
}