#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+5;
int a[N], b[N];

void solve() {
    int n, m, k = 0;
    cin >> n >> m;
    a[1] = 1;
    for(int i = 2; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    sort(a+1, a+1+n); sort(b+1, b+1+n);
    for(int i = 1, j = 1; i <= n-k;){
        if(a[i] >= b[j]) k++, j++;
        else i++, j++;
    }
    cout << k << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}