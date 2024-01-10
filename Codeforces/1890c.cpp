#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, k = 0, j = 0;
    string s, ss;
    cin >> n >> s;
    if(n%2){
        cout << "-1\n";
        return;
    }
    vector<int> v;
    while(s.size()){
        if(s[0] != s[s.size()-1]) s = s.substr(1, s.size()-2), j++, k--;
        else{
            if(s[0] == '1'){
                v.push_back(0+j);
                ss = "01"+s;
                j++;
                // k++;
            }
            else{
                v.push_back(n+k);
                ss = s+"01";
                k++;
                // j++;
            }
            ss = ss.substr(1, ss.size()-2);
            // cout << ss << "\n";
            if(s == ss){
                cout << "-1\n";
                return;
            }
            s = ss;
        }
    }
    if(v.size() > 300){
        cout << "-1\n";
        return;
    }
    cout << v.size() << "\n";
    for(auto i : v) cout << i << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}