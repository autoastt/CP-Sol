#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3+4;

void solve() {
    int n, s, e, shit = 0;
    cin >> n >> s >> e;
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        if(shit) continue;
        if(x >= s && y >= e){
            cout << "-1\n";
            shit = true;
        }
    }
    if(!shit) cout << s << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}