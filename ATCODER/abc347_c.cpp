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
    int n, a, b;
    cin >> n >> a >> b;
    set<int> s;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int d;
        cin >> d;
        d %= a + b;
        s.insert(d);
    }
    for(auto i : s) v.pb(i);
    for(int i = 1; i < v.size(); i++){
        if(v[i] - v[i-1] > b) return void(cout << "Yes");
    }
    if(v[0] + a + b - v[v.size()-1] > b) return void(cout << "Yes");
    cout << "No";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t(1);
    if(TESTCASE) cin >> t;
    while(t--) {
        solve();
    }
}

