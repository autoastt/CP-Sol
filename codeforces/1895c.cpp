#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;
string a[N];
ll sum[N];

int main(){
    unordered_map<ll, ll> mp[6];
    ll n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        ll m = a[i].size();
        for(int j = 0; j < m; j++){
            sum[i] += a[i][j] - '0';
        }
        mp[m][sum[i]]++;
    }
    for(int i = 0; i < n; i++){
        ll now = sum[i], m = a[i].size(), d = 0;
        ans += mp[m][now];
        for(int j = m-1, k = 1; j > (m/2); j--, k++){
            now -= a[i][j] - '0';
            d += a[i][j] - '0';
            ans += mp[j-k][now-d];
        }
        now = sum[i], d = 0;
        for(int j = 0, k = 1; j < (m-1)/2; j++, k++){
            now -= a[i][j] - '0';
            d += a[i][j] - '0';
            ans += mp[m-j-1-k][now-d];
        }
    }
    cout << ans;
}