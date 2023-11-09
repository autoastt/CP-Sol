#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3+5;
int cnt[N], a[N];

void solve() {
    int n, re = 0, now = 3, ok = 0; 
    cin >> n;
    vector<int> v;
    fill_n(cnt, N, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(++cnt[a[i]] == 2){re++; v.push_back(i);}
    }
    if(re < 2){cout << "-1\n"; return;}
    for(int i = 0, j = 0; i < n; i++){
        if(v[j] == i && now > 1){
            cout << now-- << " ";
            j++;
        }
        else cout << 1 << " ";
    }
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