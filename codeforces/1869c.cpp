#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, m;
    cin >> n >> m;
    if(m == 1){
        cout << 0 << "\n";
        for(int i = 0; i < n; i++) cout << 0 << "\n";
        return;
    }
    if(n < m){
        cout << n+1 << "\n";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int k = m-i-j-1;
                cout << (k < 0 ? k + m : k) << " ";
            }
            cout << "\n";
        }
    }
    else{
        cout << m << "\n";
        for(int i = 0; i < m-1; i++){
            for(int j = 0; j < m; j++){
                int k = m-i-j-1;
                cout << (k < 0 ? k + m : k) << " ";
            }
            cout << "\n";
        }
        for(int i = m-1; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << m-j-1 << " ";
            }
            cout << "\n";
        }
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