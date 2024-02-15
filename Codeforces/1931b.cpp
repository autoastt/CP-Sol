#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;

int a[N];

void solve() {
  int n, cnt = 0, sum = 0;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    sum += a[i];
  }
  sum /= n;
  for(int i = 0; i < n; i++){
    if(a[i] < sum){
      if(cnt >= sum - a[i]){
        cnt -= sum - a[i];
        continue;
      }
      return void(cout << "NO\n");
    }
    else cnt += a[i] - sum;
  }
  cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}


