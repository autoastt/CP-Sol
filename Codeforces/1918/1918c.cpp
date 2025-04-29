#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll a, b, r, ans = 0;
    int sign;
    bool first = false;
    cin >> a >> b >> r;
    if(r == 0){
        cout << abs(a-b) << "\n";
        return;
    }
    for(int i = 63; i >= 0; i--){
        ll now = 1ll << i;
        if((a & now) != (b & now)){
            if(!first){
                first = true;
                sign = (a & now ? -1 : 1);
                ans = -sign * now;
                continue;
            }
            if((sign == -1 && (b & now)) || (sign == 1 && (a & now))) ans += sign * now;
            else{
                if(r >= now){
                    r -= now;
                    ans += sign * now;
                }
                else ans -= sign * now;
            }
        }
    }
    cout << abs(ans) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
