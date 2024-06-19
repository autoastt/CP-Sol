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

vector<int> pos[N];
ll sum[N];

void solve() {
    int n, q;
    cin >> n >> q;
    set<int> s;
    for (int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        if(s.count(x)) s.erase(x);
        else s.insert(x);
        pos[x].pb(i);
        sum[i] = sum[i-1] + s.size();
    }
    for (int i = 1; i <= n; i++) {
        ll a = 0;
        pos[i].pb(q+1);
        for (int j = 1; j < pos[i].size(); j += 2) {
            a += sum[pos[i][j]-1] - sum[pos[i][j-1]-1];
        }
        cout << a << " ";
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

