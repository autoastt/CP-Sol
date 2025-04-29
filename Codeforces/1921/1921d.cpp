#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;

ll a[N], b[N];

void solve() {
    int n, m;
    ll ans = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    sort(a, a+n);
    sort(b, b+m);
    reverse(b, b+m);
    int la = 0, ra = n-1, lb = 0, rb = m-1;
    while(la <= ra){
        if(abs(a[la]-b[lb]) > abs(a[ra]-b[rb])){
            ans += abs(a[la]-b[lb]);
            la++;
            lb++;
        }
        else{
            ans += abs(a[ra]-b[rb]);
            ra--;
            rb--;
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