#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+5;
vector<pair<ll,ll>> adj[N];
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
ll d[N], state;

void dijk(){
    while(!pq.empty()){
        auto [dis,u] = pq.top();
        pq.pop();
        if(dis != d[u]) continue;
        for(auto [v,w] : adj[u]){
            if(d[v] > d[u] + w){
                pq.push({d[v] = d[u] + w, v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    fill_n(d, N, 1e15);
    ll n,k,s,q;
    cin >> n >> k >> s >> q;
    for(int i = 1; i < n; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    d[s] = 0;
    pq.push({0,s});
    dijk();
    while(q--){
        ll x,y;
        cin >> x >> y;
        if(!x){
            d[y] = 0;
            pq.push({0,y});
            dijk();
        }
        else{
            cout << d[y] << "\n";
        }
    }
}