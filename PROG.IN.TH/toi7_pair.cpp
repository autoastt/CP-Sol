#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+5;

vector<pair<ll,ll>> v;
ll fw[N], fw_cnt[N], ans, arr[N];

void update(int idx, ll x){
    for(int i = idx; i < N; i += (i & -i)){
        fw[i] += x;
        fw_cnt[i]++;
    }
}

ll query(int idx, ll x){
    ll cnt = 0, sum = 0;
    for(int i = idx; i > 0; i -= (i & -i)){
        cnt += fw_cnt[i];
        sum += fw[i];
    }
    return cnt * x + sum;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        arr[b] = a;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end(), greater<pair<ll,ll>>());
    for(auto [a, b] : v){
        update(b, a);
        ans += query(b-1, a);
        
    }
    cout << ans;
}