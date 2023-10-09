#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;
int a[N];


void solve() {
    int n, q;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int> zero[30];
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 30; j++){
            if(a[i] & (1<<j)) continue;
            zero[j].push_back(i);
        }
    }
    cin >> q;
    while(q--){
        int l, k;
        cin >> l >> k;
        if(a[l] < k){
            cout << "-1 ";
            continue;
        }
        vector<pair<int,int>> one;
        for(int i = 0; i < 30; i++){
            if(a[l] & (1<<i)){
                auto idx = upper_bound(zero[i].begin(), zero[i].end(), l);
                if(idx == zero[i].end()) continue;
                one.push_back({*idx, i});
            }
        }
        sort(one.begin(), one.end());
        int now = a[l], ans = l, prev = l;
        for(int j = 0; j < one.size(); j++){
            auto [r, i] = one[j];
            now -= (1<<i);
            // cout << "test " << r << " " << i << " " << now  << " " << ans << "\n";
            if(now < k) {
                ans = r-1;
                break;
            }
        }
        if(now >= k) ans = n;
        cout << ans << " ";
    }
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