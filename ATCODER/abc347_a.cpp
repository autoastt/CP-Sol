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
const int INF = 1e9;
const ll LLINF = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x % k == 0) v.pb(x / k);
    }
    sort(all(v));
    for(auto i : v) cout << i << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t(1);
    if(TESTCASE) cin >> t;
    while(t--) {
        solve();
    }
}

