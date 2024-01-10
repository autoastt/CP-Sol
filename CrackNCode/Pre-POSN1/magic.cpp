#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+5;
ll cnt[N];

void solve() {
    deque<ll> dq;
    fill_n(cnt, N, 0);
    ll n, k, ans, now = 0;
    cin >> n >> k;
    ans = n*(n+1)/2;
    for(int i = 0; i < n; i++){
        ll a; cin >> a;
        dq.push_back(a);
        if(!cnt[a]) now++;
        cnt[a]++;
        while(now >= k && !dq.empty()){
            cnt[dq.front()]--;
            if(cnt[dq.front()] == 0) now--;
            dq.pop_front();
        }
        ans -= dq.size();
    }
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