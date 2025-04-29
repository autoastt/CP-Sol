#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 3e5+5;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n+2, 0), b(n+2, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    set<int> s, d;
    for(int i = 0; i < n+2; i++){
        s.insert(i);
        if(i > 0 && i < n+1) d.insert(i);
    }
    for(int i = 0; i < n; i++){
        set<int> cur;
        vector<int> e;
        for(auto j : d){
            auto itr = s.find(j);
            if(itr == s.end()) continue;
            int pre = *prev(itr), nxt = *next(itr);
            if(a[pre] + a[nxt] > b[j]){
                e.push_back(j);
                if(pre > 0) cur.insert(pre);
                if(nxt < n+1) cur.insert(nxt);
            }
        }
        d = cur;
        for(auto j : e) s.erase(j);
        cout << e.size() << " ";
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