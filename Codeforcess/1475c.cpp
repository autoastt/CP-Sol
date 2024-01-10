#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;
int x[N], y[N], cnt[N][2];

void solve() {
    ll a, b, k;
    cin >> a >> b >> k;
    fill_n(cnt[0], N*2, 0);
    for(int i = 0; i < k; i++){
        cin >> x[i];
    }
    for(int i = 0; i < k; i++){
        cin >> y[i];
        cnt[x[i]][0]++;
        cnt[y[i]][1]++;
    }
    ll ans = 0;
    for(int i = 1; i <= a; i++) ans += 1LL*cnt[i][0]*(cnt[i][0]-1)/2;
    for(int i = 1; i <= b; i++) ans += 1LL*cnt[i][1]*(cnt[i][1]-1)/2;
    ans = k*(k-1)/2-ans;
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