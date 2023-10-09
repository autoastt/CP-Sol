#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5005;
ll dp[N];

void solve() {
    int n;
    cin >> n;
    vector<ll> v;
    vector<pair<ll,ll>> val;
    for(int i = 0; i < n; i++){ 
        ll x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    ll cnt = 0, now = -1;
    for(int i = 0; i < v.size(); i++){
        if(v[i] != now){
            if(now == -1 && v[i] == 0) now = v[i], cnt = 1;
            else if(now == -1 && v[i] != 0) break;
            else if(v[i] > now+1) {val.push_back({now, cnt}); cnt = 0; break;}
            else {val.push_back({now, cnt}); now = v[i], cnt = 1;}
        }
        else cnt++;
    }
    if(cnt) val.push_back({now,cnt});
    ll idx = val.size()-1, mex = now+1;
    if(val.size() == 0) {cout << "0\n"; return;}
    for(int i = idx; i >= 0; i--){
        dp[i] = mex * (val[i].second-1) + val[i].first;
        for(int j = idx; j > i; j--){
            dp[i] = min(dp[i], (val[i].second-1)*val[j].first + val[i].first + dp[j]);
        }
    }
    cout << dp[0] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}