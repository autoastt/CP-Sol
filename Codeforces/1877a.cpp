#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 105;
int a[N];

void solve() {
    int n, sum = 0;
    cin >> n;
    for(int i = 1; i < n; i++){
        int x;
        cin >> x;
        sum += x;
    }
    cout << -sum << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}