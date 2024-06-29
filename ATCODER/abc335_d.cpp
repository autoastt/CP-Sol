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

int a[50][50];

void solve() {
    int n;
    cin >> n;
    int i = 1, j = 1, d = 1;
    for(int k = 1; k < n * n; k++) {
        a[i][j] = k;

        if(d == 1 && (j == n || a[i][j+1])) d = 2;
        else if(d == 2 && (i == n || a[i+1][j])) d = 3;
        else if(d == 3 && (j == 1 || a[i][j-1])) d = 4;
        else if(d == 4 && (i == 1 || a[i-1][j])) d = 1;

        if(d == 1) j++;
        else if(d == 2) i++;
        else if(d == 3) j--;
        else i--;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(a[i][j] == 0) {
                cout << "T ";
                continue;
            }
            cout << a[i][j] << " ";
        }
        cout << "\n";
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

