#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, k;
    cin >> n >> k;
    int can[10] = {};
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        can[x%k]++;
    }
    if(can[0]) {cout << "0\n"; return;}
    if(k == 2) cout << "1\n";
    else if(k == 3){
        if(can[2]) cout << "1\n";
        else if(can[1]) cout << "2\n";
    }
    else if(k == 4){
        if(can[2] >= 2) cout << "0\n";
        else if(can[2] > 0 && (can[3] || can[1])) cout << "1\n";
        else if(can[2] == 0 && can[3]) cout << "1\n";
        else if(can[2] == 0 && can[1] >= 2) cout << "2\n";
        else cout << "3\n";
    }
    else if(k == 5){
        if(can[4]) cout << "1\n";
        else if(can[3]) cout << "2\n";
        else if(can[2]) cout << "3\n";
        else if(can[1]) cout << "4\n";
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