#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    string s;
    cin >> s;
    int sz = 0, usz = 1e9, ssz = 0, sorted = 1;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '+'){
            sz++;
            if(sz == 1) sorted = 1, ssz = 1;
            else if(sz > 1 && sorted == 1) sorted = 0;
        }
        else if(s[i] == '-'){
            sz--;
            if(sz <= 1) sorted = 1, usz = 1e9, ssz = 1;
            else if(sz <= ssz) sorted = 1, ssz = sz;
            else if(sz < usz && usz != 1e9) sorted = 0, usz = 1e9;
        }
        else if(s[i] == '1'){
            if(sorted == -1) {
                cout << "NO\n";
                return;
            }
            sorted = 1;
            ssz = sz;
        }
        else{
            if(sorted == 1) {
                cout << "NO\n";
                return;
            }
            sorted = -1; 
            usz = min(usz, sz);
        }
        // cout << sz << " " << ssz << " " << usz << " " << sorted << "\n";
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}