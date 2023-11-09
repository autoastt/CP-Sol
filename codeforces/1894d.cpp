#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;
int a[N], b[N];

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    sort(b, b+m);
    reverse(b, b+m);
    int i = 0, j = 0;
    while(i < n && j < m){
        if(b[j] >= a[i]) cout << b[j++] << " ";
        else cout << a[i++] << " ";
    }
    while(i < n) cout << a[i++] << " ";
    while(j < m) cout << b[j++] << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}