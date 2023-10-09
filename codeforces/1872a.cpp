#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int a,b,c;
    cin>>a >>b>>c;
    if(a == b){
        cout << "0\n";
        return;
    }
    int x = (a + b)/2;
    x = max(a,b) - x;
    cout << x/c + (x%c ? 1 : 0) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}