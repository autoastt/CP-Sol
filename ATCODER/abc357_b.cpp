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
    string s;
    cin >> s;
    int up = 0, low = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] <= 'Z' && s[i] >= 'A') up++;
        else low++;
    }
    for(int i = 0; i < s.size(); i++) {
        if(s[i] <= 'Z' && s[i] >= 'A' && low > up) s[i] = s[i] - 'A' + 'a';
        else if(s[i] <= 'z' && s[i] > 'a' && up > low) s[i] = s[i] - 'a' + 'A';
    }
    cout << s;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t(1);
    if(TESTCASE) cin >> t;
    while(t--) {
        solve();
    }
}

