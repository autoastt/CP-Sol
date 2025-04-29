#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
#define mp make_pair
#define pb push_back
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
const bool TESTCASE = true;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

void solve() {
    string s;
    cin >> s;
    bool found = false;
    int n = sz(s);
    for(int i = n - 1; i > 0; i--) {
        int x = s[i] - '0', y = s[i-1] - '0';
        if(x + y > 9) {
            string k = to_string(x + y);
            s[i] = k[1];
            s[i-1] = k[0];
            found = true;
            break;
        }
    }
    if(!found) {
        int x = s[0] - '0', y = s[1] - '0';
        s = to_string(x + y) + s.substr(2, n-2);
    }
    cout << s << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t(1);
    if(TESTCASE) cin >> t;
    while(t--) {
        solve();
    }
}

