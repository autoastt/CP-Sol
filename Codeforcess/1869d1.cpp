#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;
ll a[N], p[35];
map<ll,pair<int,int>> s;
void solve() {
    ll n, sum = 0, pm = 0, cnt[35] = {};
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    if(sum % n){
        cout << "No\n";
        return;
    }
    sum /= n;
    for(int i = 1; i <= n; i++){
        ll x = sum - a[i];
        if(s.find(x) == s.end() && x != 0){
            cout << "No\n";
            return;
        }
        auto [p, m] = s[x];
        cnt[p]++, cnt[m]--;
    }
    for(int i = 0; i <= 32; i++){
        if(cnt[i]){
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    p[0] = 1;
    for(int i = 1; i <= 32; i++){
        p[i] = 2*p[i-1];
        for(int j = 0; j < i; j++) s[p[i]-p[j]] = {i,j}, s[p[j]-p[i]] = {j,i};
    }
    while(t--) {
        solve();
    }
}