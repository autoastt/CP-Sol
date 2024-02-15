#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;
pair<int, int> a[N];

void solve() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
    }
    for(int i = 0; i < n; i++) cin >> a[i].second;
    sort(a, a+n);
    for(int i = 1; i <= n; i++) cout << i << " \n"[i == n];
    for(int i = 0; i < n; i++) cout << a[i].second << " ";
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
