#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5+5;
ll a[N], qsl[N], qsr[N];

void solve() {
    int n, m;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    qsl[1] = 0;
    qsl[2] = 1;
    for(int i = 3; i <= n; i++){
        qsl[i] = qsl[i-1];
        if(a[i-1] - a[i-2] > a[i] - a[i-1]) qsl[i]++;
        else qsl[i] += a[i] - a[i-1];
    }
    qsr[n] = 0;
    qsr[n-1] = 1;
    for(int i = n-2; i > 0; i--){
        qsr[i] = qsr[i+1];
        if(a[i+1] - a[i] < a[i+2] - a[i+1]) qsr[i]++;
        else qsr[i] += a[i+1] - a[i];
    }
    cin >> m;
    while(m--){
        int x, y;
        cin >> x >> y;
        if(x < y) cout << qsl[y] - qsl[x] << "\n";
        else cout << qsr[y] - qsr[x] << "\n";
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