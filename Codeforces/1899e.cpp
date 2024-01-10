#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;
int a[N];

void solve() {
    int n, mn = INT_MAX, cnt = 0, idx = -1;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] < mn) mn = a[i], idx = i;
        if(a[i] < a[i-1]) cnt = i;
    }
    cout << (cnt == idx ? idx-1 : -1) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    a[0] = INT_MAX;
    while(t--) {
        solve();
    }
}