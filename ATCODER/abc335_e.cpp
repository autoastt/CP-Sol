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

int a[N], n;
vector<int> adj[N];
bool vis[N];
int dis[N];

struct A{
    int u, d;
    bool operator <(const A&o)const{
        if(a[u] == a[o.u]) return d < o.d;
        return a[u] > a[o.u];
    }
};

void solve() {
    int m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    priority_queue<A> q;
    q.push({1, dis[1] = 1});
    while(!q.empty()){
        auto [u, d] = q.top();
        q.pop();
        if(dis[u] != d) continue;
        for(auto v : adj[u]){
            if(a[u] <= a[v] && dis[v] < d + (a[v] != a[u]))
                q.push({v, dis[v] = d + (a[v] != a[u])});
        }
    }
    cout << dis[n];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t(1);
    if(TESTCASE) cin >> t;
    while(t--) {
        solve();
    }
}

