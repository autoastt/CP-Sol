#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, m;
    string s, ss;
    cin >> n >> m >> s >> ss;
    bool shit = 0;
    for(int i = 1; i < n; i++){
        if(s[i] == s[i-1]){ shit = 1; break;}
    }
    if(!shit){cout << "Yes\n"; return;}
    for(int i = 1; i < m; i++){
        if(ss[i] == ss[i-1]){
            cout<<"No\n";
            return;
        }
    }
    for(int i = 1; i < n; i++){
        if(s[i] == s[i-1]){
            if(ss[0] == s[i-1] || ss[m-1] == s[i]){
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}