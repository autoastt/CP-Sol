#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3+5;

void solve() {
    int n, ans = 1;
    cin >> n;
    vector<pair<int,int>> v;
    for(int i = 1; i <= n; i++){
        int d,s;
        cin >> d >> s;
        v.push_back({d, d+s-1});
    }
    for(int i = 500; i > 0; i--){
        bool can = true;
        for(int j = 0; j < n; j++){
            if(v[j].second <= 2*i-v[j].first-1) can = false;
        }
        if(can){
            cout << i << "\n";
            return;
        }
    }
    // int l = 1, r = 1e5;

    // while(l < r){
    //     int mid = (l+r-1)/2;
    //     bool can = true;
    //     // cout << " mid= " << mid << "\n";
    //     for(auto [d,s]:v){
    //         // cout << d << " " << s << " " << 2*mid-d-1 << "\n";
    //         if(2*mid-d-1 >= s){
    //             can = 0;
    //             break;
    //         }
    //     }
    //     if(can) l = mid+1, ans = mid;
    //     else r = mid-1;
    // }
    // cout << ans << "\n";
    return;
}

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}