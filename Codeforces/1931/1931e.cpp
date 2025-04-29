#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, m, cnt = 0;
  cin >> n >> m;
  vector<int> v;
  for(int i = 0; i < n; i++){
    string s; cin >> s;
    cnt += s.size();
    int cntt = 0;
    for(int j = s.size()-1; j >= 0; j--){
      if(s[j] == '0') cntt++;
      else break;
    }
    v.push_back(cntt);
  }
  sort(v.begin(), v.end(), greater<int>());
  for(int i = 0; i < v.size(); i += 2) cnt -= v[i];
  /* cout << "cnt = " << cnt << "\n"; */
  cout << (cnt > m ? "Sasha" : "Anna") << "\n"; 
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
