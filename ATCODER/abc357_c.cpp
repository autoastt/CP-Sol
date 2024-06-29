#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
const bool TESTCASE = false;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

void solve() {
    int n;
    cin >> n;
    if(!n) return void(cout << '#');
    vector<string> ans = {"###", "#.#", "###"};
    int sz = 3;
    for(int i = 2; i <= n; i++) {
        vector<string> s(sz*3);
        for(int r = 0; r < sz*3; r++) {
            for(int c = 0; c < sz*3; c++) {
                if(sz <= r && r < sz*2 && sz <= c && c < sz*2) s[r] += '.';
                else s[r] += ans[r % sz][c % sz];
            }
        }
        ans = s;
        sz *= 3;
    }
    for(auto r : ans) {
        cout << r << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t(1);
    if(TESTCASE) cin >> t;
    while(t--) {
        solve();
    }
}

