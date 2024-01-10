#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;

double cal(ll x){
    double ret = 0.125*((x*(3*pow(x,2)+5))/(pow(x,4)+2*pow(x,2)+1)+3*atan(x));
    return ret;
}

void solve() {
    ll l, r;
    cin >> l >> r;
    // cout << cal(r) << " " << cal(l) << "\n";
    cout << fixed << setprecision(12) << cal(r)-cal(l) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}