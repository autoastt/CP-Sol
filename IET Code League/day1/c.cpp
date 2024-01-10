#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;
string x = "ietntu";

void solve() {
    string s;
    cin >> s;
    int j = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == x[j]) j++;
        if(j == 6) return void(cout << "YES\n");
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}