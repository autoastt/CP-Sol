#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[104];
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cout << 2 + 2*(n%2) << "\n" << 1 << " " << n-n%2 << "\n" << 1 << " " << n-n%2 << "\n";
    if(n%2){
        cout << n-1 << " " << n << "\n" << n-1 << " " << n << "\n";
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