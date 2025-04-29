#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;
int a[N];

void solve() {
  int n, ans = 0, b = 1e9, c = 1e9;
  cin >> n;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    if(x <= b) b = x;
    else if (x <= c) {
      c = x;
    }
    else {
      b = x;
      ans++;
    }
    if(b > c) swap(b, c);
  }
  cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
