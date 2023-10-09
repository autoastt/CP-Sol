#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 998244353;
const int N = 3e5 + 5;
ll a[N];

void solve() {
    ll n, ans = 0, pow = 1;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < 30; i++){
        int cnt = 0;
        bool odd = false;
        for(int j = 0; j < n; j++){
            if(a[j] & (1<<j)) odd = !odd;
            if(odd){
                cnt++;
            }
        }
        for(int j = 0; j < n; j++){
            ans += pow * cnt;
            if(a[j] & (1<<j)) cnt = n-j-cnt;
        }
        pow *= 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}