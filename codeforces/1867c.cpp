#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;
const int N = 1e5 + 5;
int a[N];

void solve() {
    int n, pre, mn = 0, y = 0, cnt = 0;
    bool zero = false;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    pre = a[0];
    if(pre != 0){
        cout << "0\n";
        cout.flush();
        cin >> y;
        return;
    }
    for(int i = 1; i < n; i++){
        if(a[i] - a[i-1] != 1){
            break;
        }
        mn = a[i];
    }
    cout << mn+1 << "\n";
    cout.flush();
    while(cnt < 2*n+1){
        cin >> y;
        if(y == -1) break;
        cout << y << "\n";
        cout.flush();
        cnt++;
    }
    if(cnt == 2*n+1) cin >> y;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}