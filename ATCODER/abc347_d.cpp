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
    ll a, b, c, x = 0, y = 0;
    cin >> a >> b >> c;
    ll k = __builtin_popcountll(c);
    if(a + b < k) return void(cout << -1);
    if((a + b - k) % 2) return void(cout << -1);
    if(a + b + k > 120) return void(cout << -1);
    ll uk = (a + b - k) / 2;
    a -= uk;
    b -= uk;
    if(a < 0 || b < 0) return void(cout << -1);
    for(int i = 0; i < 60; i++) {
        if(c & (1ll << i)) {
            if(a){
                x += 1ll << i;
                a--;
            }
            else if(b){
                y += 1ll << i;
                b--;
            }
            else return void(cout << -1);
        }
        else if(uk){
            x += 1ll << i;
            y += 1ll << i;
            uk--;
        }
    }
    cout << x << " " << y;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t(1);
    if(TESTCASE) cin >> t;
    while(t--) {
        solve();
    }
}
