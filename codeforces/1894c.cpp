#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;
int b[N], to[N];

void solve() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        to[i] = 0;
    }
    int now = n, cnt = 0;
    while(1){
        if(to[now]) break;
        if(b[now] > n){cout << "No\n"; return;}
        int next = (now - b[now]) % n;
        if(next <= 0) next += n;
        to[now] = next;
        now = next;
        cnt++;
        if(cnt == k){cout << "Yes\n"; return;}
    }
    cout << "Yes\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}