#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
const bool TESTCASE = false;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

ll a[15], s[N], l[15], t[15], cnt[15];

void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    for(int i = 1; i <= n; i++) cin >> l[i];
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++){
        cin >> s[i];
        s[i] += s[i-1];
    }
    sort(l, l+n+1);
    sort(a, a+n+1);
    for(int i = 1; i <= n; i++) l[i] -= a[i];
    for(int i = 1; i <= x; i++) cin >> t[i];
    while(x--){
        int pre = 1, now;
        for(int i = 1; i <= n; i++){
            cin >> now;
            cnt[i] = s[now] - s[pre-1];
            now = pre;
        }
        sort(cnt, cnt+n+1);
        for(int i = 1; i <= n; i++){
            
        }
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

