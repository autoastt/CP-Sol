#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int j = -1, cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'B'){
            if(j == -1) j = i;
            else{
                if(i-j+1 > k) j=i,cnt++;
            }
        }
    }
    if(j != -1) cnt++;
    cout << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}