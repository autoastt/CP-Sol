#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    string s;
    bool seven = false;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '3' && seven){
            cout << "73\n";
            return;
        }
        else if(s[i] == '3' && !seven) {
            cout << "37\n";
            return;
        }
        if(s[i] == '7') seven = 1;
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