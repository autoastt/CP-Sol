#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;

int fw[N];

void update(int idx, int x){
    for(; idx < N; idx += idx & -idx) fw[idx] += x;
}

int sum(int idx){
    int ret = 0;
    for(; idx > 0; idx -= idx & -idx) ret += fw[idx];
    return ret;
}

struct A{
    int s, h, o;
    bool operator <(const A&o)const{
        return s < o.s;
    }
};
vector<A> v;

int bs(int x){
    int l = 1, r = N, mid;
    while(l < r){
        mid = (l + r)/2;
        if(sum(mid) <= x) r = mid;
        else l = mid + 1;
    }
    return r;
}

int main(){
    int n, t, ans = 0;
    cin >> n >> t;
    for(int i = 0; i < n; i++){
        int s, h, w, o;
        cin >> s >> h >> w >> o;
        v.push_back({s, h, o});
        v.push_back({s + w, h, -o});
    }
    sort(v.begin(), v.end());
    int pre = 0;
    for(auto [now, h, o] : v){
        int upper = bs(t-1), lower = bs(t);
        if(sum(lower) == t) ans += (now - pre) * (upper - lower);
        update(1, o);
        update(1 + h, -o);
        pre = now;
    }
    cout << ans;
}