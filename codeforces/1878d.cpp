#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;

void solve() {
    int n,k,q;
    string s;
    cin >> n >> k >> s;
    vector<int> l(k), r(k), qs(n+5, 0);
    vector<pair<int,int>> sw[k];
    // s = " " + s;
    for(int i = 0; i < k; i++) cin >> l[i];
    for(int i = 0; i < k; i++) cin >> r[i];
    for(int i = 0; i < k; i++) l[i]--, r[i]--;
    cin >> q;
    // cout << "q = " << q << '\n';
    // cout << s << "\n";
    while(q--){
        int x;
        cin >> x;
        // cout << x << "\n";
        auto itr = --upper_bound(l.begin(), l.end(), x);
        int idx = itr - l.begin();
        // if(idx == l.end()){
        //     cout << "shit";
        //     return;
        // }
        // cout << idx << " " << l[idx] << " " << r[idx] << "\n";
        int a = min(x, l[idx] + r[idx] - x), b = max(x, l[idx] + r[idx] - x);
        // cout << a << " " << b << "\n";
        // reverse(s.begin()+a-1, s.begin()+b);
        // cout << s << "\n";
        sw[idx].push_back({a,b});
    }
    for(int i = 0; i < k; i++){
        for(int j = 0; j < sw[i].size(); j++){
            if(j%2 == 0){
                qs[sw[i][j].first]++;
            }
            else qs[sw[i][j].first]--;
        }
        for(int j = l[i]+1; j <= (l[i]+r[i])/2; j++) qs[j] += qs[j-1];
        for(int j = l[i]; j <= (l[i]+r[i])/2; j++){
            if(qs[j]%2) swap(s[j], s[r[i]-j]);
        }
    }
    
    cout << s << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}