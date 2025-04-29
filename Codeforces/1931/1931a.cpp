#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  string ans = "";
  for(int i = 1; i < 3; i++){
    for(int j = 1; j <= 26; j++){
      if(n - j <= 26*(3-i)){
        n -= j;
        ans += 'a' + j - 1;
        break;
      }
    }
  }
  ans += 'a' + n - 1;
  cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
