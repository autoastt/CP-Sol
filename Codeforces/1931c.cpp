#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;

int a[N];

void solve() {
  int n, mx = 0; 
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  int cntl = 0, cntr = 0, l = a[0], r = a[n-1];
  for(int i = 0; i < n; i++){
    if(a[i] == l) cntl++;
    else break;
  }
  for(int i = n-1; i >= 0; i--){
    if(a[i] == r) cntr++;
    else break;
  }
  int ans;
  if(l == r) ans = min(n, cntl + cntr);
  else ans = max(cntl, cntr);
  cout << n-ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
