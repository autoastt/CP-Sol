#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;
int a[N];

void solve() {
    int n, m, k, cnt = 0, ans = 0;
    cin >> n >> m >> k;
    fill_n(a, N, 0);
    vector<pair<int,int>> v;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        v.push_back({y,x});
        a[x]++; a[y+1]--;
    }    
    for(int i = 1; i <= n; i++){
        a[i] += a[i-1];
        if(a[i] == 0) cnt++;
    }
    sort(v.begin(), v.end());
    // for(int i = 0; i < m; i++) cout << i << ' ' << v[i].first << " " << v[i].second << "\n";
    for(int i = 0; i < m ;i++){
        int r = v[i].first, l = v[i].second, cnt2 = 0;
        for(int i = l; i <= r; i++){
            cnt2 += a[i] == 1;
        }
        ans = max(ans, cnt2);
        auto itr = lower_bound(v.begin(), v.end(), make_pair(l,0)) - v.begin();
        cout << i << ' ' << itr << "\n";
        if(itr == i) itr++;
        while(itr < m && v[itr].second <= r){
            cnt2 = 0;
            for(int i = l; i < v[itr].second; i++) if(a[i] <= 2) cnt2++;
            for(int i = v[itr].second; i <= r; i++) if(a[i] < 2) cnt2++;
            cout << "jio " << itr << " " << cnt2 << "\n"; 
            ans = max(ans, cnt2);
            itr++;
        }
    }
    cout << cnt + ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}