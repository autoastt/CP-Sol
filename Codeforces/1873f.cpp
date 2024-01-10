#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;
ll a[N], h[N];

void solve() {
    ll n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> h[i];
    ll sz = 0, sum = 0, ans = 0;
    for(int i = 1; i <= n; i++) {
        if(sz == 0){
            if(a[i] > k) continue;
            sum+=a[i];
            sz++;
            ans = max(sz, ans);
            continue;
        }
        else{
            if(h[i-1] % h[i] == 0){
                if(sum + a[i] <= k) sum += a[i], sz++, ans = max(sz, ans);
                else{
                    sum += a[i], sz++;
                    int j = i-sz+1;
                    for(; j <= i; j++){
                        sum -= a[j];
                        sz--;
                        if(sum <= k) break;
                    }
                    ans = max(sz, ans);
                }
            }
            else{
                ans = max(sz, ans);
                sz = sum = 0;
                if(a[i] <= k) sz++, sum = a[i];
            }
        }
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