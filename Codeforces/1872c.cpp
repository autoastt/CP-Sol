#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int l, r;
    cin >> l >> r;
    int k = r/2;
    if(k < 2){
        cout << "-1\n";
        return;
    }
    if(k%2 && 2*k >= l){
        cout << k-1 << " " << k+1 << "\n";
        return;
    }
    else if(k%2 == 0 && 2*k >= l){
        cout << k << " " << k << "\n";
        return;
    }
    else{
        for(int i = 2; i <= sqrt(r); i++){
            if(r%i == 0){
                cout << i << " " << r-i << "\n";
                return;
            }
        }
    }
    cout << -1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    // cout << gcd(6274,9834495);
}