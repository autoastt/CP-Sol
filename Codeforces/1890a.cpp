#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+5;

void solve() {
    int n, cnt2 = 1, y = 0, z = 0, cnt = 1;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    y = v[0];
    z = v[n-1];
    if(y==z) {cout << "Yes\n"; return;}
    for(int i = 1; i < n; i++){
        if(v[i] == y) cnt++;
        else if(v[i] == z) cnt2++;
        else{cout<<"No\n"; return;}
    }
    if(cnt == n/2 || cnt == (n+1)/2){
        cout << "Yes\n";
    } 
    else cout << "No\n";

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}