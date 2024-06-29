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

int sumx[N], sumy[N];

void solve() {
    int n, q, cnt = 1;
    cin >> n >> q;
    for(int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        if(x == 1) {
            char c;
            cin >> c;
            if(cnt) sumx[cnt] = sumx[cnt-1], sumy[cnt] = sumy[cnt-1];
            if(c == 'R') sumx[cnt]++;
            else if(c == 'L') sumx[cnt]--;
            else if(c == 'U') sumy[cnt]++;
            else sumy[cnt]--;
            cnt++;
        }
        else {
            int p;
            cin >> p;
            int px = p, py = 0;
            if(p > cnt - 1) px -= cnt - 1;
            else px = 1;
            int tmp = cnt - p;
            if(tmp > 0) px += sumx[tmp], py += sumy[tmp];
            cout << px << " " << py << "\n";
        }
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

