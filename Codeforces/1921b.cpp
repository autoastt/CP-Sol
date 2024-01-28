#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+5;

string a, b;

void solve() {
    int n, cnta = 0, cntb = 0, cntd = 0;
    cin >> n >> a >> b;
    // for(int i = 0; i < n; i++){
    //     cnta += a[i] - '0';
    // }
    for(int i = 0; i < n; i++) {
        // cntb += b[i] - '0';
        if(a[i] == '0' && b[i] == '1') cnta++;
        else if(a[i] == '1' && b[i] == '0') cntb++;
    }
    cout << max(cnta, cntb) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}