#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+5;

bool ch[N];
int a[N], sum[N];

void solve() {
    int n, mx = 0;
    ll ans = 0;
    cin >> n;
    fill_n(a, N, 0);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a[x]++;
        mx = max(x, mx);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}